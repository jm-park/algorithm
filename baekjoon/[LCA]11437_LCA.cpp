/**
 * [ LCA(Lowest Common Ancestor): 최소 공통 조상 ]
 * 문제: 11437 LCA
 *
 * https://www.acmicpc.net/problem/11437
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

#define MAX_SIZE 50001
#define MAX_H 100

int N, M, height, depth[MAX_SIZE], visit[MAX_SIZE];
int treeAnc[MAX_SIZE][MAX_H];
vector<int> edges[MAX_SIZE];

void dfs(int n, int dep) {

    // 현재 노드에 대한 방문 완료 처리
    visit[n] = 1;
    // 현재 노드의 tree depth 를 저장
    depth[n] = dep;

    for(int vertex : edges[n]) {
        // 이미 방문한 경우는 PASS
        if(visit[vertex] == 1) continue;

        // 바로 위 조상 = 즉, 부모 를 n 으로 설정
        treeAnc[vertex][0] = n;

        dfs(vertex, dep+1);
    }
}

void dp() {
    // y: 숫자가 커질수록 root조상에 가까워짐
    for(int y = 1; y < height; y++) {

        // X: 각 노드
        for(int x = 1; x <= N; x++)  {
            treeAnc[x][y] = treeAnc[treeAnc[x][y-1]][y-1];
        }

    }
}

int lca(int a, int b) {

    // 1. 두 노드의 level이 다르다면 맞춰준다.
    if(depth[a] != depth[b]) {
        // a가 더 상위 level이 되도록 설정
        if(depth[a] > depth[b]) swap(a, b);

        /**
         * Level 맞추기
         *
         * [Shift 연산]
         * 2의 n승 의 곱,나눗셈을 빠르게 수행
         * cf) https://hahahia.tistory.com/115
         */
        for(int h = height-1; h >= 0; h--) {

            // b의 레벨과 a레벨의 차이가 2^h 크거나 같은 경우 (즉.. 레벨차이 발생하는 경우)
            if(depth[b] - depth[a] >= (1 << h)) {

                b = treeAnc[b][h];
            }
        }
    }

    // 2. 레벨이 동일한 상태에서, 두 값이 같은지 확인
    if(a == b) return a;

    // 3. 레벨이 동일한데, 값이 다른 경우는 위로 올라가면서 다른 조상을 찾아야함
    for(int h = height-1; h >= 0; h--) {
        if(treeAnc[a][h] != treeAnc[b][h]) {
            a = treeAnc[a][h];
            b = treeAnc[b][h];
        }
    }

    return treeAnc[a][0];
}

int main() {

    int a, b;

    cin >> N; // 노드 개수
    for(int i = 0; i < N-1; i++) {
        // 연결된 두 정점
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    height = ceil(log2(N+1))+1;

    /**
     * [ DFS 활용 ]
     * 1. 바로 위 부모 찾기.
     * 2. 해당 노드의 tree depth 찾기.
     */
    dfs(1, 0);

    /**
     * [ 동적계획법 활용 ]
     * 각 노드에 연결된 모든 조상노드를 treeAnc 배열에 저장
     */
    dp();


    cin >> M; // 가장 가까운 공통 조상을 알고싶은 쌍의 개수
    for(int i = 0; i < M; i++) {
        cin >> a >> b;

        /**
         * LCA 알고리즘 수행
         */
        cout << lca(a, b) << "\n";
    }

    return 0;
}