#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

vector<int> ans;
int n, apartment[30][30], dx[]={1,-1,0,0}, dy[]={0,0,1,-1};
bool visited[30][30];

void bfs() {
    queue<pair<int,int>> que;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) {
            if(!visited[i][j] && apartment[i][j] == 1) {
                que.push(make_pair(i,j));

                int house_cnt = 1;

                while(!que.empty()) {
                    visited[i][j]=true;
                    int now_x = que.front().first, now_y = que.front().second;
                    que.pop();

                    for(int k=0; k<4; k++){
                        int next_x = now_x+dx[k], next_y = now_y+dy[k];
                        if(next_x<1 || next_x>n || next_y<1 || next_y>n) continue;

                        if(!visited[next_x][next_y] && apartment[next_x][next_y] != 0){
                            que.push(make_pair(next_x,next_y));
                            visited[next_x][next_y]=true;
                            house_cnt++;
                        }
                    }
                }

                ans.push_back(house_cnt);
            }

        }
    }
}

int main() {
    scanf("%d", &n);

    for(int i=1; i<=n; i++) {
        getchar();
        for(int j=1; j<=n; j++){
            char tmp;
            scanf("%c", &tmp);
            apartment[i][j] = tmp-'0';
        }
    }

    bfs();

    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for(auto val: ans)
        printf("%d\n", val);

    return 0;
}