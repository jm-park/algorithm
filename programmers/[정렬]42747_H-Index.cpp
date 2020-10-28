/**
 * [ 정렬 ]
 * 문제: 42747 H-Index
 *
 * https://programmers.co.kr/learn/courses/30/lessons/42747
 *
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int idx = 0, answer = 0, size = citations.size();

    // 오름차순 정렬
    sort(citations.begin(), citations.end());

    // h번이상인 순간 포착
    while(1) {
        if(citations[idx] >= size-(idx)) break;
        idx++;
    }

    answer = citations[idx];

    // 만약 초과하는 경우는 하나씩 빼가면서 h값 탐색
    if(citations[idx] > size-(idx)) {
        while(1) {
            answer--;
            if(answer <= size-(idx)) break;
        }
    }


    return answer;
}

int main() {

//    cout << "RESULT: " << solution(2,{1, 2, 2, 2, 100}) << endl;

// 1,1,4,8,10
    cout << "RESULT: " << solution({4, 4, 4}) << endl;
    return 0;
}