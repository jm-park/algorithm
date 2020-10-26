#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int num;
    int dp[1000001]={0, };
    
    scanf("%d", &num);
    
    for(int i=2; i<=num; i++){
        if(i%3 == 0)
            dp[i] = min(dp[i-1], dp[i/3])+1;
        else if(i%2 == 0)
            dp[i] = min(dp[i-1], dp[i/2])+1;
        else
            dp[i] = dp[i-1]+1;
    }
    
    printf("%d\n", dp[num]);
    
    return 0;
}
