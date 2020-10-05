/**
 * [ 전체탐색 BY DFS ]
 * 문제: 12100 2048(Easy)
 *
 * https://www.acmicpc.net/problem/12100
 *
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, answer = 0, map[25][25], position[4][2] = {{0,1}, {0,-1},{1,0},{-1,0}}; // 0: 우, 1: 좌, 2: 아래, 3: 위
int idx = 0;
int checkMaxNum(int copyMap[25][25]) {

    int num = 0;
    for(int i = 0 ; i < N; i++) {
        for (int j = 0; j < N; j++) {
            num = max(num, copyMap[i][j]);
        }
    }
    return num;
}

void dfs(int cnt, int newMap[25][25]) {

//    cout << "idx : " << ++idx << endl;
    //  최대 5번 이동시켜서 얻을 수 있는 가장 큰 블록
    if(cnt >= 5) {

        int maxVal = checkMaxNum(newMap);
        answer = max(answer, maxVal);
        return;
    }

    for(int pos = 0; pos < 4; pos++) {

        // 배열 복사
        int copyMap[25][25] = {0, }, merge[25][25]={0,};
        for(int i = 0 ; i < N; i++) {
            for (int j = 0; j < N; j++) {
                copyMap[i][j] = newMap[i][j];
            }
        }

        /**
         * 좌 / 위는 index0부터 시작함
         */
        if(pos == 1 || pos == 3) {

            for(int i = 0 ; i < N; i++) {

                for(int j = 0 ; j < N; j++) {


                    if(merge[i][j] == 1) continue;

                    // 블록이동
                    int nextX = i, nextY = j;
                    while(1) {

                        // 범위를 벗어나기전까지 움직인다. && 해당위치에 다른 숫자가 있으면 멈추고 본다.
//                        int value = copyMap[nextX + position[pos][0]][nextY + position[pos][1]];
                        if(0 > nextX + position[pos][0] || nextX + position[pos][0] >= N || nextY+position[pos][1] < 0 || nextY+position[pos][1] >= N
                           || copyMap[nextX + position[pos][0]][nextY + position[pos][1]] != 0) {

                            if(!(0 > nextX + position[pos][0] || nextX + position[pos][0] >= N || nextY+position[pos][1] < 0 || nextY+position[pos][1] >= N)) {
                                nextX = nextX + position[pos][0];
                                nextY = nextY+position[pos][1];
                            }
                            break;
                        }

                        nextX += position[pos][0], nextY += position[pos][1];

                    }

                    if(nextX == i && nextY == j) continue;

                    // 다음 위치가 범위를 벗어난 경우
                    if(0 > nextX ||  nextX >= N || nextY < 0 || nextY >= N) {
                        int nowNumber = copyMap[i][j];
                        copyMap[i][j] = copyMap[i][j];
                        copyMap[i][j] = nowNumber;
                    }
                        // 다른 숫자가 있는 경우
                    else if(copyMap[nextX][nextY] != 0) {

                        // 합칠 수 있는 경우
                        if(merge[nextX][nextY] == 0 && copyMap[nextX][nextY] == copyMap[i][j]) {

                            // 숫자 합쳐줌
                            copyMap[nextX][nextY] = copyMap[i][j]*2;
                            copyMap[i][j] = 0;

                            // 합쳤다는 것을 표기해줌
                            merge[nextX][nextY] = 1;
                        } else if(!(nextX - position[pos][0] == i && nextY-position[pos][1] == j) && copyMap[nextX - position[pos][0]][nextY-position[pos][1]] == 0){
                            copyMap[nextX - position[pos][0]][nextY-position[pos][1]] = copyMap[i][j];
                            copyMap[i][j] = 0;
                        }
                    } else if(copyMap[nextX][nextY] == 0){    // 빈공간인 경우는 그냥 옮긴다.
                        copyMap[nextX][nextY] = copyMap[i][j];
                        copyMap[i][j] = 0;
                    }

                }
            }
        } else {

            /**
             * 우/아래 는 끝에서부터 시작해줘야 먹힘!!! 이 문제의 핵심 포인트임
             */
            for(int i = N-1 ; i  >= 0; i--) {
                for(int j = N-1 ; j >= 0; j--) {

                    if(merge[i][j] == 1) continue;

                    // 블록이동
                    int nextX = i, nextY = j;
                    while(1) {

                        // 범위를 벗어나기전까지 움직인다. && 해당위치에 다른 숫자가 있으면 멈추고 본다.
//                        int value = copyMap[nextX + position[pos][0]][nextY + position[pos][1]];
                        if(0 > nextX + position[pos][0] || nextX + position[pos][0] >= N || nextY+position[pos][1] < 0 || nextY+position[pos][1] >= N
                           || copyMap[nextX + position[pos][0]][nextY + position[pos][1]] != 0) {

                            if(!(0 > nextX + position[pos][0] || nextX + position[pos][0] >= N || nextY+position[pos][1] < 0 || nextY+position[pos][1] >= N)) {
                                nextX = nextX + position[pos][0];
                                nextY = nextY+position[pos][1];
                            }
                            break;
                        }

                        nextX += position[pos][0], nextY += position[pos][1];

                    }

                    if(nextX == i && nextY == j) continue;

                    // 다음 위치가 범위를 벗어난 경우
                    if(0 > nextX ||  nextX >= N || nextY < 0 || nextY >= N) {
                        int nowNumber = copyMap[i][j];
                        copyMap[i][j] = copyMap[i][j];
                        copyMap[i][j] = nowNumber;
                    }
                        // 다른 숫자가 있는 경우
                    else if(copyMap[nextX][nextY] != 0) {

                        // 합칠 수 있는 경우
                        if(merge[nextX][nextY] == 0 && copyMap[nextX][nextY] == copyMap[i][j]) {

                            // 숫자 합쳐줌
                            copyMap[nextX][nextY] = copyMap[i][j]*2;
                            copyMap[i][j] = 0;

                            // 합쳤다는 것을 표기해줌
                            merge[nextX][nextY] = 1;
                        } else if(!(nextX - position[pos][0] == i && nextY-position[pos][1] == j) && copyMap[nextX - position[pos][0]][nextY-position[pos][1]] == 0){
                            copyMap[nextX - position[pos][0]][nextY-position[pos][1]] = copyMap[i][j];
                            copyMap[i][j] = 0;
                        }
                    } else if(copyMap[nextX][nextY] == 0){    // 빈공간인 경우는 그냥 옮긴다.
                        copyMap[nextX][nextY] = copyMap[i][j];
                        copyMap[i][j] = 0;
                    }

                }
            }
        }


//        cout << "============합친후 ===========" << endl;
//        for(int i = 0 ; i < N; i++) {
//            for(int j = 0 ; j < N; j++) {
//                cout << copyMap[i][j] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;
        dfs(cnt+1, copyMap);
    }


}

int main() {

    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j<N; j++) {
            cin >> map[i][j];
        }
    }

    dfs(0, map);

    cout << answer << endl;

    return 0;
}