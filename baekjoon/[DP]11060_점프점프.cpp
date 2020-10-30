/**
 * [ DP ]
 * 문제: 11060 점프점프
 *
 * https://www.acmicpc.net/problem/11060
 *
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, map[1005], answer[1005];
vector<int> idxList[1005]; // 각 인덱스마다 접근할 수 있는 index 목록

void findIdxList() {
    for(int i = 0; i < N; i++) {
        for(int idx = 1; idx <= map[i] && i+idx < N; idx++) {
            idxList[i+idx].push_back(i);
        }
    }
}

void dp() {
    for(int i = 1; i < N; i++) {
        int maxSize = idxList[i].size();
        for(int idx = 0; idx < maxSize; idx++) {
            answer[i] = min(answer[i], answer[idxList[i][idx]]+1);
        }
    }
}

int main() {

    // (1 ≤ N ≤ 1,000)
    cin >> N;
    for(int i = 0; i < N; i++) {
        // (0 ≤ Ai ≤ 100)
        cin >> map[i];
        answer[i] = 987654321;
    }
    answer[0] = 0;

    // 접근가능한 index 목록화
    findIdxList();

    // 최소값 탐색
    dp();

    // 접근할 수 없는 경우
    if(answer[N-1] == 987654321) answer[N-1] = -1;

    // 최소 몇 번 점프 => 오른쪽 끝 칸
    cout << answer[N-1] << endl;

    return 0;
}