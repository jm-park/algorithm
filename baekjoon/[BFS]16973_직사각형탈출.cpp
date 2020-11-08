/**
 * [ BFS ]
 * 문제: 16973 직사각형탈출
 *
 * https://www.acmicpc.net/problem/16973
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;

int answer = -1, N, M, H, W, deptX, deptY, destX, destY;
int visit[1001][1001], map[1001][1001], position[4][2]= {{0,1},{0,-1},{1,0},{-1,0}}; // 우, 좌, 아래, 위

void move() {

    // 사각형 좌표의 시계방향 순
    deque<vector<int>> que;
    que.push_back({deptX, deptY, 0}); // 0: x좌표, 1: y좌표, 2: 이동수
    visit[deptX][deptY] = 1;    // 방문 처리

    while(!que.empty()) {
        int x = que.front()[0], y = que.front()[1], cnt = que.front()[2];
        que.pop_front();

        // 도착지점인 경우, BFS 탈출
        if(x == destX && y == destY) {
            answer = cnt;
            break;
        }

        // 사방위 이동
        for(int pos = 0; pos < 4; pos++) {
            int nX = x + position[pos][0], nY = y + position[pos][1];

            // 격자범위를 벗어난 경우 or 이미 방문한 경우
            if(nX < 1 || nY < 1 || nX+H-1 > N || nY+W-1 > M || visit[nX][nY] == 1) continue;
            else {
                visit[nX][nY] = 1;

                /**
                 * [시간단축부분]
                 * 벽이 있는 경우 확인!!
                 *
                 * 시간을 줄이기 위해서, 추가된 부분만 벽이 있는지 확인한다 => 이미 전 부분들은 벽이 없는 곳이기 때문에.
                 */
                int hasWall = 0;
                if(pos == 0) { // 우(세로줄) 확인
                    for(int h = nX; h <= nX+H-1; h++) {
                        if(map[h][nY+W-1] == 1) {
                            hasWall = 1; break;
                        }
                    }
                } else if(pos == 1){// 좌(세로줄) 확인
                    for(int h = nX; h <= nX+H-1; h++) {
                        if(map[h][nY] == 1) {
                            hasWall = 1; break;
                        }
                    }
                } else if(pos == 2) { // 아래(가로줄) 확인
                    for(int w = nY; w <= nY+W-1; w++) {
                        if(map[nX+H-1][w] == 1) {
                            hasWall = 1; break;
                        }
                    }
                } else if(pos == 3) { // 위(가로줄) 확인
                    for(int w = nY; w <= nY+W-1; w++) {
                        if(map[nX][w] == 1) {
                            hasWall = 1; break;
                        }
                    }
                }

                // 벽이 없는 경우: 방문 처리
                if(hasWall == 0) {
                    // 목적지에 도착한 경우 탈출
                    if (nX == destX && nY == destY) {
                        // 일부러 front에 push하여 while문 탈출하도록
                        que.push_front({nX, nY, cnt + 1});
                        break;
                    } else {
                        que.push_back({nX, nY, cnt + 1});
                    }
                }
            }
        }
    }

}

int main() {

    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            // 0은 빈 칸, 1은 벽
            cin >> map[i][j];
            // 벽이 있는 곳은 바로 방문처리 해버리기
            if(map[i][j] == 1) visit[i][j] = 1;
        }
    }

    // 직사각형의 크기 H, W, 시작 좌표 Sr, Sc, 도착 좌표 Fr, Fc
    cin >> H >> W >> deptX >> deptY >> destX >> destY;

    move();

    // 최소 이동 횟수, 이동할 수 없는 경우에는 -1을 출력
    cout << answer << endl;

    return 0;
}