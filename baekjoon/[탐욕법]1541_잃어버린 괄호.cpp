/**
 * [ 그리디 알고리즘 ]
 * 문제: 1541 잃어버린 괄호
 *
 * https://www.acmicpc.net/problem/1541
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

vector<int> numbers;

int main() {

    string input;

    //  양수와 +, -, 길이가 최대 50인 식
    // 수는 0으로 시작할 수 있다.
    cin >> input;
    int lth = input.size();

    int sum = 0;
    string num = "";
    for(int i = 0; i < lth; i++) {

        if(input[i] >= '0' && input[i] <= '9') {
            // 숫자인 경우
            num += input[i];
            // 맨마지막 숫자를 처리하는 경우 PASS되는 것을 방지하기 위해 일부러 문자를 바꿔버림
            if(i == lth-1) {
                // 꼼수 부림
                input[i] = '-';
                i--;
            }
        } else {
            sum += stoi(num);
            num = "";

            // 부호인 경우
            if(input[i] == '-') {
                int val = sum;
                if(numbers.size() > 0) {
                    // 이전 값이 있다면, 빼줌
                    val = numbers.back() - sum;
                    numbers.pop_back();
                }
                numbers.push_back(val);

                sum = 0;
            }

        }

    }

    /**
     * 이 식의 값을 최소값
     *
     * 기본생각:
     * -(뺄셈)은 생관없고, +(덧셈)의 경우 더하기의 모든 값을 묶어준 후 뺄셈이 나오면 빼줘버린다.
     * 이것이 가장 최소가 나올 수 있는 방안
     *
     * eg. 55-(50+40+40)-(10+30+20)
     */
    cout << numbers[0] << endl;
    return 0;
}