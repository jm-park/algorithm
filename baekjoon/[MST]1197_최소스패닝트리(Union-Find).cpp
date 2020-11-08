/**
 * [ MST&Union-Find ]
 * 문제: 1197 최소 스패닝 트리
 *
 * https://www.acmicpc.net/problem/1197
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;

int V, E, answer, vertex[10001];
vector<vector<int>> edges;

void merge(int x, int y) {
    // root값이 더 작은쪽으로 합쳐줌
    if(x < y) {
        vertex[y] = x;
    } else {
        vertex[x] = y;
    }
}

int findRoot(int num) {
    // root인 경우 return
    if(vertex[num] == num) {
        return num;
    } else {
        return findRoot(vertex[num]);
    }
}

void mst() {

    // 1. 가중치가 작은 것 우선으로 선택
    for(vector<int> edge : edges) {

        // 2. 사이클 생성 여부 확인
        int root1 = findRoot(edge[0]);
        int root2 = findRoot(edge[1]);

        // 3. 사이클이 생성되지 않는다면 간선 추가
        if(root1 != root2) {
            merge(root1, root2);
            answer += edge[2];
        }
    }

}

int main() {

    // 정점의 개수 V(1 ≤ V ≤ 10,000), 간선의 개수 E(1 ≤ E ≤ 100,000)
    cin >> V >> E;

    for(int i = 0 ; i < E; i++) {
        int a, b, c;
        // A번 정점과 B번 정점이 가중치 C(C는 음수일 수도)

        cin >> a >> b >> c;

        // 0: 시작, 1: 도착, 2: 가중치
        edges.push_back({a,b,c});

    }

    // 정점의 root값을 자신으로 초기화
    for(int i = 1; i <= V; i++) {
        vertex[i] = i;
    }

    // 가중치 작은 값 기준으로 오름차순 정렬
    sort(edges.begin(), edges.end(), [] (const vector<int> &a, const vector<int> &b) {
       return a[2] < b[2];
    });

    // 최소 스패닝 트리 찾기
    mst();

    // 최소 스패닝 트리의 가중치
    cout << answer << endl;

    return 0;
}