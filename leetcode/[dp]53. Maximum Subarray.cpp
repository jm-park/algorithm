/**
 * [ DP ]
 * 문제: 53. Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

#define MAX_SIZE 30005
int maxSubArray(vector<int>& nums) {

    int dp[MAX_SIZE] = {0, }, answer, size = nums.size();
    // 초기화
    dp[0] = answer = nums[0];

    for (int i = 1; i < size; i++) {
        if(dp[i-1]+nums[i] > nums[i]) {
            dp[i] = dp[i-1]+nums[i];
        } else {
            dp[i] = nums[i];
        }

        answer = max(answer, dp[i]);
    }

    return answer;
}

int main() {


    // 결과
//    Runtime: 4 ms, faster than 96.39% of C++ online submissions for Maximum Subarray.
//    Memory Usage: 13.2 MB, less than 70.70% of C++ online submissions for Maximum Subarray.

    vector<int> nums;
    nums.push_back(5);
    nums.push_back(4);
    nums.push_back(-1);
    nums.push_back(7);
    nums.push_back(8);

    int answer = maxSubArray(nums);
    cout << answer << endl;
    return 0;
}