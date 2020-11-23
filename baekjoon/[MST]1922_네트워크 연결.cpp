/**
 * [ MST(크루스칼&unionFind) ]
 * 문제: 1922 네트워크 연결
 *
 * https://www.acmicpc.net/problem/1922
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

#define MAX_SIZE 1005

using namespace std;

int N, M, answer;
vector<vector<int>> cost; // 0: 비용, 1&2: 연결지점
int parent[MAX_SIZE]; // root


int findRoot(int n) {
    if(n == parent[n]) {
        return n;
    } else {
        return parent[n] = findRoot(parent[n]);
    }
}

void mergeRoot(int x, int y) {
    if(x < y) {
        parent[y] = x;
    } else {
        parent[x] = y;
    }
}

void mst() {

    for(vector<int> info: cost) {

        // cycle이 생성되는지 확인
        int root1 = findRoot(info[1]);
        int root2 = findRoot(info[2]);

        // 생성되지 않는다면, 연결
        if(root1 != root2) {
            answer += info[0];
            mergeRoot(root1, root2);
        }
    }

}

int main() {

    // 컴퓨터의 수 N (1 ≤ N ≤ 1000)
    // 연결할 수 있는 선의 수 M (1 ≤ M ≤ 100,000)
    scanf("%d %d", &N, &M);

    // 각 컴퓨터를 연결하는데 드는 비용 => c (1 ≤ c ≤ 10,000)
    int a, b, c;
    for(int i = 0; i < M; i++) {
        scanf("%d %d %d", &a, &b, &c);
        // cf) a = b 가능
        if(a == b) continue;
        cost.push_back({c, a, b});
    }

    // cost 기준으로, 오름차순 정렬
    sort(cost.begin(), cost.end(), [](const vector<int> & a, const vector<int> & b) {
       return a[0] < b[0];
    });

    // 배열 초기화
    for(int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    // 최소비용 찾기
    mst();

    // 모든 컴퓨터를 연결하는데 필요한 최소비용
    cout << answer << endl;

    return 0;
}