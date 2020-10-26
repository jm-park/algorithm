#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int map[105][105], dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};
bool visited[105][105];
queue<pair<int,int>> path;

void searchMap(int x, int y) {

    path.push(make_pair(x,y));
    visited[x][y] = true;

    while(!path.empty()) {

        int now_x = path.front().first, now_y = path.front().second;

        path.pop();

        for(int i=0; i<4; i++){
            if(!visited[now_x+dx[i]][now_y+dy[i]] && map[now_x+dx[i]][now_y+dy[i]]!=0) {
                map[now_x+dx[i]][now_y+dy[i]] = map[now_x][now_y]+1;
                path.push(make_pair(now_x+dx[i],now_y+dy[i]));
                visited[now_x+dx[i]][now_y+dy[i]] = true;  // 큐에 넣는 순간 바로 체크: 메모리 초과를 피하기 위함
            }
        }

    }
}

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    for(int i=1; i<=n; i++) {
        getchar();
        for(int j=1; j<=m; j++) {
            char tmp;
            scanf("%c", &tmp);
            map[i][j]= tmp-'0';
        }
    }

    searchMap(1,1);
    printf("%d\n", map[n][m]);

    return 0;
}