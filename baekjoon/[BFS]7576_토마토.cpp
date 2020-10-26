#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int n, m, turned_tomatos, days, box[1005][1005], dx[]={1,-1,0,0}, dy[]={0,0,1,-1};
bool visited[1005][1005];
queue<pair<int,int>> que;

int bfs(){
    int ans = 0;

    while(!que.empty()) {
        bool isSearched = false;
        int now_x=que.front().first, now_y=que.front().second;
        visited[now_x][now_y] = true;
        que.pop();
        ans = max(ans, days);
        days = box[now_x][now_y]+1;

        for(int i=0; i<4; i++) {
            if(now_x+dx[i]<1 || now_x+dx[i]>m || now_y+dy[i]<1 || now_y+dy[i]>n) continue;

            if(!visited[now_x+dx[i]][now_y+dy[i]] && box[now_x+dx[i]][now_y+dy[i]] == 0){
                isSearched = true;
                turned_tomatos++;
                que.push(make_pair(now_x+dx[i], now_y+dy[i]));
                box[now_x+dx[i]][now_y+dy[i]] = days;
            }
        }
        if(!isSearched) days--; // 상하좌우로 가지 못한 경우 days카운트를 줄여준다.
    }

    return ans;
}

int main() {
    int total_tomatos=0;

    scanf("%d %d", &n, &m);

    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            scanf("%d", &box[i][j]);
            if(box[i][j] == 0) total_tomatos++;
            else if(box[i][j] == 1)
                que.push(make_pair(i, j));
        }
    }


    if(total_tomatos == 0){
        printf("0\n");
        return 0;
    }

    total_tomatos += que.size();
    turned_tomatos += que.size();
    int ans = bfs()-1;

    if(total_tomatos != turned_tomatos){
        printf("-1\n");
        return 0;
    }

    printf("%d\n", ans);

    return 0;
}