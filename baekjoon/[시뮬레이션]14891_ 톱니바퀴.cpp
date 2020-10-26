#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

char gear[5][8];

void clockMove(int idx) {
    int tmp = gear[idx][8];

    for(int j=8; j>1; j--)
        gear[idx][j] = gear[idx][j-1];

    gear[idx][1] = tmp;
}

void revClockMove(int idx) {
    int tmp = gear[idx][1];

    for(int j=1; j<8; j++)
        gear[idx][j] = gear[idx][j+1];

    gear[idx][8] = tmp;
}

void moveGear(int idx, int direction, bool isLeft, bool first) {

    // 왼쪽으로 가는 경우
    if(isLeft && idx > 1 && gear[idx][7] != gear[idx-1][3])
        moveGear(idx-1, direction*-1, true, false);
    if(first) // 첫번째인 경우 오른쪽또 탐색하도록
        isLeft = !isLeft;
    // 오른쪽으로 가는 경우
    if(!isLeft && idx < 4 && gear[idx][3] != gear[idx+1][7])
        moveGear(idx+1, direction*-1, false, false);

    if(direction == 1) clockMove(idx);
    else revClockMove(idx);
}

int main() {
    int idx, direction, k, ans=0;

    for(int i=1; i<5; i++){
        for(int j=1; j<9; j++)
            scanf("%c", &gear[i][j]);
        getchar();
    }

    scanf("%d", &k);
    vector<pair<int,int>> move; // 삭제해도 될듯

    for(int i=0; i<k; i++) {
        scanf("%d %d", &idx, &direction);
        moveGear(idx, direction, true, true);
    }

    // 점수 계산
    for(int i=1; i<5; i++) {
        if(gear[i][1] == '0') continue;
        ans += pow(2, i-1);
    }

    printf("%d\n", ans);

    return 0;
}