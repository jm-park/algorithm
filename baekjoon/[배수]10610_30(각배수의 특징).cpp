/**
 * [ 배수특징 ]
 * 문제: 10610 30
 *
 * https://www.acmicpc.net/problem/10610
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<char> nStr;
string N;

int main() {

    // N는 최대 10^5개의 숫자로 구성되어 있으며, 0으로 시작하지 않는다.
    cin >> N;

    int sum = 0, checkZero = 0;
    for(char c : N) {
        nStr.push_back(c);
        sum += (c-'0');
        if(checkZero == c-'0') {
            checkZero = 1;
        }
    }

    /**
     * [배수의 특징 이용]
     * 1) 30 배수: 0이 최소한 하나는 존재해야함
     * 2) 3 배수: 모든 자리 수의 합이 3의 배수
     *  => cf) https://m.blog.naver.com/PostView.nhn?blogId=alwaysneoi&logNo=100200385519&proxyReferer=https:%2F%2Fwww.google.com%2F
     */
    if(checkZero == 0 || sum%3 != 0) {
        cout << -1 << endl;
    } else {

        // 내림차순 정렬
        sort(nStr.begin(), nStr.end(), [] (const char a, const char b) {
            return a > b;
        });

        for(char c : nStr) {
            cout << c;
        }
        cout << endl;

    }

    return 0;
}