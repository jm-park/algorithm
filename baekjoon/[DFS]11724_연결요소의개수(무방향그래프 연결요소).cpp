#include <cstdio>
#include <cstring>

using namespace std;

int vertex, edge;
int graph[1005][1005], visited[1005];

void dfs(int idx) {

    if(visited[idx] != 0)
        return;

    visited[idx] = 1;

    for(int i=1; i<=vertex; i++){
        if(graph[idx][i]){
            dfs(i);
        }
    }
}

int main() {
    int cnt = 0;

    scanf("%d %d", &vertex, &edge);

    for(int i=0; i<edge; i++){
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        graph[v1][v2] = graph[v2][v1] = 1;
    }

    for(int i=1; i<=vertex; i++) {

        if(!visited[i]){ // 모든 꼭지점(vertex)을 방문할 때까지 진행함.
            dfs(i);
            cnt++;  // 하나의 연결요소 탐색 완료
        }
    }

    printf("%d\n", cnt);


    return 0;
}