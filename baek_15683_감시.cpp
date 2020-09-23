#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <ctime>

using namespace std;

/**
 * [ DFS ]
 * 문제: 15683 감시
 *
 * https://www.acmicpc.net/problem/15683
 *
 * @return
 */
int N, M, answer = 987654321;
int map[10][10], area[10][10];  // 우, 좌, 아래, 위
vector<vector<int>> cctv;

void sortByCCTV() {
    // CCTV 번호 기준으로 오름차순 정렬
    sort(cctv.begin(), cctv.end(),
         [](const vector<int> &a, const vector<int> &b) {
             return a[0] < b[0];
         });
}

void ckArea(int x, int y, int val, int posX, int posY) {

    while (posX + x >= 0 && posX + x < N && posY + y >= 0 && posY + y < M && map[posX][posY] != 6) {
        area[posX + x][posY + y] += val;
        posX = posX + x; posY = posY + y;
    }
}

void dfs(int cnt) {
    // 사이즈 체크
    if (cnt >= cctv.size()) {
//        cout << "\n\n=======??? =======" << endl;

        int cntValue = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (area[i][j] == 0) {
                    cntValue++;
                }
//                cout << area[i][j] <<  " ";
            }
//            cout << endl;
        }
        answer = min(answer, cntValue);
//        cout << "count: "  << answer<<endl;
        return;
    }
    vector<int> cctvInfo = cctv[cnt];
    if (cctvInfo[0] == 1) {
        ckArea(1, 0, 1, cctvInfo[1], cctvInfo[2]);    // 우
        dfs(cnt + 1);
        ckArea(1, 0, -1, cctvInfo[1], cctvInfo[2]);    // 우(원상복귀)

        ckArea(-1, 0, 1, cctvInfo[1], cctvInfo[2]);    // 좌
        dfs(cnt + 1);
        ckArea(-1, 0, -1, cctvInfo[1], cctvInfo[2]);    // 좌(원상복귀)

        ckArea(0, 1, 1, cctvInfo[1], cctvInfo[2]);    // 아래
        dfs(cnt + 1);
        ckArea(0, 1, -1, cctvInfo[1], cctvInfo[2]);    // 아래(원상복귀)

        ckArea(0, -1, 1, cctvInfo[1], cctvInfo[2]);    // 위
        dfs(cnt + 1);
        ckArea(0, -1, -1, cctvInfo[1], cctvInfo[2]);    // 위(원상복귀)
        return;
    } else if (cctvInfo[0] == 2) {
        ckArea(1, 0, 1, cctvInfo[1], cctvInfo[2]);    // 우
        ckArea(-1, 0, 1, cctvInfo[1], cctvInfo[2]);    // 좌
        dfs(cnt + 1);
        ckArea(1, 0, -1, cctvInfo[1], cctvInfo[2]);    // 우(원상복귀)
        ckArea(-1, 0, -1, cctvInfo[1], cctvInfo[2]);    // 우(원상복귀)

        ckArea(0, 1, 1, cctvInfo[1], cctvInfo[2]);    // 아래
        ckArea(0, -1, 1, cctvInfo[1], cctvInfo[2]);    // 위
        dfs(cnt + 1);
        ckArea(0, -1, -1, cctvInfo[1], cctvInfo[2]);    // 아래(원상복귀)
        ckArea(0, 1, -1, cctvInfo[1], cctvInfo[2]);    // 위(원상복귀)
        return;
    } else if (cctvInfo[0] == 3) {
        ckArea(1, 0, 1, cctvInfo[1], cctvInfo[2]);    // 아래
        ckArea(0, 1, 1, cctvInfo[1], cctvInfo[2]);    // 우
        dfs(cnt + 1);
        ckArea(1, 0, -1, cctvInfo[1], cctvInfo[2]);    // 우(원상복귀)
        ckArea(0, 1, -1, cctvInfo[1], cctvInfo[2]);    // 아래(원상복귀)

        ckArea(1, 0, 1, cctvInfo[1], cctvInfo[2]);    // 아래
        ckArea(0, -1, 1, cctvInfo[1], cctvInfo[2]);    // 좌
        dfs(cnt + 1);
        ckArea(1, 0, -1, cctvInfo[1], cctvInfo[2]);    // 우(원상복귀)
        ckArea(0, -1, -1, cctvInfo[1], cctvInfo[2]);    // 위(원상복귀)

        ckArea(0, 1, 1, cctvInfo[1], cctvInfo[2]);    // 우
        ckArea(-1, 0, 1, cctvInfo[1], cctvInfo[2]);    // 위
        dfs(cnt + 1);
        ckArea(0, 1, -1, cctvInfo[1], cctvInfo[2]);    // 아래(원상복귀)
        ckArea(-1, 0, -1, cctvInfo[1], cctvInfo[2]);    // 좌(원상복귀)

        ckArea(-1, 0, 1, cctvInfo[1], cctvInfo[2]);    // 위
        ckArea(0, -1, 1, cctvInfo[1], cctvInfo[2]);    // 좌
        dfs(cnt + 1);
        ckArea(-1, 0, -1, cctvInfo[1], cctvInfo[2]);    // 위(원상복귀)
        ckArea(0, -1, -1, cctvInfo[1], cctvInfo[2]);    // 좌(원상복귀)
        return;
    } else if (cctvInfo[0] == 4) {
        ckArea(1, 0, 1, cctvInfo[1], cctvInfo[2]);    // 우
        ckArea(-1, 0, 1, cctvInfo[1], cctvInfo[2]);    // 좌
        ckArea(0, 1, 1, cctvInfo[1], cctvInfo[2]);    // 아래
        dfs(cnt + 1);
        ckArea(1, 0, -1, cctvInfo[1], cctvInfo[2]);    // 좌(원상복귀)
        ckArea(-1, 0, -1, cctvInfo[1], cctvInfo[2]);    // 우(원상복귀)
        ckArea(0, 1, -1, cctvInfo[1], cctvInfo[2]);    // 아래(원상복귀)

        ckArea(1, 0, 1, cctvInfo[1], cctvInfo[2]);    // 우
        ckArea(-1, 0, 1, cctvInfo[1], cctvInfo[2]);    // 좌
        ckArea(0, -1, 1, cctvInfo[1], cctvInfo[2]);    // 위
        dfs(cnt + 1);
        ckArea(1, 0, -1, cctvInfo[1], cctvInfo[2]);    // 좌(원상복귀)
        ckArea(-1, 0, -1, cctvInfo[1], cctvInfo[2]);    // 우(원상복귀)
        ckArea(0, -1, -1, cctvInfo[1], cctvInfo[2]);    // 위(원상복귀)

        ckArea(-1, 0, 1, cctvInfo[1], cctvInfo[2]);    // 좌
        ckArea(0, 1, 1, cctvInfo[1], cctvInfo[2]);    // 아래
        ckArea(0, -1, 1, cctvInfo[1], cctvInfo[2]);    // 위
        dfs(cnt + 1);
        ckArea(-1, 0, -1, cctvInfo[1], cctvInfo[2]);    // 좌(원상복귀)
        ckArea(0, 1, -1, cctvInfo[1], cctvInfo[2]);    // 위(원상복귀)
        ckArea(0, -1, -1, cctvInfo[1], cctvInfo[2]);    // 아래(원상복귀)

        ckArea(1, 0, 1, cctvInfo[1], cctvInfo[2]);    // 우
        ckArea(0, 1, 1, cctvInfo[1], cctvInfo[2]);    // 아래
        ckArea(0, -1, 1, cctvInfo[1], cctvInfo[2]);    // 위
        dfs(cnt + 1);
        ckArea(1, 0, -1, cctvInfo[1], cctvInfo[2]);    // 우(원상복귀)
        ckArea(0, 1, -1, cctvInfo[1], cctvInfo[2]);    // 위(원상복귀)
        ckArea(0, -1, -1, cctvInfo[1], cctvInfo[2]);    // 아래(원상복귀)
        return;
    } else if(cctvInfo[0] == 5) {
        ckArea(1, 0, 1, cctvInfo[1], cctvInfo[2]);    // 우
        ckArea(-1, 0, 1, cctvInfo[1], cctvInfo[2]);    // 좌
        ckArea(0, 1, 1, cctvInfo[1], cctvInfo[2]);    // 아래
        ckArea(0, -1, 1, cctvInfo[1], cctvInfo[2]);    // 위
        dfs(cnt + 1);
        return;
    }

}

int main() {

    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];

            if (map[i][j] >= 1 && map[i][j] <= 5) {
                cctv.push_back({map[i][j], i, j});    // 첫번째: cctv정보, 두번째: x좌표, 세번째: y좌표
                area[i][j] = 9;
            } else if(map[i][j] == 6) {
                area[i][j] = 6;
            }
        }
    }

    dfs(0);
    cout << answer;
}