/**
 * [ MST ]
 * 문제: 2887 행성 터널
 *
 * https://www.acmicpc.net/problem/2887
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX_SIZE 100001

using namespace std;

int N;
vector<vector<int>> planets;
vector<vector<int>> costs;
int parents[MAX_SIZE];

void findCost(int pos) {

    for (int i = 0; i < N - 1; i++) {
        // 연결비용: min(|xA-xB|, |yA-yB|, |zA-zB|)
        int cost = abs(planets[i][pos] - planets[i + 1][pos]);

        int nowPlanet= planets[i][0], nextPlanet = planets[i+1][0];

        // 0, 1: 연결되는 NODE , 3: 비용
        costs.push_back({nowPlanet, nextPlanet, cost});
    }
}

int findParent(int n) {
    if(parents[n] == n) return n;
    else return parents[n] = findParent(parents[n]); // 부모의 ROOT가 변경된 경우, 같이 변경됨!
}

void mergeEdge(int x, int y) {
    // 병합기준: 더 작은 NODE쪽으로 합친다.
    if(x > y) {
        parents[x] = y;
    } else {
        parents[y] = x;
    }
}

int mst() {

    long long answer = 0;
    int cnt = 0;
    // 1. 가중치가 작은 것 우선 탐색.
    for(vector<int> edge: costs) {
        if(cnt == N-1) break;

        int x = edge[0], y = edge[1], cost = edge[2];

        // 2. 조상 탐색: 사이클이 생성되는지 확인하기 위해
        int xP = findParent(x);
        int yP = findParent(y);

        // 조상이 같지 않은 경우 => 즉, 사이클이 형성되지 않는 경우
        // 3. 두 간선은 합쳐준다(조상끼리 합쳐줌)
        if(xP != yP) {
            mergeEdge(xP, yP);
            answer += cost;
            cnt++;
        }
    }

    return answer;
}

int main() {

    int x, y, z;

    // 행성의 개수 N (1 ≤ N ≤ 100,000)
    scanf("%d", &N);

    // 각 행성의 x, y, z좌표 (-10^9보다 크거나 같고, 10^9보다 작거나 같은 정수)
    for(int i = 0; i < N; i++) {
        scanf("%d %d %d", &x, &y, &z);
        planets.push_back({i, x,y,z});

        // 부모배열 초기화
        parents[i] = i;
    }

    // 각 행성끼리 연결하는데 드는 비용 계산
    for (int pos = 1; pos <= 3; ++pos) {

        /**
         * [Lamdat exp Sort]
         * 각 좌표 기준으로 최단거리 계산
         *
         * 오름차순으로 정렬하면, 현 노드 Idx의 다음노드 Idx+1 이 가장 가까운 최단거리가 된다!!!!
         */
        sort(planets.begin(), planets.end(), [&pos](const vector<int>&a, const vector<int>&b) {
            return a[pos] < b[pos];
        });
        findCost(pos);
    }

    // 최소 비용 순으로, 오름차순 정렬
    sort(costs.begin(), costs.end(), [](const vector<int>&a, const vector<int>&b) {
        return a[2] < b[2];
    });

    // 모든 행성을 터널로 연결하는데 필요한 최소 비용
    printf("%d\n", mst());
    return 0;
}