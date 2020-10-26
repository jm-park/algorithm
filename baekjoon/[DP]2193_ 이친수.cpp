#include <cstdio>

using namespace std;

int main() {
    int n;
    long long dp[95] = {0, 1, 1, }; // int 범위 초과
    
    scanf("%d", &n);
    
    for(int i=3; i<=n; i++) {
        dp[i] = dp[i-1]+dp[i-2];
    }
    
    printf("%lld\n", dp[n]);
    
    return 0;
}
