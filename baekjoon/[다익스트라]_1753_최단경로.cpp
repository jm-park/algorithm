/**
 * [ 다익스트라 ]
 * 문제: 1753 최단경로
 *
 * https://www.acmicpc.net/problem/1753
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 2000000000

using namespace std;

int V, E, dept;

vector<pair<int,int>> vertex[20002];    // index: 출발지점, vector => first: 비용, second: 도착지점
int minCost[20002];

void dijkstra() {

    // first 값 기준으로 minHeap 출력 => first: 비용, second: 도착지점
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({minCost[dept], dept});

    while(!pq.empty()) {
        int now = pq.top().second, nowCost = pq.top().first; // 다음 도착지점
        pq.pop();

        /**
         * 현재 cost가격이, 현 node의 방문 최소값보다 큰 경우 그냥 PASS!!!
         *
         * 왜냐, 아래 로직에서 다른길로 탐방했을때 최소값이 나왔을 수 있기 때문
         */
        if(nowCost > minCost[now]) continue;

        // now에서 갈 수 있는 지점
        for(pair<int,int> pos : vertex[now]) {
            int next = pos.second, cost = pos.first;
            if(minCost[next] > cost + minCost[now]) {
                minCost[next] = cost + minCost[now];
                pq.push({minCost[next], next});
            }
        }
    }

}

int main() {

    // 정점의 개수 V와 간선의 개수 E  (1≤V≤20,000, 1≤E≤300,000)
    // 시작 정점의 번호
    cin >> V >> E >> dept;

    for(int i = 0; i < E; i++) {
        int u, v, w;
        // u에서 v로 가는 가중치 w인 간선
        cin >> u >> v >> w;
        vertex[u].push_back({w, v}); // first: 비용, second: 도착지점
    }

    /**
     * 노드 방문 최소값 초기화
     *
     * fill_n(배열명, 갯수, 초기화값)
     */
    fill_n(minCost, V+1, INF);
    minCost[dept] = 0; // 출발지는 0으로 초기화

    /**
     * [다익스트라를 이용한 최단경로 탐색]
     * 중요 포인트: 한번만 탐색해도 되는 이유
     *
     * dijkstra 알고리즘은 결론적으로 모든 노트에 대해 전체탐색이다.
     * 따라서, 도착점을 지정하지 않아도 시작점만 지정한다면,
     * 시작점 Ai에서 Aj까지 가는 각 노드들에 대한 최소 가중치 경로를 알 수 있다..
     * 
     */
    dijkstra();

    for(int node = 1; node <= V; node++) {

        if(minCost[node] == INF) {
            printf("INF\n");
        } else {
            printf("%d\n", minCost[node]);
        }
    }


    return 0;
}