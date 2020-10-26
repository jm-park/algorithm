#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/**
 * [ DFS로 풀었을때 시간초과남 ]
 * 문제: 1520 내리막길
 *
 * https://www.acmicpc.net/problem/1520
 *
 * @return
 */
int N, M, answer, destination;
int map[505][505], visit[505][505];
int position[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}}; // 우, 좌, 아래, 위

void dfs(int x, int y, int prevVal) {

    // 도착한경우
    if(x == N-1 && y == M-1 && map[x][y] < prevVal) {
        answer++;
        return;
    }

    // 더이상 갈 수 없는 경로 조건(PASS) : 이전값 이상인 경우는 && 목적지 값보다 작아서 도착할 수 없는 경우
    if(map[x][y] >= prevVal || map[x][y] < destination) {
        return;
    } else if(map[x][y] < prevVal) {

        for(int i = 0; i < 4; i++) {
            int nextX = x+position[i][0], nextY = y+position[i][1];

            // 지도 범위를 벗어나지 않는 경우로 체크 & 갈수있는 범위인지 체크
            if(nextX >= 0 && nextX < N && nextY >= 0 && nextY < M
                && visit[nextX][nextY] == 0 && map[nextX][nextY] < map[x][y] && map[nextX][nextY] >= destination) {
                visit[nextX][nextY] = 1;
                dfs(nextX, nextY, map[x][y]);
                visit[nextX][nextY] = 0;
            }
        }
    }
}

int main() {
//    scanf("%d %d", &N, &M);
    cin >> N  >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <M; j++) {
            cin >> map[i][j];
        }
    }

    destination = map[N-1][M-1];
//    cout << "\n\n==========??" << endl;
//    for(int i = 0; i < N; i++) {
//        for(int j = 0; j <M; j++) {
//            cout <<  map[i][j] << " ";
//        }
//        cout << endl;
//    }
    visit[0][0] = 1;
    dfs(0,0,987654321);
    cout << answer;

}