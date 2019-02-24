#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, ans=0, sum;
    int days[20]={0,}, pay[20] = {0,};
    
    scanf("%d", &n);
    
    for(int i=1;i<=n;i++){
        scanf("%d %d", &days[i], &pay[i]);
    }
    
    for(int i=1; i<=n; i++) {
        sum = 0;
        
        for(int j=i; j<=n && j+days[j]<=n+1 ; j += days[j]){
            sum += pay[j];
        }
        
        ans = max(sum, ans);
    }
    
    printf("%d\n", ans);
    
    return 1;
}
