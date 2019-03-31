#include <iostream>
#include <string>

using namespace std;
int main() {
    string str;
    cin >> str;

    for(auto ch: str) {
        if (ch >= 'A' && ch <= 'Z')
            printf("%c", ch);
    }

    return 0;
}