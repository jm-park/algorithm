/**
 * [ 이분탐색 ]
 * 문제: 1300 K번째 수
 *
 * https://www.acmicpc.net/problem/1300
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

long long N, K;

long long findMid() {

    long long start = 1, end = K, answer;

    while(end >= start) {
        long long mid = (start+end)/2;
        long long cnt = 0;

        // 각 행별로 숫자 X 이하인 수의 갯수를 센다.
        for(int i = 1; i <= N; i++) {
            cnt += mid/i >= N ? N : mid/i;
        }

        // 갯수가 더 크다는 것은, 숫자를 줄여야 한다는 것
        if(cnt >= K) {
            end = mid-1;
            answer = mid;
        }
        // 갯수가 작다는 것은, 숫자를 키워야 한다는 것
        else if(cnt < K) start = mid+1;
    }

    return answer;
}

int main() {

    // N: 10^5보다 작거나 같은 자연수, k: min(10^9, N^2)보다 작거나 같은 자연수
    cin >> N >> K;

    // K번째 수
    cout << findMid() << endl;
    return 0;
}