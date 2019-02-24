#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, ans = 0;
    int day[20]={0,}, pay[20] = {0,}, dp[20] = {0, };
    
    scanf("%d", &n);
    
    for(int i=1;i<=n;i++){
        scanf("%d %d", &day[i], &pay[i]);
        dp[i] = pay[i];
    }
    
    for(int i=2; i<=n; i++) {
        for(int j=1; j<i; j++) {
            if(i-j >= day[j]) {
                dp[i] = max(dp[j]+pay[i],dp[i]);
            }
        }
    }
    
    for(int i=1; i<=n; i++) {
        if(i+day[i] <= n+1)
            ans = max(ans, dp[i]);
    }
    printf("%d\n",ans);
    
    return 0;
}
