#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int n, num;
    scanf("%d",&n);
    vector<int> ans;
    int fibo0[45] = {1,0, }, fibo1[45] = {0,1,0, };
    
    // 미리 40까지 0과 1의 출력 개수 합을 계산해둠
    for(int i=2; i<=40; i++) {
        fibo0[i] = fibo0[i-1]+fibo0[i-2];
        fibo1[i] = fibo1[i-1]+fibo1[i-2];
    }
    
    for(int i=0; i<n; i++) {
        scanf("%d", &num);
        ans.push_back(fibo0[num]);
        ans.push_back(fibo1[num]);
    }
    
    for(int i=0; i<n*2; i+=2) {
        printf("%d %d\n", ans[i], ans[i+1]);
    }
    
    return 0;
}
