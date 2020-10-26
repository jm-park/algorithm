#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a, b;
    vector <int> ans;

    while(1){
        scanf("%d %d", &a, &b);
        if(a==0 && b==0)
            break;

        ans.push_back(a+b);
    }

    for(auto num: ans)
        printf("%d\n", num);

    return 0;
}