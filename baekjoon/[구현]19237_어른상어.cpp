/**
 * [ 구현 ]
 * 문제: 19237 어른상어
 *
 * https://www.acmicpc.net/problem/19237
 *
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int answer = 0, N, M, k, map[22][22], nowPos[405];
int position[5][2] = {{0,0},{-1,0},{1,0},{0,-1},{0,1}}; // 위:1, 아래:2, 왼쪽:3, 오른쪽:4
vector<int> shark[405][5]; // 우선순위
vector<int> smell[22][22];  // 냄새, 0: 상어 번호, 1: 냄새가 있는 초
vector<pair<int,int>> sharkPos; // 상어 위치

void moveShark() {

    while(1) {

        // 1000 초가 넘어가면 -1로 종료한다.
        if(answer > 1000) {
            answer = -1;
            break;
        }

        // 상어가 한마리만 남은 경우(1만남은경우) 탈출
        if(sharkPos.size() == 1) {
            break;
        }

        int moveMap[22][22] = {0,};

        vector<pair<int,int>> newPos;
        vector<int> newSmell[22][22];
        // 냄새처리는 여기서 함
        for(int i = 0 ; i < N; i++) {
            for(int j = 0 ; j < N; j++) {
                if(smell[i][j].size() == 0) continue;
                // 사라지는 냄새
                if(smell[i][j][1] == 1) {
                    smell[i][j].clear();
                } else {
                    smell[i][j][1] = smell[i][j][1]-1;
                }
                newSmell[i][j] = smell[i][j];
            }
        }
        // 상어 냄새뿌리기 & 이동
        for(pair<int,int> pos : sharkPos) {

            int number = map[pos.first][pos.second];

            // 자신의 위치에 자신의 냄새를 뿌린다
            if(newSmell[pos.first][pos.second].size() > 0) {
                newSmell[pos.first][pos.second].clear();
            }
            newSmell[pos.first][pos.second].push_back(number); // 상어 번호
            newSmell[pos.first][pos.second].push_back(k);  // 남은 초

            // 이동할 방향을 설정한다.
            int nX = pos.first, nY = pos.second;

            // 동일한 조건이라면 => 우선순위 먼저
            // 인접한 칸 중 아무 냄새가 "없는" 칸의 방향을 선택
            // 그런 칸이 없으면 "자신의 냄새"가 있는 칸의 방향으로

            int nextPos, changePos; // 다음 방향
            for(int i = 0; i < 4; i++) {
                nextPos = shark[number][nowPos[number]][i];
                // 갈 수 있는 경우
                if(0 > pos.first+position[nextPos][0] || pos.first+position[nextPos][0] >= N || 0 > pos.second+position[nextPos][1] || pos.second+position[nextPos][1] >= N) continue;
                if(smell[pos.first+position[nextPos][0]][pos.second+position[nextPos][1]].size() == 0 || smell[pos.first+position[nextPos][0]][pos.second+position[nextPos][1]][0] == number) {

                    // 자신의 냄새인 경우는 우선순위 탐색
                    if(smell[pos.first+position[nextPos][0]][pos.second+position[nextPos][1]].size() > 0
                        && smell[pos.first+position[nextPos][0]][pos.second+position[nextPos][1]][0] == number
                        && !(nX == pos.first && nY == pos.second)) continue;

                    // 다음위치 설정
                    nX = pos.first + position[nextPos][0]; nY = pos.second + position[nextPos][1];
                    changePos = nextPos;
                    // 빈칸인 경우 바로 탈출
                    if(smell[nX][nY].size() == 0) {
                        break;
                    }

                }
            }

            // 진행방향 바꿔줌
            nowPos[number] = changePos;
            // 이동하는데, 이미 상어가 있다면 작은애만 살아남는다.
            if(moveMap[nX][nY] == 0 || moveMap[nX][nY] > number) {
                if(moveMap[nX][nY] == 0) {
                    newPos.push_back({nX, nY});
                }
                moveMap[nX][nY] = number;
            }

        }

        // 초cnt를 올린다.
        answer++;

        // 상어위치 교체
        sharkPos = newPos;
        // map정보 교체
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                map[i][j] = moveMap[i][j];
                smell[i][j] = newSmell[i][j];
            }
        }

    }



}

int main() {

    // (2 ≤ N ≤ 20, 2 ≤ M ≤ N2, 1 ≤ k ≤ 1,000)
    cin >> N >> M >> k;
    // 상어 위치
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> map[i][j];
            if(map[i][j] != 0) {
                sharkPos.push_back({i,j});
            }
        }
    }

    // 현재 상어들의 방향
    for(int i = 1; i <= M; i++) {
        cin >> nowPos[i];
    }

    // 상어 우선순위 방향
    for(int i = 1; i <= M; i++) {
        // 우선순위 순서: 위, 아래, 왼쪽, 오른쪽
        for(int j = 1; j <= 4; j++) {
            int a1, a2, a3, a4;

            cin >> a1 >> a2 >> a3 >> a4;

            vector<int> nums;
            nums.push_back(a1);
            nums.push_back(a2);
            nums.push_back(a3);
            nums.push_back(a4);

            shark[i][j] = nums;
        }

    }

    moveShark();
    cout << answer << endl;

    return 0;
}