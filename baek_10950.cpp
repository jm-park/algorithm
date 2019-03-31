#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int n, a, b;
    vector <int> ans;

    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d %d", &a, &b);
        ans.push_back(a+b);
    }

    for(auto num: ans)
        printf("%d\n", num);

    return 0;
}