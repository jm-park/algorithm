/**
 * [ 구현 ]
 * 문제: 16235 나무 재테크
 *
 * https://www.acmicpc.net/problem/14503
 *
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <ctime>

using namespace std;

/** 예 => 답: 5150
10 10 1000
100 100 100 100 100 100 100 100 100 100
100 100 100 100 100 100 100 100 100 100
100 100 100 100 100 100 100 100 100 100
100 100 100 100 100 100 100 100 100 100
100 100 100 100 100 100 100 100 100 100
100 100 100 100 100 100 100 100 100 100
100 100 100 100 100 100 100 100 100 100
100 100 100 100 100 100 100 100 100 100
100 100 100 100 100 100 100 100 100 100
100 100 100 100 100 100 100 100 100 100
1 1 1
2 2 1
3 3 1
4 4 1
5 5 1
6 6 1
7 7 1
8 8 1
9 9 1
10 10 1
*/

int N, M, K;
int pos[8][2] = {{-1, -1},{-1, 0},{-1, 1},{0,-1},{0,1},{1,-1},{1,0},{1,1}}; // 8방위
int map[15][15], feed[15][15], deadTreeFeed[15][15];
int tree[15][15][1101];    // 전체 나무 리스트
vector<vector<int>> tree5;  // 5배수가 되는 나무의 tree deque의 index값

void fall() {

    int treeTotalCnt = tree5.size();

    for (int i = 0; i < treeTotalCnt; i++) {

        // 8방위에 나무 추가
        for (int idx = 0; idx < 8; idx++) {

            int nextX = tree5[i][0]+ pos[idx][0], nextY = tree5[i][1] + pos[idx][1];

            // 땅의 범위를 초과하지 않는 경우 => 나무 번식.
            if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N) {
                tree[nextX][nextY][1] += tree5[i][2] ;    // 한살짜리 나무 추가
            }
        }

    }

    tree5.clear();    // 5배수의 나무 index 리스트는 비워준다

}

void spring() {

    for(int x = 0 ; x < N; x++) {
        for(int y = 0; y < N; y++) {
            int newAgeArr[1101]= {0,};
            for(int age = 1; age <= 1100; age++) {
                // 나무가 없는 경우는 PASS
                if(tree[x][y][age] == 0) continue;


                // 아직 양분이 있는 경우
                if (map[x][y] >= age) {
                    int treeCnt = map[x][y]/age;    // 양분먹기가 가능한 나무 개수

                    if(tree[x][y][age] <= treeCnt) {    // 모든 나무가 양분먹기 가능한 경우

                        map[x][y] -= (age*tree[x][y][age]); // 먹은 양분 제거
                        newAgeArr[age+1] = tree[x][y][age];

                    } else {    // 같은나이중 몇개만 가능한 경우

                        map[x][y] -= (age*treeCnt); // 먹은 양분 제거
                        newAgeArr[age+1] = treeCnt;
                        deadTreeFeed[x][y] += ((age/2)*(tree[x][y][age]-treeCnt));
                    }

                }
                else { // 양분이 없어서 나무가 죽는 경우0
                    deadTreeFeed[x][y] += ((age/2)*tree[x][y][age]);  // 나무나이를 2로 나눈 값이, 나무가 있던 칸에 양분으로 추가

                }

                // 나무개수 0표시
                tree[x][y][age] = 0;
            }

            // 나무 개수 변경
            int cnt = 0;
            for(int age = 1; age <= 1100; age++) {
                tree[x][y][age] += newAgeArr[age];
                // 나이가 5배수인경우 vector에 넣는다.
                if (age % 5 == 0) {
                    cnt += tree[x][y][age];
                }
            }
            if(cnt > 0) {
                tree5.push_back({x,y,cnt});
            }
        }

    }

}


void winter() {

    // 땅에 양분을 추가
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // 입력받은 양분값과 여름에 더해져야할 양분값을 map에 저장한다
            map[i][j] += (feed[i][j] + deadTreeFeed[i][j]);
            deadTreeFeed[i][j] = 0; // 죽은 나무 양분값은 초기화시켜준다
        }
    }

}

int main() {

    scanf("%d %d %d", &N, &M, &K);
    // A배열 저장
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> feed[i][j];  // 겨울에 주는 양분 값
            map[i][j] = 5;  // 기본양분 : 5 설정
        }
    }
    // 나무정보 저장
    for (int i = 0; i < M; i++) {

        int x, y, age;
        scanf("%d %d %d", &x, &y, &age);

        tree[x-1][y-1][age]++;  // x위치, y위치에 해당하는 age 개수 저장
    }


    // K년이 될때까지 아래를 반복한다.
    for (int year = 0; year < K; year++) {
        // 봄(season = 1): 앙분 - 나무나이 and 나무나이 +1, 만약 2개이상이면 어린나무부터 양분을 먹는다. if(양분 == 0) 나무 죽음
        spring();
        // 여름(season = 2): 양분 += 죽은나무나이/2 ==> 봄에서 배열에 양분값을 저장해주고, 겨울에 값을 더해준다.
//        summer();
        // 가을(season = 3): 나무나이%5 == 0 인경우, 인접한 8개의 칸에 나이가 1인 나무가 생긴다.
        fall();
        // 겨울(season = 4): map[x][y] += 양분[x][y]
        winter();
    }

    // 살아있는 나무의 수를 구한다.

    int answer = 0;
    for(int x = 0 ; x < N; x++) {
        for(int y = 0; y < N; y++) {
            for (int age = 1; age <= 1100; age++) {
                answer += tree[x][y][age];
            }
        }

    }
    cout << answer << endl;

    return 0;
}