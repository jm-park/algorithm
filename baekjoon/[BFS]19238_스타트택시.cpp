/**
 * [ BFS ]
 * 문제: 19238 스타트택시
 *
 * https://www.acmicpc.net/problem/19238
 *
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int answer, N, M, taxiX, taxiY, map[22][22], position[4][2]={{-1,0},{1,0},{0,-1},{0,1}};  // 위, 아래, 좌, 우
vector<vector<pair<int,int>>> customer;

int findShortDist(int deptX, int deptY, int destX, int destY) {

    int minDist = 0;
    queue<vector<int>> que;
    int visit[22][22] = {0,};
    que.push({deptX,deptY, 0});


    while(!que.empty()) {
        int x = que.front()[0], y = que.front()[1], dist = que.front()[2];
        que.pop();

        // 도착지점인 경우 탈출
        if(x == destX && y == destY) {
            minDist = dist;
            break;
        }

        for(int i = 0; i < 4; i++) {

            int nX = x+position[i][0], nY = y+position[i][1];

            // 격자범위를 벗어남 or 벽이 있거나 or 이미 방문했다면 PASS
            if(nX < 1 || nX > N || nY < 1 || nY > N || map[nX][nY] == 1 || visit[nX][nY] == 1) continue;

            visit[nX][nY] = 1;
            que.push({nX,nY,dist+1});

        }

    }

    return minDist;
}

int main() {

    // N : 격자, M명의 승객, answer: 초기 연료  (2 ≤ N ≤ 20, 1 ≤ M ≤ N2, 1 ≤ 초기 연료 ≤ 500,000)
    cin >> N >> M >> answer;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            // 0: 빈칸, 1: 벽
            cin >> map[i][j];
        }
    }

    cin >> taxiX >> taxiY;

    // 승객
    for(int i = 0; i < M; i++) {
        int x1, y1, x2, y2;
        // 출발지의 행과 열 & 목적지의 행과 열
        cin >> x1 >> y1 >> x2 >> y2;

        vector<pair<int,int>> info;
        info.push_back({x1, y1});
        info.push_back({x2, y2});

        customer.push_back(info);
    }

    while(M--) {

        // 1. 손님선택
        int shortCusIdx = 0, minDist = 987654321;
        for(int i = 0; i <= M; i++) {

            int dist = findShortDist(taxiX, taxiY, customer[i][0].first, customer[i][0].second);

            // 1-1) 현재 위치에서 최단거리가 가장 짧은 승객 선택
            if(minDist > dist) {
                shortCusIdx = i;
                minDist = dist;
            }
            else if(minDist == dist) {
                // 1-2) 여러명이면, 행 번호가 가장 작은 승객
                if(customer[shortCusIdx][0].first > customer[i][0].first) {
                    shortCusIdx = i;
                    minDist = dist;
                }
                else if(customer[shortCusIdx][0].first == customer[i][0].first) {
                    // 1-3) 여러명이면, 열 번호가 가장 작은 승객
                    if(customer[shortCusIdx][0].second > customer[i][0].second) {
                        shortCusIdx = i;
                        minDist = dist;
                    }
                }
            }
        }

//        cout << "===========손님선택===========\n 시작: " << customer[shortCusIdx][0].first << " " << customer[shortCusIdx][0].second << " / 도착: " << customer[shortCusIdx][1].first << " " << customer[shortCusIdx][1].second << endl;


        // 2. 이동
        if(minDist >= answer || (minDist == 0 && !(taxiX == customer[shortCusIdx][0].first && taxiY == customer[shortCusIdx][0].second))) { // 손님을 태우러가는데 연료가 부족한 경우 or 갈 수 없는 경우 => 종료
            answer = -1;
            break;
        }
        // 2-1) 이동시, 연료 -= 1 (한칸당)
        int dist2 = findShortDist(customer[shortCusIdx][0].first, customer[shortCusIdx][0].second, customer[shortCusIdx][1].first, customer[shortCusIdx][1].second);
        if(dist2+minDist > answer || dist2 == 0) {   // 목적지 도착까지 연료가 부족한 경우 or 갈 수 없는 경우 => 종료
            answer = -1;
            break;
        }
        // 2-2) 도착시, "연료 += 소모한 연료 *2" 충전 (도착시 0은 상관없음)
        answer = answer - (dist2+minDist) + (dist2*2);

//        cout << "도착 후 연료 상태=====> 갈때: " << minDist << " 목적지도착시: " << dist2 << " 연료는? " << answer << endl << endl;
        // 택시 위치 변경
        taxiX = customer[shortCusIdx][1].first;  taxiY = customer[shortCusIdx][1].second;

        // 손님 제거
        vector<vector<pair<int,int>>> newList;
        for(int i = 0; i <= M; i++) {
            if(i != shortCusIdx) {
                vector<pair<int,int>> value = customer[i];
                newList.push_back(value);
            }
        }
        customer=newList;
    }


    // 모든 손님을 이동시키고 연료를 충전했을 때 남은 연료의 양
    // 도중 연료가 바닥 or 모든 손님을 이동시킬 수 없는 경우 => -1
    cout << answer << endl;
    return 0;
}