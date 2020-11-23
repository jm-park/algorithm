/**
 * [ 시뮬레이션 ]
 * 문제: 15662 톱니바퀴(2)
 *
 * https://www.acmicpc.net/problem/15662
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int T, K, gear[1000][8]; // 톱니바퀴 상태

void rotate(int num, int pos) {
    // pos: 방향이 1인 경우는 시계 방향(오른쪽)이고, -1인 경우는 반시계 방향(왼쪽)

    if(pos == 1) {
        int tmp = gear[num][7];
        for(int i = 7; i > 0; i--) {
            gear[num][i] = gear[num][i-1];
        }
        gear[num][0] = tmp;
    } else {
        int tmp = gear[num][0];
        for(int i = 0; i < 7; i++) {
            gear[num][i] = gear[num][i+1];
        }
        gear[num][7] = tmp;
    }
}

void solution(int num, int pos) {


    int visit[1000] = {0, };
    queue<pair<int,int>> changeGear;
    changeGear.push({num, pos});
    visit[num] = 1;

    while(!changeGear.empty()) {
        int nowG = changeGear.front().first, rot = changeGear.front().second;
        changeGear.pop();

        // 1. 현 톱니바퀴와 양 옆의 톱니바퀴의 극이 다른지 확인
        // 2. 다르다면 저장해야함
        if(nowG+1 < T && visit[nowG+1] == 0) { // 오른쪽 확인
            visit[nowG+1] = 1;

            if(gear[nowG][2] != gear[nowG+1][6]) {
                changeGear.push({nowG+1, rot*-1});
            }
        }
        if(nowG-1 >= 0 && visit[nowG-1] == 0) { // 왼쪽 확인
            visit[nowG-1] = 1;

            if(gear[nowG][6] != gear[nowG-1][2]) {
                changeGear.push({nowG-1, rot*-1});
            }
        }

        // 3. 톱니바퀴가 돈다.
        rotate(nowG, rot);
    }

}

int main() {

    // 톱니바퀴의 개수 T (1 ≤ T ≤ 1,000)
    cin >> T;

    // N극은 0, S극은 1
    for(int i = 0; i < T; i++) {
        // 12시방향부터 시계방향 순서대로
        string str;
        cin >> str;
        for(int j = 0; j < 8; j++) {
            gear[i][j] = str[j]-'0';
        }
    }

    // 회전 횟수 K(1 ≤ K ≤ 1,000)
    cin >> K;
    // 첫 번째 정수는 회전시킨 톱니바퀴의 번호, 두 번째 정수는 방향: 방향이 1인 경우는 시계 방향(오른쪽)이고, -1인 경우는 반시계 방향(왼쪽)
    int x, y;
    for(int i = 0; i < K; i++) {
        cin >> x >> y;
        solution(x-1, y);
    }

    // 12시방향이 S극인 톱니바퀴의 개수
    int answer = 0;
    for(int i = 0; i < T; i++) {
        if(gear[i][0] == 1) answer++;
    }

    cout << answer << endl;

    return 0;
}