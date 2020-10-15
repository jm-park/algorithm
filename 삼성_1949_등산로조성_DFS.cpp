/**
 * [ DFS & 시뮬레이션 ]
 * 문제: 1949 등산로조성
 *
 * https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PoOKKAPIDFAUq
 *
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, K, answer, map[10][10], position[4][2]={{0,1},{0,-1},{1,0},{-1,0}};  // 우, 좌, 아래, 위
vector<pair<int,int>> maxPoint; // 높은 봉우리 모음
int maxRoad;

void dfs(int x, int y, int hint, int road, int visit[10][10]) {

    visit[x][y] = 1;

    for (int pos = 0; pos < 4; pos++) {
        int nX = x + position[pos][0], nY = y + position[pos][1];

        // 범위를 벗어나거나, 이미 방문한 경우는 PASS
        if (nX < 0 || nX >= N || nY < 0 || nY >= N || visit[nX][nY] == 1) continue;

        // 2. 높은 지형에서 낮은 지형으로 연결(연결점은 position만 가능)
        if (map[nX][nY] < map[x][y]) {
            maxRoad = max(road + 1, maxRoad);
            dfs(nX, nY, hint, road + 1, visit);
        }
        // 3. 딱 한 곳!!! 을 정해서 최대 K 깊이만큼 지형을 깎아서 길을 만듬
        // 3-1) 현위치의 값 <= 갈 위치의값 && 현위치의값 > 갈위치의값-K 가능한 경우
        else if (hint == 1 && map[x][y] <= map[nX][nY] && map[x][y] > map[nX][nY] - K) {
            int tmp = map[nX][nY];
            map[nX][nY] = map[x][y] - 1;
            maxRoad = max(road + 1, maxRoad);
            dfs(nX, nY, hint - 1, road + 1, visit);
            map[nX][nY] = tmp;
        }

    }

    visit[x][y] = 0;

    return;
}
int main(int argc, char** argv) {
    int test_case;
    int T;

    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case) {

        answer = 1;
        cin >> N >> K;

        int maxValue = 0;
        maxRoad = 1;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cin >> map[i][j];
                if(maxValue < map[i][j]) {
                    maxPoint.clear();
                    maxValue = map[i][j];
                    maxPoint.push_back({i,j});
                } else if(maxValue == map[i][j]) {
                    maxPoint.push_back({i,j});
                }
            }
        }

        while(maxPoint.size() > 0) {
            // 1. 가장 높은 봉우리에서 시작
            int x = maxPoint.back().first, y=maxPoint.back().second;
            maxPoint.pop_back();

            int visit[10][10]={0,};
            dfs(x,y,1,1,visit);

            //  가장 긴 등산로
            answer = max(maxRoad, answer);
        }

        cout << "#" << test_case <<" "<< answer << endl;

    }
    return 0;
}