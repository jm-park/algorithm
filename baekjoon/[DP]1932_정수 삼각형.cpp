#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n;
    long long triangle[505][505] = {0, };
    
    scanf("%d",&n);
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            scanf("%lld", &triangle[i][j]);
            
            // 행의 중간 부분 (왼쪽, 오른쪽 대각선 이동을 통해 접근할 수 있는 경우)
            if(i!=1 && j>1 && j<i) {
                triangle[i][j] += max(triangle[i-1][j], triangle[i-1][j-1]);
            }
            // 행의 맨 왼쪽 부분 (왼쪽 대각선으로부터만 이동해서 올 수 있는 경우)
            else if(i!=1 && j==1) {
                triangle[i][j] += triangle[i-1][j];
            }
            // 행의 맨 오른쪽 부분 (오른쪽 대각선으로부터만 이동해서 올 수 있는 경우)
            else if(i !=1 && j==i){
                triangle[i][j] += triangle[i-1][j-1];
            }
        }
    }
    
    // n번째 행에서 가장 max값 찾아내기
    long long * value = max_element(triangle[n], triangle[n]+n+1);
    printf("%lld\n", *value);
    
    return 0;
}
