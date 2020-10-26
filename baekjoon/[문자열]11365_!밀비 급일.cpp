#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    vector <string> ans;

    while(1){
        string strLine;

        getline(cin, strLine);  // string을 end of Line 까지 받기

        if(strLine.compare("END") == 0) break;

        reverse(strLine.begin(), strLine.end());
        ans.push_back(strLine);
    }

    for(auto str: ans){
        cout << str << endl;
    }
    return 0;
}