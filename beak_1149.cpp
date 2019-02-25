#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int r, g, b, min_r=0, min_g=0, min_b=0;
    scanf("%d", &n);
    
    // 1차 생각
//    int cost[1005][3] = {0,};
//    for(int i=0; i<n; i++)
//        for(int j=0; j<3; j++) {
//            scanf("%d", &cost[i][j]);
//            if(i != 0) {
//                if(j == 0)
//                    cost[i][j] += min(cost[i-1][j+1], cost[i-1][j+2]);
//                else if(j == 1)
//                    cost[i][j] += min(cost[i-1][j-1], cost[i-1][j+1]);
//                else
//                    cost[i][j] += min(cost[i-1][j-1], cost[i-1][j-2]);
//            }
//        }
//    printf("%d\n", min(cost[n-1][0], min(cost[n-1][1], cost[n-1][2])));
    
    // 2차 생각
    while(n--) {
        scanf("%d %d %d", &r, &g, &b);
        r += min(min_g, min_b);
        g += min(min_r, min_b);
        b += min(min_r, min_g);
        min_r = r;
        min_g = g;
        min_b = b;
    }
    
    printf("%d\n", min(r,min(g,b)));
    
    return 0;
}


