/**
 * [ LCA(Lowest Common Ancestor) ]
 * 문제: 11438 LCA 2
 *
 * https://www.acmicpc.net/problem/11438
 *
 * cf) 최소 공통 조상을 찾는 알고리즘 (LCA)
 * https://matice.tistory.com/55
 *
 * https://jason9319.tistory.com/90
 *
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

#define MAX_SIZE 100001
#define MAX_H 21
using namespace std;

int N, M;
int depth[MAX_SIZE], visit[MAX_SIZE];
int treeAnc[MAX_SIZE][MAX_H];
vector<int> edges[MAX_SIZE];


void dfs(int n, int dep) {

    visit[n] = 1;
    depth[n] = dep;

    for(int next : edges[n]) {
        if(visit[next] == 1) continue;

        // 자손의 조상을 자신으로 설정
        treeAnc[next][0] = n;
        dfs(next, dep+1);
    }
}

void dp() {
    for(int y = 1; y < MAX_H; y++) {
        for(int x = 1; x <= N; x++) {
//            if(treeAnc[x][y] != 0) => 삭제해야함
                treeAnc[x][y] = treeAnc[treeAnc[x][y-1]][y-1];
        }
    }
}

int lca(int a, int b) {

    // Level이 다른 경우, 맞춰준다.
    if(depth[a] != depth[b]) {

        // a가 더 low level인 경우
        if(depth[a] > depth[b]) {
            swap(a,b); // a 가 더 높은 level의 node로 변경 (a, b값 변경)
        }

        for(int i = MAX_H-1; i >= 0; i--) {

            /**
             * [Shift 연산]
             * 2의 n승 의 곱,나눗셈을 빠르게 수행
             * cf) https://hahahia.tistory.com/115
             */
            if(depth[b] - depth[a] >= (1 << i)) {
                b = treeAnc[b][i];
            }
        }
    }

    // 조상이 같아지는 경우, END
    if(a == b) return a;

    if(a != b) {
        for(int i = MAX_H-1; i >= 0; i--) {
            if(treeAnc[a][i] != treeAnc[b][i]) {
                a = treeAnc[a][i];
                b = treeAnc[b][i];
            }
        }
    }

    return treeAnc[a][0];
}

int main() {

    vector<int> answer;

    // N(2 ≤ N ≤ 100,000)개의 정점
    scanf("%d", &N);

    /**
     * N+1해줘야함!!!!!!!!!!
     * MAX_H: 이진트리 최소 높이인 log2N 값은 약 16.8
     */
//    MAX_H = (int) floor(log2(N+1));

    for(int i = 0; i < N-1; i++) {
        // 트리 상에서 연결된 두 정점
        int a, b;
        scanf("%d %d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    /**
     * [부모 찾기]
     * 현 노드의 부모를 2차원 배열 idx = 0에 저장한다.
     */
    dfs(1,0);

    /**
     * [조상 찾기]
     * 0,1.. 2차원배열의 idx가 클 수록 최상위 root를 바라보게됨
     */
    dp();

    // 두 노드의 쌍 M(1 ≤ M ≤ 100,000)
    scanf("%d", &M);

    for(int i = 0; i < M; i++) {
        // 정점 쌍
        int a, b;
        scanf("%d %d", &a, &b);

        /**
         * [LCA 알고리즘]
         * 두 node의 level을 비교하며, 최단거리의 조상을 찾는다.
         */
        answer.push_back(lca(a,b));
//        printf("%d\n", lca(a,b));
    }

    for(int ans : answer) {
        printf("%d\n", ans);
    }
    return 0;
}