/**
 * [ DP & DFS ]
 * 문제: 1937 욕심쟁이 판다
 *
 * https://www.acmicpc.net/problem/1937
 *
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int maxCnt, answer, n, visit[501][501], dp[501][501], map[501][501], position[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

void dfs(int x, int y, int cnt) {

    if(maxCnt < cnt) {
        maxCnt = cnt;
    }

    // 2. 상, 하, 좌, 우 중 한 곳으로 이동
    for(int pos = 0; pos < 4; pos++) {
        int nX = x+position[pos][0], nY = y+position[pos][1];

        // 격자 범위 내 & 방문전 & 값이 더 커야함
        if(nX >= 0 && nX < n && nY >= 0 && nY < n && visit[nX][nY] == 0 && map[x][y] < map[nX][nY]) {

            if(dp[nX][nY] == 0) { // 이전에 저장해둔 최대 경로 값이 없는 경우
                // 1. 대나무를 먹기
                visit[nX][nY] = 1;
                dfs(nX, nY, cnt+1);
                // 되돌리기
                visit[nX][nY] = 0;
            } else { // 최대 경로값이 있는 경우, 그 값을 그대로 사용
                maxCnt = max(maxCnt, cnt+dp[nX][nY]);
            }

        }

    }


}

int main() {

    vector<vector<int>> sortByVal;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
            sortByVal.push_back({i,j,map[i][j]});
        }
    }

    /**
     * [시간단축 포인트]
     * 먹이 값이 가장 큰 것부터 내림차순 정렬
     *
     * 이유: 큰수들은 무조건 DFS탐색에 들어가기 때문에,
     *      최대한 탐색횟수를 줄이기 위해 DP 에 미리 저장해 두도록 순서 설정
     */
    sort(sortByVal.begin(), sortByVal.end(), [](const vector<int> & a, const vector<int> &b) {
        return a[2] > b[2];
    });

    for (int i = 0; i < n * n; i++) {
        int x = sortByVal[i][0], y = sortByVal[i][1];
        maxCnt = 0;
        visit[x][y] = 1;
        dfs(x, y, 1);
        dp[x][y] = maxCnt;
        visit[x][y] = 0;
        answer = max(maxCnt, answer);
    }

    // 첫째 줄에는 판다가 최대한 살 수 있는 일수(K)를 출력
    cout << answer << endl;
    return 0;
}