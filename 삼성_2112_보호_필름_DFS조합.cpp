/**
 * [ DFS & 조합 ]
 * 문제: 2112 보호 필름
 *
 * https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5V1SYKAaUDFAWu
 *
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int answer, D, W, K, map[14][22], visit[14], sameCol[14];

int checkK(int afterDrug[14][22]) {

    int totalPass = 0;

    for(int j = 0 ;j < W; j++) {
        int cntA = 1, cntB = 1;
        for(int i = 1; i < D; i++) {

            if(cntA == K || cntB == K) break;

            // A
            if(afterDrug[i-1][j] == afterDrug[i][j] && afterDrug[i][j] == 0) {
                cntA += 1;
            }
                // B
            else if(afterDrug[i-1][j] == afterDrug[i][j] && afterDrug[i][j] == 1) {
                cntA += 1;
            }
            else if(afterDrug[i-1][j] != afterDrug[i][j]) {
                cntA = 1; cntB = 1;
            }

        }

        if(cntA == K || cntB == K) {
            totalPass += 1;
        } else {
            break;
        }
    }

    return totalPass == W ? 0 : -1;
}

void dfs(int cnt, int nextRow, int afterDrug[14][22]) {

    // 최소값보다 크다면 탈출
    if(cnt >= answer) {
        return;
    }

    // 성능검사 만족 체크
    int result = checkK(afterDrug);
    if(result == 0) {
        answer = min(answer, cnt);
        return;
    }

    // 어차피 다음값을 넣는 경우는 의미없음
    if(cnt +1 == answer) {
        return;
    }


    // 1. 그렇지 않다면, 약품 투입위치 구한다.
    // 1-2) 약품의 row 위치를 구한다.

    // 복사본
    int newMap[14][22] = {0,};
    for (int i = 0; i < D; i++) {
        for (int j = 0; j < W; j++) {
            newMap[i][j] = afterDrug[i][j];
        }
    }


    // 2. 약품을 투입한다. (조합)
    for (int row = nextRow; row < D; row++) {

        if (visit[row] == 1) continue;
        visit[row] = 1;

//        if(cnt+1 == answer) return;
        if(sameCol[row] == 0 || (sameCol[row] == 1 && map[row][0] == 1)) {
            // A약품
            for (int col = 0; col < W; col++) {
                newMap[row][col] = 0;
            }

//            cout << "=============="<< row+1 << "행 : " << 0 <<" 값으로 "<< cnt+1 << "번째 약물투여=============" << endl;
//            for(int i = 0; i <D; i++) {
//                for(int j = 0; j < W; j++) {
//                    cout << newMap[i][j] << " ";
//                }
//                cout << endl;
//            }
//            cout << endl;

            dfs(cnt + 1, row + 1, newMap);
        }


        if(sameCol[row] == 0 || (sameCol[row] == 1 && map[row][0] == 0)) {
            // B약품
            for (int col = 0; col < W; col++) {
                newMap[row][col] = 1;
            }

//        cout << "=============="<< row+1 << "행 : " << 1 <<" 값으로 "<< cnt+1 << "번째 약물투여=============" << endl;
//        for(int i = 0; i <D; i++) {
//            for(int j = 0; j < W; j++) {
//                cout << newMap[i][j] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;

            dfs(cnt + 1, row + 1, newMap);
        }

        // 약물 투여 취소
        visit[row] = 0;

//            cout << row+1 << "행 원복!" << endl;
        for (int col = 0; col < W; col++) {
            newMap[row][col] = map[row][col];
        }

    }

}

int main(int argc, char** argv) {
    int test_case;
    int T;

    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case){


        // 보호 필름의 두께 D, 가로크기 W, 합격기준 K
        cin >> D >> W >> K;

        answer = K;

        // 특성A는 0, 특성B는 1
        for(int i = 0; i < D; i++) {
            visit[i] = 0;
            int cnt = 1;
            for(int j = 0; j < W; j++) {
                cin >> map[i][j];
                if(j > 0 && map[i][j] == map[i][j-1]) {
                    cnt++;
                }
            }
            if(cnt == W) {
                sameCol[i] = 1;
            } else {
                sameCol[i] = 0;
            }
        }

        // 약품 type
//        for(int type = 0; type < 2; type++) {
        dfs(0, 0, map);
//        }

        // 약품 투입 횟수를 최소로 하여 성능검사를 통과할 수 있는 방법
        cout << "#" << test_case << " " << answer << endl;
    }
    return 0;
}