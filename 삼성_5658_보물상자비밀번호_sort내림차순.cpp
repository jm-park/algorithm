/**
 * [ 시뮬레이션 ]
 * 문제: 5658 보물상자비밀번호
 *
 * https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRUN9KfZ8DFAUo
 *
 */
#include<iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
int N, K;
int main(int argc, char** argv) {
    int test_case;
    int T;

//    freopen("sample_input.txt", "r", stdin);
    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case) {

        string numbers;

        // N은 4의 배수, (8 ≤ N ≤ 28)
        cin >> N >> K;
        cin >> numbers;

        vector<int> orderedNum;
        vector<string> numberList;

        // 회전 횟수
        for(int i = 0; i < N/4; i++) {

            // 만들어줌
            for(int j = 0; j < numbers.size(); j+=N/4) {
                /**
                 * substr(시작indx, 개수)
                 */
                string strNum = numbers.substr(j, N/4);
                int val = 0;
                for(int k = 0; k < numberList.size(); k++) {
                    if(numberList[k]== strNum) {
                        val = 1; break;
                    }
                }

                if(val == 0) {
                    numberList.push_back(strNum);
                }
            }

            numbers = numbers[numbers.size()-1]+ numbers.substr(0, numbers.size()-1);
        }

        for(int i = 0; i < numberList.size(); i++){
            string strNum = numberList[i];
            int n = 0;
            for(int x = 0; x < N/4; x++) {

                int subNum = 1;
                if(strNum[x] >= '0'&&strNum[x] <= '9') {
                    subNum = strNum[x]-'0';
                } else {
                    switch (strNum[x]) {
                        case 'A': subNum = 10; break;
                        case 'B': subNum = 11; break;
                        case 'C': subNum = 12; break;
                        case 'D': subNum = 13; break;
                        case 'E': subNum = 14; break;
                        case 'F': subNum = 15; break;
                    }
                }

                for(int mul = x; mul <  N/4-1; mul++) {
                    subNum *= 16;
                }
                n+=subNum;
            }
            orderedNum.push_back(n);
        }

        /**
         * 내림차순 정렬!!!!!!!!!!
         */
        sort(orderedNum.begin(), orderedNum.end(), [](const int a, const int b) {
            return a > b;
        });

        cout << "#" << test_case << " " << orderedNum[K-1] << endl;

    }

    return 0;
}