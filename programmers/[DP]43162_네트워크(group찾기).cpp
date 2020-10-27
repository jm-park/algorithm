/**
 * [ DFS ]
 * 문제: 43162 네트워크
 *
 * https://programmers.co.kr/learn/courses/30/lessons/43162
 *
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int visit[200][200];

void dfs(int x, int n, vector<vector<int>> computers) {

    for(int nY = 0; nY < n; nY++) {
        // 방문전 && 경로가 존재하는 경우
        if(visit[x][nY] == 0 && computers[x][nY] > 0) {
            visit[x][nY] = visit[nY][x] = 1;
            dfs(nY, n, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for(int x = 0; x < n; x++) {
        for(int y = 0; y < n; y++) {
            // 결국 모든 경로에 대해 visit 처리가 완료되는 순간 종료됨.
            if(visit[x][y] == 0 && computers[x][y] != 0) {

                // 무방향 그래프이기 때문에 x->y & y->x 방문처리 해줌
                visit[x][y] = visit[y][x] = 1;

                // 연결된 경로를 다 탐색한 경우 DFS종료
                dfs(x,n, computers);

                answer++;
            }
        }
    }
    return answer;
}

int main() {

    vector<vector<int>> input;
    vector<int> info;

    info.push_back(1);
    info.push_back(0);
    info.push_back(0);
    info.push_back(1);
    input.push_back(info);
    info.clear();

    info.push_back(0);
    info.push_back(1);
    info.push_back(1);
    info.push_back(1);
    input.push_back(info);
    info.clear();

    info.push_back(0);
    info.push_back(1);
    info.push_back(1);
    info.push_back(0);
    input.push_back(info);
    info.clear();

    info.push_back(1);
    info.push_back(1);
    info.push_back(0);
    info.push_back(1);
    input.push_back(info);
    info.clear();
//
//    info.push_back(4);
//    info.push_back(5);
//    info.push_back(2);
//    info.push_back(6);
//    info.push_back(5);
//    input.push_back(info);
//    info.clear();

    cout << "RESULT: " << solution(4, input) << endl;

    return 0;
}