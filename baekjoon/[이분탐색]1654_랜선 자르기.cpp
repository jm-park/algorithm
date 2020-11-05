/**
 * [  ]
 * 문제: 1654 랜선자르기
 *
 * https://www.acmicpc.net/problem/1654
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int K, N;
long long answer;
vector<long long> lan;

int checkSize(long long size) {

    int cnt = 0;
    for(long long lth : lan) {
        cnt += lth / size;
    }

    return cnt;
}

void bst() {

    long long maxVal = lan.back(), minVal = 0, midVal;

    while(maxVal >= minVal) {
        midVal = (maxVal+minVal)/2;
        if(midVal == 0) midVal = 1;

        int cnt = checkSize(midVal);

        if(cnt < N) { // 부족한 경우: 랜선길이를 줄인다.
            maxVal = midVal-1;
        }
        else if(cnt >= N) { // 넘치는 경우: 랜선길이를 늘린다.

            // 랜선 N개 이상 만들경우: max길이를 anwer에 넣어줌
            answer = max(midVal, answer);

            minVal = midVal+1;

        }
    }
}

int main() {

    // 랜선의 개수 K, 필요한 랜선의 개수 N (K ≦ N)
    cin >> K >> N;
    for(int i = 0; i < K; i++) {
        long long lth;
        cin >> lth;
        lan.push_back(lth);
    }

    // 오름차순 정렬
    sort(lan.begin(), lan.end());

    bst();

    cout << answer << endl;

    return 0;
}