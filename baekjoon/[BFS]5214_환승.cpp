/**
 * [ BFS ]
 * 문제: 5214 환승
 *
 * https://www.acmicpc.net/problem/5214
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, K, M, answer = -1;

vector<vector<int>> edges; // 각 하이퍼튜브가 연결하는 역 정보.
vector<int> stations[100001]; // 각 역이 갖고있는 하이퍼튜브 정보.

void bfs() {

    queue<vector<int>> que;
    que.push({1,1}); // 0: 현재 역, 1: 방문한 역의 개수

    // visit: 역 방문여부 확인, eVisit: 하이퍼튜브 방문 확인
    int visit[100001]= {0,}, eVisit[1001] = {0, };
    visit[1] = 1;


    while(!que.empty()) {
        int now = que.front()[0], cost = que.front()[1];
        que.pop();

        if(now == N) {
            answer = cost;
            break;
        }

        // 현재 역에 연결되어있는 하이퍼 튜브를 for문으로 돌린다.
        for(int tube : stations[now]) {

            // 해당 하이퍼튜브를 방문했었는지 확인.
            if(eVisit[tube] == 1) continue;
            eVisit[tube] = 1;

            // 해당 하이퍼튜브에 연결되어있는 역정보를 구한다.
            for(int station: edges[tube]) {
                if(visit[station] == 0) {
                    visit[station] = 1;
                    que.push({station, cost+1});
                }
            }
        }
    }
}

int main() {

    // 역의 수 N, 한 하이퍼튜브가 서로 연결하는 역의 개수 K, 하이퍼튜브의 개수 M
    // (1 ≤ N ≤ 100,000, 1 ≤ K, M ≤ 1000)
    cin >> N >> K >> M;

    for(int i = 0; i < M; i++) {

        vector<int> edge;
        // 하이퍼튜브 하나가 연결하는 역의 개수는 K 개
        for(int j = 0; j < K; j++) {
            int n;
            cin >> n;

            edge.push_back(n);

            // 해당 역에 서는 하이퍼튜브번호
            stations[n].push_back(i);
        }

        // 한 하이퍼튜브가 연결하는 역 번호들
        edges.push_back(edge);
    }

    bfs();

    // 1번역에서 N번역으로 가는데 방문하는 역의 개수의 최솟값, 갈 수 없다면 -1
    cout << answer << endl;
    return 0;
}