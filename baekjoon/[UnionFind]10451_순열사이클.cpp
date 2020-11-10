/**
 * [ Union-Find ]
 * 문제: 10451 순열 사이클
 *
 * https://www.acmicpc.net/problem/10451
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, parent[1001];

void mergeGroup(int x, int y) {
    // 더 작은 쪽의 root값으로 사이클을 합쳐준다.
    if(x < y) {
        parent[y] = x;
    } else {
        parent[x] = y;
    }
}

int findRoot(int n) {
    if(n == parent[n]) {
        return n;
    } else {
        return findRoot(parent[n]);
    }
}

int main() {

    int T;
    cin >> T;

    vector<int> answer;

    while(T--) {
        vector<pair<int,int>> edges;

        // 순열의 크기 N (2 ≤ N ≤ 1,000)
        cin >> N;

        for(int i = 1; i <= N; i++) {
            int j;
            cin >> j;
            edges.push_back({i, j});

            // root 배열 초기화
            parent[i] = i;
        }

        for(pair<int,int> pos: edges) {

            int root1 = findRoot(pos.first);
            int root2 = findRoot(pos.second);

            if(root1 != root2) {
                mergeGroup(root1, root2);
            }

        }

        // 갯수 찾기
        int cnt = 0, visit[1001] = {0, };
        for(int i = 1; i <= N; i++) {
            int root = findRoot(parent[i]);
            if(visit[root] == 0) {
                visit[root] = 1;
                cnt++;
            }
        }
        answer.push_back(cnt);
    }

    // 사이클 갯수
    for(int ans : answer) {
        cout << ans << endl;
    }

    return 0;
}