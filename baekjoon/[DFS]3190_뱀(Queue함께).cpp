/**
 * [ DFS ]
 * 문제: 3190 뱀
 *
 * https://www.acmicpc.net/problem/3190
 *
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, K, L, answer, map[105][105], snakeMap[105][105], position[4][2]={{0,1},{1,0},{0,-1},{-1,0}}; // 우, 아래, 좌, 위
queue<pair<int,int>> snake; // 뱀
queue<pair<int,int>> snakeDir;  // 뱀 방향

void dfs(int x, int y, int pos) {

    answer++;
    int nextX = x+position[pos][0], nextY = y+position[pos][1];

    // 0. 뱀이 이리저리 기어다니다가 벽 또는 자기자신의 몸과 부딪히면 게임이 끝
    if(nextX <= 0 || nextX > N || nextY <= 0 || nextY > N) return;
    else if(snakeMap[nextX][nextY] == 1) return;

    // 1. 뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다.
    snakeMap[nextX][nextY] = 1;
    snake.push({nextX,nextY});

    // 2. 만약 이동한 칸에 사과 O, 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다. (즉, 뱀 길이가 늘어남)
    if(map[nextX][nextY] == 1) {
        map[nextX][nextY] = 0;
    }
    // 3. 만약 이동한 칸에 사과 X, 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다. 즉, 몸길이는 변하지 않는다.
    else {
        snakeMap[snake.front().first][snake.front().second] = 0;
        snake.pop();
    }

    if(!snakeDir.empty() && snakeDir.front().first <= answer) {
        switch (snakeDir.front().second) {
            case 'L': // 왼쪽
                pos = pos == 0 ? 3 : pos-1; break;
            case 'D': // 오른쪽
                pos = (pos+1)%4; break;
        }
        snakeDir.pop();
    }

    dfs(nextX, nextY, pos);
}

int main() {

    scanf("%d %d", &N, &K);

    // 사과위치 표기 : 모두 다른치에 있고, (1,1)에는 사과 없음
    for(int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        map[x][y] = 1;
    }

    cin >> L;
    for(int i = 0; i < L; i++) {
        int x; char c;
        // X초가 끝난 뒤에 왼쪽(C가 'L') 또는 오른쪽(C가 'D')로 90도 방향을 회전시킨다는 뜻
        scanf("%d %c", &x, &c);
        snakeDir.push({x,c});
    }

    snakeMap[1][1] = 1;
    snake.push({1,1});

    dfs(1,1,0);
    //  게임이 몇 초에 끝나는지
    cout << answer << endl;

    return 0;
}