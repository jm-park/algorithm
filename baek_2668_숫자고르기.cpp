#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <ctime>

using namespace std;

/**
 * [ DFS ]
 * 문제: 2668 숫자고르기
 *
 * https://www.acmicpc.net/problem/2668
 *
 * @return
 */
int N;
int number[105], visit[105];
vector<int> answer;

void dfs(int startValue, int endValue) {

    if(visit[endValue] != 0) {
        if(startValue == endValue) {
            answer.push_back(startValue);
        }
    } else {
        visit[endValue] += 1;
        dfs(startValue, number[endValue]);
    }
}

int main() {

    scanf("%d", &N);
    for(int x = 1; x <= N; x++) {
        cin >> number[x];
    }

    for(int i = 1 ; i <= N; i++) {
        dfs(i,i);
        for(int j = 1; j <=N; j++) {
            visit[j] = 0;
        }
    }

    // 답 출력
//    cout << "\n==========답==========" << endl;
    cout << answer.size() << endl;
    for(int num : answer) {
        cout << num << endl;
    }
}
// 1 2 3 4 5 6 7
// 4 3 5 7 2 1 6
