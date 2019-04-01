#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string chess_w[8] = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
};

vector<string> board;

int startW(int x, int y){
    int cnt=0;
    for(int i=x; i<x+8; i++){
        for(int j=y; j<y+8; j++){
            if(chess_w[i-x].at(j-y) != board[i].at(j)) cnt++;
        }
    }
    return cnt;
}

int main() {
    int n,m,ans=987654321;

    scanf("%d %d", &n, &m);
    getchar();
    board.resize(n+1);

    for(int i=0; i<n; i++)
        getline(cin, board[i]);

    for(int i=0; i<n-7; i++)
        for(int j=0; j<m-7; j++){
            int start_w = startW(i,j);
            ans = min( ans, min(start_w, 64-start_w) );  // W로 시작한 값은 B로 시작한 값 반대에 해당
        }

    printf("%d\n", ans);
    return 0;
}