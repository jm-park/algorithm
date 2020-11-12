/**
 * [ KMP ]
 * 문제: 1786 찾기
 *
 * https://www.acmicpc.net/problem/1786
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

string T, P;
vector<int> answerIdx;
int table[1000005];

void findPattern() {
    /**
     * Prefix, PostFix 공통부분 찾는 것.
     */
    int j = 0, pLth = P.size();
    for(int i = 1; i < pLth; i++) {
        while( j > 0 && P[i] != P[j]) {
            // 이전 Index의 같은 개수 저장
            j = table[j-1];
        }
        // 같은 경우, 하나 더 증가된 값을 저장시켜줌
        if(P[i] == P[j]) {
            table[i] = ++j;
        }
    }

}

void kmp() {
    int tLth = T.size(), pIdx = 0, pLth = P.size();

    for(int t = 0; t < tLth; t++) {

        // 시작은 같지만, 끝이 같지 않아지는 지점 발견
        while(pIdx > 0 && T[t] != P[pIdx]) {
            pIdx = table[pIdx-1]; // 동일한 글자수 개수 저장
        }

        // 같인지 비교
        if(T[t] == P[pIdx]) {

            if(pIdx == pLth-1) {
                // 마지막에 도달한 경우
                answerIdx.push_back(t-(pLth-1)+1);
                pIdx = table[pIdx];
            } else {
                pIdx++;
            }
        }

    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    /**
     * 한줄을 입력받는 방법
     */
    getline(cin, T);
    getline(cin, P);

    // P의 부분 string 찾기
    findPattern();
    kmp();
    // T 중간에 P가 몇 번 나타나는지
    cout << answerIdx.size() << "\n";

    // P가 나타나는 위치를 차례대로 공백으로 구분해 출력
    for(int ans : answerIdx) {
        cout << ans << " ";
    }
    cout << "\n";

    return 0;
}