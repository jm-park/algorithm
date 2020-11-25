/**
 * [ KMP ]
 * 문제: 1701 Cubeditor
 *
 * https://www.acmicpc.net/problem/1701
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int findSubStr(string s) {
    int subArr[5005] = {0, };
    int lth = s.size(), result = 0, j = 0;

    for(int i = 1; i < lth; i++) {

        // 글자가 같다면, 이전Index의 총 같은 갯수값을 j에 저장시킨다.
        // j > 0 : 단 첫번째 자리가 같은 경우는 당연히 패스한다
        while(j > 0 && s[i] != s[j]) j = subArr[j-1];
        if(s[i] == s[j]) {
            result = max(result, subArr[i] = ++j);
        }
    }

    return result;
}

int main() {
    string input;

    // 최대 5,000이고, 문자열은 모두 소문자
    cin >> input;

    int answer = 0, lth = input.size();

    // qbqtzqqt => q b "q t" z q "q t"
    // 가장 긴 부분문자열이 꼭 0번째부터 시작하지 않기 때문!
    for(int i = 0; i < lth; i++) {
        if(answer > lth-i) break;
        answer = max(answer, findSubStr(input.substr(i, lth-i)));
    }

    // 두 번이상 나오는 부분문자열 중에서 가장 긴 길이
    cout << answer << endl;

    return 0;
}