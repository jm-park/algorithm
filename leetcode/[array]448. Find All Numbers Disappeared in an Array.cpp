/**
 * [ 배열 ]
 * 문제: 448. Find All Numbers Disappeared in an Array
 *
 * https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/submissions/
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <list>
using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
    // you may assume the returned list does not count as extra space.
    vector<int> answer;
    int size = nums.size();

    for (int i = 0; i < size; i++) {

        // 이미 방문한 경우는 "음수"처리해버리기 때문에, 음수인 경우는 Index 탐색을 위해 양수로 돌려준다.
        int tmp = nums[i] > 0 ? nums[i] : -nums[i];

        // 방문처리: "음수"로 만듬으로 방문 처리
        // 여기서 굳이 -1 하는 경우는 => 실제 size는 1~n 이지만, index 는 0 ~ n-1이기 때문에
        nums[tmp-1] = nums[tmp-1] > 0 ? -nums[tmp-1] : nums[tmp-1];

    }

    for (int i = 0; i < size; i++) {

        // 양수: vector의 숫자가 없기 때문에 방문하지 못함을 의미함
        if (nums[i] > 0) {
            // index보다 +1된 값이 진짜 숫자임
            answer.push_back(i+1);
        }
    }

    return answer;
}

int main() {


    // 결과
    // Runtime: 52 ms, faster than 83.14% of C++ online submissions for Find All Numbers Disappeared in an Array.
    // Memory Usage: 33.5 MB, less than 94.57% of C++ online submissions for Find All Numbers Disappeared in an Array.

    vector<int> nums;
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(8);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(2);


    vector<int> answer = findDisappearedNumbers(nums);
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;

    return 0;
}