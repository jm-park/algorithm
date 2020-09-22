#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/**
 * [  ]
 * 문제: 2606 바이러스
 *
 * https://www.acmicpc.net/problem/2606
 *
 * @return
 */
int N, M, answer;
int map[105][105], visit[105];

void dfs(int x, int y) {    // X에서 Y로 간다.

    if(visit[y] == 1) {
        return;
    } else if(map[x][y] == 1) { // 경로가 있는 경우 탐색
        answer++;
//        cout << "answer 값 증가=====> X: " << x << " / Y: " << y << " / answer : " << answer <<  endl;
        // 방문 표기
        visit[x] = 1;
        visit[y] = 1;

        for(int i = 1; i <= N; i++) {
            if(map[y][i] == 1 && visit[i] == 0) {
                dfs(y, i);
            }
        }
    }

}

int main() {
    scanf("%d %d", &N, &M);

    for(int i = 0; i < M; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        map[x][y] = 1;
        map[y][x] = 1;
    }

    // 1에서 갈수있는 모든 경우를 탐색한다.
    for(int i = 2; i <= N; i++) {
        dfs(1, i);
    }

    cout << answer;

}