/**
 * [ 전체탐색 BY DFS ]
 * 문제: 15684 사다리 조작
 *
 * https://www.acmicpc.net/problem/15684
 *
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, H, answer = 4, map[31][11], position[4][2] = {{0,0},{0,1},{0,-1}};  // 우 . 좌

int checkMap(int moveMap[31][11]) {

    int result = 0;
    for(int n = 1; n <= N; n++) {
        int x = 1, y = n;

        while(1) {
            // 가장 아래까지 탐색한 경우 종료
            if(x > H) break;

            // 사다리가 있는 경우 탐색
            if(moveMap[x][y] > 0) {
                y += position[moveMap[x][y]][1];
            }

            // 무조건 한칸씩 내려감
            x++;
        }

        // i번 세로선의 결과가 i번인 경우 count 해줌
        if(x == H+1 && y == n) {
            result++;
        }
    }

    return result;
}

void dfs(int cnt, int nextN, int moveMap[31][11]) {

    // 3보다 큰 값이면 종료
    if(cnt > 3) {
        return;
    }

    // 사다리타기 조작 결과 체크
    int result = checkMap(moveMap);
    if(result == N) {
        answer = min(answer, cnt);
        return;
    }

    // 사다리타기 조작결과 체크 후, 종료
    if(cnt == 3) {
        return;
    }

    // 배열 복사본
    int copyMap[31][11] = {0,};
    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= N; j++) {
            copyMap[i][j] = moveMap[i][j];
        }
    }

    for (int n = nextN; n < N; n++) {   // 세로줄 기준으로 탐색

        for (int h = 1; h <= H; h++) {

            if (copyMap[h][n] == 0) {

                // 현 위치로부터 오른쪽에 좌표를 찍는다 오른쪽
                int nX = h + position[1][0], nY = n + position[1][1];
                int val = copyMap[nX][nY];
                if (1 <= nX && nX <= H && 1 <= nY && nY <= N && copyMap[nX][nY] == 0) {
                    copyMap[h][n] = 1;
                    copyMap[nX][nY] = 2;
                    dfs(cnt + 1, n, copyMap);
                    copyMap[h][n] = 0;
                    copyMap[nX][nY] = 0;
                }
            }

        }
    }
}

int main() {

    // 세로선의 개수 N (2 ≤ N ≤ 10)
    // 가로선의 개수 M (1 ≤ H ≤ 30)
    // 세로선마다 가로선을 놓을 수 있는 위치의 개수 H (0 ≤ M ≤ (N-1)×H)
    cin >> N >> M >> H;

    for(int i = 1; i <= M; i++) {
        int x, y;
        cin >> x >> y;
        // 사다리 표기
        map[x][y] = 1; // 우측으로 이어짐
        map[x][y+1] = 2; // 왼쪽으로 이어짐
    }

    // 사다리가 없는경우, 사다리를 놓지않아도 통과됨
    if(M == 0) {
        cout << 0 << endl;
        return 0;
    }

    dfs(0, 1, map);

    // 3보다 큰 값이면 -1을 출력, 불가능한 경우에도 -1
    // 가로선 개수의 최솟값
    if(answer == 4) {
        answer = -1;
    }

    cout << answer << endl;

    return 0;
}