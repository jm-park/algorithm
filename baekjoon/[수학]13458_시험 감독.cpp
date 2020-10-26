#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int tmp, n, main_proc, sub_proc;
    long long ans = 0;
    vector<int> test_n;
    
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%d", &tmp);
        test_n.push_back(tmp);
    }
    scanf("%d %d", &main_proc, &sub_proc);
    
    for(int i=0; i<n; i++) {
        test_n[i] -= main_proc;
        ans++;
        if(test_n[i] > 0){
            ans += test_n[i]%sub_proc == 0 ? test_n[i]/sub_proc:test_n[i]/sub_proc+1;
        }
    }
    
    printf("%lld\n", ans);
    
    return 0;
}
