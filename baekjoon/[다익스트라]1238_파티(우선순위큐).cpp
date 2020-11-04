/**
 * [ 다익스트라 ]
 * 문제: 1238 파티
 *
 * https://www.acmicpc.net/problem/1238
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, X, answer;
vector<pair<int,int>> map[1001]; // 경로: Index 에서 갈 수 있는 모든 경로 first: 비용, second: 도착지점
int minCost[1001]; // 최소경로 비용


int dijkstra(int dept, int dest) {

    // 비용 적은 순으로 우선순위 됨
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // 최소경로 목록 first: 비용, second: 도착지점

    minCost[dept] = 0; // 시작점의 cost는 0으로 지정
    pq.push({minCost[dept], dept});

    while(!pq.empty()) {
        int now = pq.top().second;
        pq.pop();

        // 현재(now)에서 갈 수 있는 도로 중, 최소 값 탐색
        for(pair<int,int> next : map[now]) {
            int nextPath = next.second, nextCost = next.first;

            if(minCost[nextPath] > nextCost+minCost[now]) {
                // 최소값 변경
                minCost[nextPath] = nextCost+minCost[now];
                pq.push({nextCost+minCost[now], nextPath});
            }
        }
    }

    return minCost[dest];
}

int main() {

    // 학생수: N(1 ≤ N ≤ 1,000), 도로수: M(1 ≤ M ≤ 10,000), X
    cin >> N >> M >> X;

    // 도로의 시작점, 끝점, 소요시간
    for(int i = 0; i < M; i++) {
        int s, e, t;
        cin >> s >> e >> t;
        map[s].push_back({t,e}); // first: 비용, second: 도착지점
    }

    // 각 학생의 최소시간 중, 가장 오래 걸리는 학생의 소요시간
    for(int i = 1; i <= N; i++) {

        int result = 0;
        // 배열 초기화
        for(int j = 0; j <= N; j++) {
            minCost[j] = 2000000000;
        }
        // 다익스트라: N->X 가는 최소 경로 (집에서 X로 가는 최소경로)
        result += dijkstra(i, X);

        // 배열 초기화
        for(int j = 0; j <= N; j++) {
            minCost[j] = 2000000000;
        }
        // 다익스트라: X->N 가는 최소 경로 (X에서 집으로 돌아오는 최소경로)
        result += dijkstra(X, i);

        answer = max(result, answer);
    }
    cout << answer << endl;

    return 0;
}