/**
 * [ 조합 & DFS ]
 * 문제: 14889 스타트와 링크
 *
 * https://www.acmicpc.net/problem/14889
 *
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, answer = 2000000000, map[22][22], member[22];

int idx = 0;
void dfs(int cnt, int nextI) {

    if(cnt == (N/2)) {
//        cout << "idx : " << ++idx << endl;

        int start = 0, link = 0;
        for(int i = 1; i <= N; i++) {
            for (int j = i+1; j <= N; j++) {

                if(member[i] == 1 && member[j] == 1) {
                    start += (map[i][j]+map[j][i]);
                } else if(member[i] == 0 && member[j] == 0){
                    link += (map[i][j]+map[j][i]);
                }
            }
        }

        int sum = start - link >= 0 ? start-link : link-start;
//        cout << "START : " << start << " / LINK: " << link << " ====> SUM : " << sum << endl;
        answer = min(answer, sum);
        return;
    }

    for(int i = nextI; i <= N; i++) {

        // 선택하는 경우
        if(member[i] == 0) {
            member[i] = 1;
            dfs(cnt+1, i+1);
            member[i] = 0;
        }

    }

}

int main() {

    // N은 짝수
    cin >> N;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> map[i][j];
        }
    }

    dfs(0,1);

    // 팀의 능력치의 차이를 최소
    cout << answer << endl;

    return 0;
}