/**
 * [ 구현 ]
 * 문제: 17837 새로운게임2
 *
 * https://www.acmicpc.net/problem/17837
 *
 */
#include <vector>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

int answer = -1, N, K, map[13][13], position[5][2]={{0,0},{0,1},{0,-1},{-1,0},{1,0}}; // 1: 우 →, 2: 좌 ←, 3: 위 ↑, 4: 아래 ↓
vector<int> kMap[13][13];   // 체스판에 있는 말 정보
vector<int> kInfo[11];  // 말의 정보

int checkGameEnd(int cnt) {
    for(int i = 1 ; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if(kMap[i][j].size() >= 4) {
                return cnt;
            }
        }
    }
    return -1;
}

void game() {

    int cnt = 0;
    while(1) {
        // 1,000보다 크거나 절대로 게임이 종료되지 않는 경우에는 -1을 출력
        if(cnt > 1000) {
            break;
        }

        // 턴이 진행되던 중에 말이 4개 이상 쌓이는 순간 게임이 종료
        int result = checkGameEnd(cnt);
        if(result == cnt) {
            answer = cnt;
            break;
        }

        int moveCnt = 0, moveChessNum[11] = {0,};    // 0: 아직 안옮김, 1: 옮김
        while(1) {
            // 다옮기면 탈출
            if(moveCnt >= K) break;

            // 말을 움직이는 부분 : 작은 말부터 차례대로
            for(int num = 1; num <= K; num++) {
                if(moveChessNum[num] == 1) continue;

                // 옮김 체크
                moveChessNum[num] = 1;
                moveCnt++;

                // 말의 정보
                int x = kInfo[num][0], y = kInfo[num][1], pos = kInfo[num][2];
                // 다음위치
                int nX = x+position[pos][0], nY = y+position[pos][1];

                // 범위를 벗어난 경우 or 파란색인 경우, 이동 방향을 반대로 하고 한 칸 이동
                if(1 > nX || nX > N || 1 > nY || nY > N || map[nX][nY] == 2) {
                    if(pos%2 == 0) {    // 좌||아래 인 경우는 우||위 로 변경
                        kInfo[num][2]--;
                    } else {
                        kInfo[num][2]++;
                    }
                    pos = kInfo[num][2];

                    // 다음 위치 다시 체크
                    nX = x+position[pos][0], nY = y+position[pos][1];

                    // 방향을 반대로 바꾼 후에 이동하려는 칸이 파란색인 경우에는 이동하지 않고 가만히 있는다
                    if(1 > nX || nX > N || 1 > nY || nY > N || map[nX][nY] == 2) continue;

                }

                vector<int> numbers; // 옮길 말: 이미 뒤집어서 들어감
                for(int i = kMap[x][y].size()-1; i >= 0; i--) {
                    int n = kMap[x][y][i];
                    numbers.push_back(n);
                    kMap[x][y].pop_back();
                    if(n == num) break;
                }

                if(map[nX][nY] == 0){ // 흰색 : 순서 원상복귀
                    reverse(numbers.begin(), numbers.end());
                }

                // 말 옮김
                int chessCnt = numbers.size();
                for(int i = 0; i < chessCnt; i++) {
                    kInfo[numbers[i]][0] = nX; kInfo[numbers[i]][1] = nY;
                    kMap[nX][nY].push_back(numbers[i]);
                }

                // 턴이 진행되던 중에 말이 4개 이상 쌓이는 순간 게임이 종료
                if(kMap[nX][nY].size() >= 4) {
                    moveCnt = K;
                    break;
                }
            }
        }


        cnt++;

    }



}

int main() {

    cin >> N >> K;

    for(int i = 1 ; i <= N; i++) {
        for(int j = 1 ; j <= N; j++) {
            // 0은 흰색, 1은 빨간색, 2는 파란색
            cin >> map[i][j];
        }
    }

    for(int i = 1; i <= K; i++) {
        int x, y, pos;
        cin >> x >> y >> pos;
        // 말의 정보
        kInfo[i].push_back(x);
        kInfo[i].push_back(y);
        kInfo[i].push_back(pos);
        // 지도의 말크기 표기
        kMap[x][y].push_back(i);
    }

    game();
    // 게임이 종료되는 턴의 번호
    cout << answer << endl;

    return 0;
}