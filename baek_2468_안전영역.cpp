#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <ctime>

using namespace std;

/**
 * [ BFS ]
 * 문제: 2468 안전영역
 *
 * https://www.acmicpc.net/problem/2468
 *
 * @return
 */
int N, answer=1, maxHeight, minHeight=987654321;
int map[105][105], visited[105][105], position[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};    // 좌, 우, 아래, 위
vector<pair<int,int>> area;

int bfs(int height) {

    int cnt = 0;

    for(pair<int,int> pos : area) {
        queue<pair<int,int>> que;

        if(visited[pos.first][pos.second] == 0) {
            que.push({pos.first, pos.second});
            visited[pos.first][pos.second] = 1;

            while(!que.empty()) {
                int nowX = que.front().first, nowY = que.front().second;
                que.pop();

                for(int i = 0; i < 4; i++) {
                    int nextX = nowX+position[i][0], nextY = nowY+position[i][1];

                    // 방문가능한 경우 & 물에 잠기지 않은 경우
                    if(nextX >= 0 && nextX < N && nextY >= 0 && nextY < N
                       && visited[nextX][nextY] == 0 && map[nextX][nextY] > height) {

                        que.push({nextX, nextY});
                        // 방문처리
                        visited[nextX][nextY] = 1;
                    }
                }

            }

            cnt++;
        }
    }


    return cnt;

}

/**
 * 물에 잠긴 지역 표기
 * 1: 잠기지 않았음,
 * 0: 잠겼음
 * @param height
 */
void afterRain(int height) {

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(map[i][j] > height) {
                area.push_back({i,j});
                visited[i][j] = 0;
            }
        }
    }

}
int main() {

    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> map[i][j];
            if(maxHeight < map[i][j]) {
                maxHeight = map[i][j];  // 가장 높은 높이값
            }
            if(minHeight > map[i][j]) {
                minHeight = map[i][j];  // 가장 낮은 높이값
            }
        }
    }

    for(int i = minHeight; i < maxHeight; i++) {
        area.clear();

        // 침수지역 표기
        afterRain(i);

        // 안전영역 구하기
        int maxVal = bfs(i);
        answer = max(maxVal, answer);
    }

    cout << answer;
}