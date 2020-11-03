/**
 * [ 다익스트라 ]
 * 문제: 1916 최소비용구하기
 *
 * https://www.acmicpc.net/problem/1916
 *
 * cf) 다익스트라 설명 (with 우선순위큐)
 * https://dongdd.tistory.com/42
 *
 * 간단설명
 * 1. 노드 하나 선택
 * 2. 선택한 노드에서 인접한 노드를 제외한 나머지 노드들의 COST 는 무한대로 만듬
 * 3. 가장 작은 COST 선택
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

int N, M, dept, dest;
vector<pair<int,int>> bus[50005];
int minCost[50005]; // index에 갈 수 있는 최소비용

void findMinRoot() {

    // 우선순위 큐
    // first: 비용, second: 도착지역
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    minCost[dept] = 0;
    pq.push({0, dept}); // 시작 위치 넣어둠

    while(!pq.empty()) {

        int nowCity = pq.top().second , cost = pq.top().first;
//        cout << "선택 : " << nowCity << " / 비용: " << cost << endl;

        pq.pop(); // 제거

        // 만약 현재 최소비용보다 큰 경우는 PASS
        if(cost > minCost[nowCity]) continue;

        // 현 지역에서 갈 수 있는 node
        for(pair<int,int> pos : bus[nowCity]) {
            int nextCity = pos.first, nodeCost = pos.second;

            // 현재 위치에서 -> 다음위치 가는 값이 더 작은 경우 : 담아줌
            // 다음 방문노드 기존저장값 > 현위치값+다음방문노드COST
            if(minCost[nextCity] > cost + nodeCost) {
                minCost[nextCity] = cost + nodeCost;
//                cout << "다음도시는 : " << nextCity << " / COST : " << minCost[nextCity] << endl;
                pq.push({cost + nodeCost, nextCity}); // first: 비용, second: 도착지역
            }

        }

    }

}

int main() {

    // 도시의 개수 N(1 ≤ N ≤ 1,000) , 버스의 개수 M(1 ≤ M ≤ 100,000)
    cin >> N >> M;

    // 버스의 정보
    for(int i = 0; i < M; i++) {

        // 출발 도시, 도착지의 도시 번호, 버스 비용
        int s, e, p;
        cin >> s >> e >> p;
        bus[s].push_back({e, p});   // first: S 에서 갈 수 있는 도시, second: S-E 경로 비용
//        bus[e].push_back({s, p});   // first: E 에서 갈 수 있는 도시, second: S-E 경로 비용
        minCost[s] = 1000000000;
        minCost[e] = 1000000000;
    }

    // 시작도시, 종료도시
    cin >> dept >> dest;

    // 다익스트라 알고리즘: 최소비용, 최단경로 찾기
    findMinRoot();

    // 출발 도시에서 도착 도시까지 가는데 드는 최소 비용
    cout << minCost[dest] << endl;

    return 0;
}