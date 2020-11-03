/**
 * [ 스택/큐 ]
 * 문제: 42584 주식가격
 *
 * https://programmers.co.kr/learn/courses/30/lessons/42584
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> prices) {
    int size = prices.size();
    vector<int> answer;

    for(int i = 0; i < size; i++) {
        int sec = size-i-1;
        for(int j = i+1; j < size; j++) {
            // 가격이 떨어지는 시점
            if(prices[i] > prices[j]) {
                sec = j - i; break;
            }
        }

        answer.push_back(sec);
    }

    return answer;
}

int main() {

    vector<int> result = solution({1, 2, 3, 2, 3});
    for(int ans : result) {
        cout << ans << " ";
    }

    return 0;
}