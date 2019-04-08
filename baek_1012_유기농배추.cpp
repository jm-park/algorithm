    #include <iostream>
    #include <vector>
    #include <stack>
    #include <utility>
    using namespace std;

    int M,N,dx[]={1,-1,0,0}, dy[]={0,0,1,-1};

    // 2차원 배열 넘기기!!
    void dfs(int x, int y, int farm[][55], bool visited[][55]) {

        visited[x][y] = true;

        for(int i=0; i<4; i++) {
            int next_x = x+dx[i], next_y = y+dy[i];

            if(next_x < 0 || next_x > M-1 || next_y < 0 || next_y > N-1) continue;
            if(!visited[next_x][next_y] && farm[next_x][next_y]) dfs(next_x, next_y, farm, visited);
        }
    }

    int main() {
        int T, K;
        vector<int> ans;
        scanf("%d", &T);

        while(T--){
            scanf("%d %d %d", &M, &N, &K);
            int cnt=0, farm[55][55]={0, };
            bool visited[55][55]= {false, };

            while(K--){
                int x, y;
                scanf("%d %d", &x, &y);
                farm[x][y] = 1;
            }

            for(int i=0; i<M; i++)
                for(int j=0; j<N; j++) {
                    if(!visited[i][j] && farm[i][j]==1){
                        dfs(i,j,farm,visited);
                        cnt++;
                    }
                }

            ans.push_back(cnt);
        }

        for(auto val: ans)
            printf("%d\n", val);

        return 0;
    }