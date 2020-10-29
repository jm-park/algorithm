/**
 * [ DP ]
 * 문제: 11048 이동하기
 *
 * https://www.acmicpc.net/problem/11048
 *
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int answer[1005][1005], N, M, map[1005][1005], position[3][2]={{1,0},{0,1},{1,1}}; // 아래, 오른쪽, 우측대각선아래(남동)

void searchRoot() {

    answer[1][1] = map[1][1];

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            for(int pos = 0; pos < 3; pos++) {

                int nX = i+position[pos][0], nY = j+position[pos][1];
                if(nX >= 1 && nX <= N && nY >= 1 && nY <= M) {
                    answer[nX][nY] = max(answer[nX][nY], answer[i][j]+map[nX][nY]);
                }
            }
        }
    }

}

int main() {

    // (1 ≤ N, M ≤ 1,000)
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> map[i][j];
        }
    }

    searchRoot();

    // (N, M)에서 가져올 수 있는 사탕 개수의 최댓값
    cout << answer[N][M] << endl;

    return 0;
}