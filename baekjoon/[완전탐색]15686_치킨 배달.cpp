#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int ans=987654321, n, m, map[51][51];
bool chosen[15];
vector<pair<int,int>> house, chicken;

void dfs(int idx, int chicken_cnt) {

    if(idx > chicken.size()) return;

    // m개인 경우, 최소 경로
    if(chicken_cnt == m) {
        int tot_dist = 0;

        for(int i=0; i<house.size(); i++) {

            int dist_min=987654321; // 집을 기준으로 가장 가까운 치킨집까지의 거리 측정
            for(int j=0; j<chicken.size(); j++) {
                if(!chosen[j]) continue;

                // 거리값
                int dist = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);
                dist_min = min(dist_min, dist);
            }
            tot_dist += dist_min;   // 집에서 치킨집가는 경로중 가장 최소 경로 값을 더해줌
        }
        ans = min(tot_dist, ans); // 모든 경로 중 가장 짧은 경로를 ans로 저장

        return;
    }

    chosen[idx] = true;
    dfs(idx+1, chicken_cnt+1);

    chosen[idx] = false;
    dfs(idx+1, chicken_cnt);

}

int main() {
    int val;
    scanf("%d %d", &n, &m);

    // 1, 2인 경우에만 각각 vector에 저장한다 => 저장은 x,y(좌표)값을 pair로 저장
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &val);
            if(val == 1)
                house.push_back(make_pair(i,j));
            else if(val == 2)
                chicken.push_back(make_pair(i,j));
        }
    }

    dfs(0,0);

    printf("%d\n", ans);

    return 0;
}