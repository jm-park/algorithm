#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int dp[305] = {0, }, score[305] = {0, };
    
    scanf("%d", &n);
    for(int i=1; i<=n ; i++) {
        scanf("%d", &score[i]);
        dp[i] = score[i];
    }
    
    dp[2] = dp[1] + dp[2];
    for(int i=3; i<=n; i++) {
        dp[i] = score[i] + max(score[i-1]+dp[i-3], dp[i-2]);
    }
    
    printf("%d\n", dp[n]);
    
    return 0;
}
