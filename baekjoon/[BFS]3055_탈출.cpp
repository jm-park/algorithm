/**
 * [ BFS ]
 * 문제: 3055 탈출
 *
 * https://www.acmicpc.net/problem/3055
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

#define MAX_SIZE 55
using namespace std;

int R, C, destX, destY; // 도착지
char map[MAX_SIZE][MAX_SIZE];
int position[4][2] = {{0,1},{0,-1},{1,0},{-1,0}}; // 우, 좌, 아래, 위
queue<pair<int,int>> water;

int bfs(int deptX, int deptY) {

    int result = -1;
    queue<vector<int>> que;
    int visit[MAX_SIZE][MAX_SIZE] = {0,};
    que.push({deptX, deptY, 0});
    visit[deptX][deptY] = 1;

    int prevCost = -1;
    while(!que.empty()) {
        int x = que.front()[0], y = que.front()[1], cost = que.front()[2];
        que.pop();

        // 물웅덩이는 PASS
        if(map[x][y] == '*') continue;

        // 목적지 도착 시, 탈출
        if(x == destX && y == destY) {
            result = cost;
            break;
        }

        // 고슴도치가 움직일 수 있는 방향 탐색
        for(int i = 0; i < 4; i++) {
            int nX = x + position[i][0], nY = y + position[i][1];

            // 범위를 벗어나거나 or 이미 방문을 했거나 or 돌/물 이 있거나
            if(nX < 0 || nX >= R || nY < 0 || nY >= C || visit[nX][nY] == 1
                || map[nX][nY] == 'X' || map[nX][nY] == '*') continue;

            // 방문 처리
            visit[nX][nY] = 1;
            que.push({nX, nY, cost+1});
        }

        // 고슴도치가 4방위 탐색을 끝내면, 물이 4방위로 퍼진다.
        if(prevCost != cost) {
            prevCost = cost;

            queue<pair<int,int>> newWater;
            while(!water.empty()) {
                int wX = water.front().first, wY = water.front().second;
                water.pop();

                for(int i = 0; i < 4; i++) {
                    int nX = wX + position[i][0], nY = wY + position[i][1];

                    // 범위를 벗어나거나 or 이미 방문을 했거나 or 돌/물 이 있거나
                    if(nX < 0 || nX >= R || nY < 0 || nY >= C
                       || map[nX][nY] == 'X' || map[nX][nY] == '*' ||  map[nX][nY] == 'D') continue;

                    map[nX][nY] = '*';
                    newWater.push({nX, nY});
                }
            }

            water = newWater;
        }

    }



    return result;
}

int main() {

    int deptX, deptY; // 고슴도치 위치

    // R과 C (50보다 작거나 같은)
    scanf("%d %d ", &R, &C);

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            // 비어있는 곳은 '.'로 표시되어 있고, 물이 차있는 지역은 '*', 돌은 'X'
            cin >> map[i][j];

            if(map[i][j] == 'D') { // 비버의 굴은 'D'
                destX = i; destY = j;
            } else if(map[i][j] == 'S') { // 고슴도치의 위치는 'S'
                deptX = i; deptY = j;
            } else if(map[i][j] == '*') { // 물이 차있는 지역은 '*'
                water.push({i,j});
            }
        }
    }

    int answer = bfs(deptX, deptY);

    // 비버의 굴로 이동할 수 있는 가장 빠른 시간
    if(answer == -1) {
        printf("KAKTUS\n");
    } else {
        printf("%d\n", answer);
    }
    return 0;
}