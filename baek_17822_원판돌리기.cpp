/**
 * [ DFS & 시뮬레이션 ]
 * 문제: 17822 원판돌리기
 *
 * https://www.acmicpc.net/problem/17822
 *
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, T, cnt, map[55][55], position[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};    // 우, 좌, 아래, 위
queue<vector<int>> moveInfo;

void rotate(int x, int d, int k) {

    /**
     * 실수하기 딱 좋은 부분!!
     * 원판은 X배수인 경우만 돌리는데 => 이부분!!!!!!!!!
     * x배수는 결국 x를 계속 더해나가는 것임.....
     */
    // 돌리려는 원판
    for(int i = x; i <= N; i += x) {

        // 회전 횟수
        for(int j = 0; j < k; j++) {

            if(d == 0) {    // 시계방향
                int tmp = map[i][M];
                for(int idx = M; idx > 1; idx--) {
                    map[i][idx] = map[i][idx-1];
                }
                map[i][1] = tmp;
            }
            else {  // 반시계방향
                int tmp = map[i][1];
                for(int idx = 1; idx < M; idx++) {
                    map[i][idx] = map[i][idx+1];
                }
                map[i][M] = tmp;
            }
        }

    }

}

int findSameNum(int x, int y, int numCnt, int visit[55][55]) {

    // 숫자가 다 지워진경우 탈출
    if(cnt == numCnt) return numCnt;

    for(int i = x; i <= N; i++) {

        for(int j = y; j <= M; j++) {
            if(visit[i][j] == 1 || map[i][j] == 0) continue;
            if(visit[i][j] == 0)
                visit[i][j] = 1;
            // 인접한 곳 탐색
            for(int pos = 0; pos < 4; pos++) {
                int nX = i+position[pos][0], nY = j+position[pos][1];

                // 시작점과 끝점이 만나는 경우를 체크해줌
                if(nX < 1 || nX > N || nY < 1 || nY > M) {
                    if(pos == 0) { // 우
                        nY = 1;
                    } else if(pos == 1) { // 좌
                        nY = M;
                    }
                }

                if(map[i][j] == map[nX][nY]){
                    visit[i][j]++;
                }
                if(visit[nX][nY] > 0) continue;

                if(map[i][j] == map[nX][nY]) {
                    findSameNum(nX, nY, numCnt++, visit);
                    map[nX][nY] = 0;
                }

            }

            if(visit[i][j] > 1) {
                map[i][j] = 0;
            }
        }
    }

    return numCnt;
}

void changeNumber() {

    int avg = 0, totalCnt = 0;
    // 평균값 구하기
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            avg += map[i][j];
            if(map[i][j] != 0) totalCnt++;
        }
    }

    cnt = totalCnt;
//    cout << "cnt: " << cnt << " 평균값 : " << avg/(cnt*1.0) << endl;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(map[i][j] > 0 && map[i][j] < avg/(cnt*1.0)) {
                map[i][j] += 1;
            } else if(map[i][j] > avg/(cnt*1.0)) {
                map[i][j] -= 1;
            }
        }
    }
}

int main() {

    int answer = 0;

    cin >> N >> M >> T;
    // 원판 정보
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> map[i][j];
            cnt++;  // 원판 숫자 개수
        }
    }

    // 회전 정보
    for(int i = 0; i < T; i++) {
        int x,d,k;
        cin >> x >> d >> k;
        moveInfo.push({x,d,k});
    }

    while(!moveInfo.empty() && cnt > 0) {
        // x: 배수의 원판, d: 방향(0-시계 / 1-반시계) , k: 회전횟수
        int x = moveInfo.front()[0], d = moveInfo.front()[1], k = moveInfo.front()[2];
        moveInfo.pop();

        // 1. 회전한다.
        rotate(x, d, k);

        // 2. 원판에 수가 있다면, 인접하면서 같은 수를 모두 찾는다.
        int visit[55][55]={0,};
        int result = findSameNum(1,1,0,visit);

        // 2-1. 인접한 수는 삭제(0)
        // 2-1. 인접한 수 없다면, 모든수의 평균값 계산 후, 평균값 > 수 => 수+1 or 평균값 < 수 => 수-1
        if(result == 0) {
            changeNumber();
        }
    }


    // 원판을 T번 회전시킨 후 원판에 적힌 수의 합
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(map[i][j] != 0) answer += map[i][j];
        }
    }
    cout << answer << endl;

    return 0;
}