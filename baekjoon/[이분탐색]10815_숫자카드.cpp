/**
 * [ 이분 탐색 ]
 * 문제: 10815 숫자카드
 *
 * https://www.acmicpc.net/problem/10815
 *
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
vector<int> cards, targets;

int bst(int num) {
    int maxIdx = cards.size()-1, minIdx = 0, idx = cards.size()/2;

    while(1) {
        if(cards[idx] == num) {
            return 1;
        }
        else if(maxIdx == minIdx && cards[idx] != num) {
            return 0;
        }

        if(cards[idx] > num) {  // 값이 더 큰 경우: 현재보다 작은 인덱스를 탐색해야함 (왼쪽)
            maxIdx = idx;
            idx = (minIdx+idx)/2;
        }
        else {  // 값이 더 작은 경우: 현재보다 큰 인덱스쪽을 탐색해야함(오른쪽)
            minIdx = idx;
            if((maxIdx+idx)/2 == idx) { // 나눠도 같은 값인 경우
                idx = (maxIdx+idx)/2 + 1;
                minIdx = idx;
            } else {
                idx = (maxIdx+idx)/2;
            }
        }
    }
}

int main() {

    // 상근이 가지고 있는 카드
    cin >> N;
    for(int i = 0; i < N; i++) {
        int n;
        cin >> n;
        cards.push_back(n);
    }


    // 비교대상 카드
    cin >> M;
    for(int i = 0; i < M; i++) {
        int n;
        cin >> n;
        targets.push_back(n);
    }

    // 상근 카드 오름차순 정렬
    sort(cards.begin(), cards.end());

    // 가지고 있으면 1을, 아니면 0을 공백으로 구분해 출력
    for(int i = 0; i < M; i++) {
        cout << bst(targets[i]) << " ";
    }

    return 0;
}