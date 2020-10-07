/**
 * [ 구현 ]
 * 문제: 14890 경사로
 *
 * https://www.acmicpc.net/problem/14890
 *
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int answer, N, L, map[105][105];

void findRoad() {


//    cout << "\n=========가로탐색==========" << endl;
    // 가로 탐색
    for(int x = 0; x < N; x++) {
        int roadVal = map[x][0];

        int y, cnt = 1; // 동일한 블럭수를 센다
        for(y = 1; y < N; y++) {

            int sub = roadVal - map[x][y];
            if(sub == 0 || cnt == 0) {
                cnt++;
            }
            if(sub == 1 || sub == -1) {    // 경사로 설치하는 경우
                if(sub == 1) {  // 내려가는 경사
                    int k;
                    // 경사 설치가 가능한지 확인
                    int newHill[105] = {0,};
                    for(k = 1; k < L; k++) {
                        if(0 > y+k || y+k >= N || map[x][y+k] != map[x][y]) {
                            newHill[y+k] = 1;
                            break;
                        }
                    }

                    if(k < L) {
                        break;
                    } else {
                        // 경사 바꿔줌
                        y += L-1;
                        roadVal = map[x][y];
                        cnt = 0;
                    }
                } else {  // 올라가는 경사
                    if(cnt >= L) {
                        if(L == 1 && 0 <= y-2 && y-2 < N && map[x][y-2] - roadVal != 0 && (map[x][y-2] - roadVal != sub)) {
                            break;
                        }
                        // 경사 바꿔줌
                        roadVal = map[x][y];
                        cnt = 0;
                    } else {
                        break;
                    }
                }

            } else if(sub != 0){
                break;
            }

        }

        if(y == N) {
//            cout << "몇번째줄?? " << x+1 << endl;
            answer++;
        }
    }


//    cout << "\n\n=========세로탐색==========" << endl;
    // 세로 탐색
    for(int y = 0; y < N; y++) {
        int roadVal = map[0][y];

        int x, cnt = 1; // 동일한 블럭수를 센다
        for(x = 1; x < N; x++) {

            int sub = roadVal - map[x][y];
            if(sub == 0 || cnt == 0) {
                cnt++;
            }
            if(sub == 1 || sub == -1) {    // 경사로 설치하는 경우
                if(sub == 1) {  // 내려가는 경사
                    int k;
                    // 경사 설치가 가능한지 확인
                    for(k = 1; k < L; k++) {
                        if(0 > x+k || x+k >= N || map[x+k][y] != map[x][y]) {
                            break;
                        }
                    }

                    if(k < L) {
                        break;
                    } else {
                        // 경사 바꿔줌
                        x += L-1;
                        roadVal = map[x][y];
                        cnt = 0;
                    }
                } else {  // 올라가는 경사
                    if(cnt >= L) {
                        if(L == 1 && 0 <= x-2 && x-2 < N && map[x-2][y] - roadVal != 0 && (map[x-2][y] - roadVal != sub)) {
                            break;
                        }
                        // 경사 바꿔줌
                        roadVal = map[x][y];
                        cnt = 0;
                    } else {
                        break;
                    }
                }

            } else if(sub != 0){
                break;
            }

        }

        if(x == N) {
//            cout << "몇번째줄?? " << y+1 << endl;
            answer++;
        }
    }
}

int main() {

    // (2 ≤ N ≤ 100)과 L (1 ≤ L ≤ N)
    cin >> N >> L;

    for(int i = 0 ; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    findRoad();

    // 지나갈 수 있는 길
    cout << answer << endl;
    return 0;
}