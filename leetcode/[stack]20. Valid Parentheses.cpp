/**
 * [  ]
 * 문제: 20. Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

bool isValid(string s) {
    bool answer = true;
    vector<char> stack;


    int len = s.size();
    if (len%2 == 1) {
        return false;
    }
    for (int i =0; i<len; i++) {


        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            stack.push_back(s[i]);
        } else {

            char ch = stack.empty() ? 0 : stack.back();
            switch (ch) {
                case '(':
                    if(s[i] != ')') answer = false;
                    break;
                case '[':
                    if(s[i] != ']') answer = false;
                    break;
                case '{':
                    if(s[i] != '}') answer = false;
                    break;
                default:
                    answer = false;
            }


            if (!answer) {
                break;
            } else {
                stack.pop_back();
            }
        }
    }

    if(stack.size() > 0) answer = false;

    return answer;
}


int main() {


    // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Parentheses.
    // Memory Usage: 6.2 MB, less than 90.54% of C++ online submissions for Valid Parentheses.
    bool answer = isValid("[[");
    cout << answer << endl;
    return 0;
}