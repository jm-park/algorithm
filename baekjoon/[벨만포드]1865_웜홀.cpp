/**
 * [ 벨만–포드 ]
 * 문제: 1865 웜홀
 *
 * https://www.acmicpc.net/problem/1865
 *
 * cf) 설명 참고: https://yabmoons.tistory.com/365
 * 소스 참고: https://yangorithm.tistory.com/135
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M, W;

string bellman_ford(vector<pair<int,int>> road[505]) {

    // 기본값: 음수 사이클이 생성되지 않는 가정
    string answer = "NO\n";

    // 각 정점까지의 cost 최대값(무한대값)으로 초기화
    int dist[505];
    fill_n(dist, N+1, INT8_MAX);
    dist[1] = 0;

    /**
     * 최상위 for문이 추가된 이유.
     *
     * 원래, bellmanFord에서 시작점이 주어지지만,
     * 현재 문제에서 어느 시작점이든 상관없이 음수 사이클이 존재하면 바로 정답이 되기 때문임.
     *
     * 따라서, i는 각 간선의 시작 포인트를 나타냄.
     */
    for(int i = 1; i <= N; i++) {

        for(int j = 1; j <= N; j++) {

            // Vertex J에서 갈 수 있는 모든 정점을 돈다.
            for(pair<int,int> edge : road[j]) {
                int next = edge.second, cost = edge.first;

                // 방문 정점의 비용이 더 줄어들면 update
                if(dist[next] > dist[j]+cost) {
                    dist[next] = dist[j]+cost;
                }
            }
        }
    }


    /**
     * 음수 사이클 확인
     */
    for(int j = 1; j <= N; j++) {

        // 어차피 갈 수 없는 정점은 PASS
        if(dist[j] == INT8_MAX) continue;

        // Vertex J에서 갈 수 있는 모든 정점을 돈다.
        for(pair<int,int> edge : road[j]) {
            int next = edge.second, cost = edge.first;

            /**
             * 이미 다 최소비용을 update했음에도 불구하고 더 줄어드는 것은
             * => 사이클이 존재하기 때문에!! (무한으로 돌게됨)
             */
            if(dist[next] != INT8_MAX && dist[next] > dist[j]+cost) {
                answer = "YES\n";
                return answer;
            }
        }
    }

    return answer;
}

int main() {

    int TC;
    cin >> TC;

    while(TC--) {

        vector<pair<int,int>> road[505];

        // 지점의 수 N(1 ≤ N ≤ 500), 도로의 개수 M(1 ≤ M ≤ 2500), 웜홀의 개수 W(1 ≤ W ≤ 200)
        cin >> N >> M >> W;

        int S, E, T;

        // S, E => 연결된 지점의 번호, T: 도로 이동 시간
        for(int i = 0; i < M; i++) {
            cin >> S >> E >> T;
            // first: 비용, second: 도착지
            road[S].push_back({T, E});
            road[E].push_back({T, S});
        }

        // S는 시작 지점, E는 도착 지점, T는 줄어드는 시간
        for(int i = 0; i < W; i++) {
            cin >> S >> E >> T;
            // 0: 비용, 2: 도착지
            road[S].push_back({-T, E});
        }

        // 벨만–포드 알고리즘 수행
        cout << bellman_ford(road);

    }

    return 0;
}