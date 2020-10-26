/**
 * [ 구현 WITH SORT ]
 * 문제: 17140 이차원배열과연산
 *
 * https://www.acmicpc.net/problem/17140
 *
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int answer = -1, r, c, k, A[101][101], maxRCnt=3, maxCCnt=3;


void sortByR() {

    for(int i = 1; i <= maxRCnt; i++) {

        int maxNum = -1, num[101] = {0, };
        vector<vector<int>> sortNum;

        for(int j = 1; j <= maxCCnt; j++) {
            if(A[i][j] == 0) continue;
            num[A[i][j]]++;
            maxNum = max(maxNum, A[i][j]);
        }

        for(int n = 1; n <= maxNum; n++) {
            if(num[n] == 0) continue;
            sortNum.push_back({n, num[n]});
        }

        /**
         * SORT 중요함!!
         * 꼭 확인할 것!
         */
        sort(sortNum.begin(), sortNum.end(), [](const vector<int>& x, const vector<int>& y) {
            // 2번째값 기준으로 오름차순!!
            // 2번째값이 같다면, 첫번째값 기준으로 오름차순
            if(x[1] == y[1]) {
                return x[0] < y[0]; // 첫번째 값 기준으로 오름차순 정렬한다.
            } else {
                return x[1] < y[1]; // 두번째 값 기준으로 오름차순 정렬한다.
            }
        });

        int idx = 0;
        for(vector<int> value : sortNum) {
            A[i][++idx] = value[0];
            A[i][++idx] = value[1];
        }

        // 최대 row 계산
        maxCCnt = max(maxCCnt, idx);

        for(idx+=1; idx <= 100;idx++) {
            A[i][idx] = 0;
        }
    }
}

void sortByC() {

    for(int i = 1; i <= maxCCnt; i++) {

        int maxNum = -1, num[101] = {0, };
        vector<vector<int>> sortNum;

        for(int j = 1; j <= maxRCnt; j++) {
            if(A[j][i] == 0) continue;
            num[A[j][i]]++;
            maxNum = max(maxNum, A[j][i]);
        }

        for(int n = 1; n <= maxNum; n++) {
            if(num[n] == 0) continue;
            sortNum.push_back({n, num[n]});
        }

        sort(sortNum.begin(), sortNum.end(), [](const vector<int>& x, const vector<int>& y) {
            // 오름차순 (2번째값)
            // 2번째값이 같다면, 첫번째값 기준으로 오름차순
            if(x[1] == y[1]) {
                return x[0] < y[0];
            } else {
                return x[1] < y[1];
            }
        });

        int idx = 0;
        for(vector<int> value : sortNum) {
            A[++idx][i] = value[0];
            A[++idx][i] = value[1];
        }
        // 열의 최대 개수
        maxRCnt = max(maxRCnt, idx);

        for(idx+=1; idx <= 100;idx++) {
            A[idx][i] = 0;
        }
    }
}
int main() {

    // (1 ≤ r, c, k ≤ 100)
    cin >> r >> c >> k;

    for(int i = 1; i <= 3; i ++) {
        for(int j = 1; j <=3; j++) {
            cin >> A[i][j];
        }
    }

    int cnt = 0;
    while(1) {

        if(A[r][c] == k) {
            answer = cnt;
            break;
        }
        if(cnt >= 100) {
            break;
        }



        if(maxRCnt >= maxCCnt) {
            cnt++;
            sortByR();
        }

        if(A[r][c] == k) {
            answer = cnt;
            break;
        }
        if(cnt >= 100) {
            break;
        }


        if(maxRCnt < maxCCnt) {
            cnt++;
            sortByC();
        }

    }

    // A[r][c]에 들어있는 값이 k가 되기 위한 연산의 최소 시간
    // 100초가 지나도 A[r][c] = k가 되지 않으면 -1을 출력
    cout << answer << endl;

    return 0;
}