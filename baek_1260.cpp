#include <cstdio>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[1001];
bool isVisited[1001];

void dfs(int location) {
    if(isVisited[location] == true)
        return;
    
    printf("%d ", location);
    isVisited[location] = true;
    
    for(int i=0; i<graph[location].size(); i++) {
        dfs(graph[location][i]);
    }
    
}

void bfs(int start) {
    queue<int> dfsValue;
    
    dfsValue.push(start);
    
    while(!dfsValue.empty()) {
        int tmp = dfsValue.front();
        
        printf("%d ", tmp);
        dfsValue.pop();
        isVisited[tmp] = true;
        
        for(int i=0; i< graph[tmp].size(); i++){
            if(isVisited[graph[tmp][i]] == false) {
                dfsValue.push(graph[tmp][i]);
                isVisited[graph[tmp][i]] = true;
            }
        }
    }
    
}

int main() {
    int e, v, start_point; // e: edge(간선), v: vertex(정점), start_point: 시작점
    int start_v, end_v;
    
    scanf("%d %d %d", &v, &e, &start_point);
    
    for(int i=0; i<e; i++) {
        scanf("%d %d", &start_v, &end_v);
        graph[start_v].push_back(end_v);
        graph[end_v].push_back(start_v);
    }
    
    for(int i=0; i<v; i++){
        sort(graph[i].begin(), graph[i].end());
    }
    
    fill(isVisited, isVisited+1001, false);
    dfs(start_point);
    printf("\n");
    fill(isVisited, isVisited+1001, false);
    bfs(start_point);
    printf("\n");
    
    return 0;
}
