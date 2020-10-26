#include <cstdio>
#include <cstring> // memset함수 헤더파일

using namespace std;

int N;
int visited[105], graph[105][105];  // 양방향이므로 visited는 1차원 배열 사용

void dfs(int idx) {

    for(int i=0; i<N; i++) {
        if(!visited[i] && graph[idx][i]) {
            visited[i] = 1;
            dfs(i);
        }
    }
}

int main() {

    // case input
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // DFS 풀이
    for(int i=0; i<N; i++) {
        memset(visited, 0, sizeof(visited));    // 방문여부 체크 배열 초기화 작업 필요
        dfs(i);

        for(int j=0; j<N; j++){
            if(visited[j])
                graph[i][j] = 1;
        }
    }

    // 답안 출력
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}