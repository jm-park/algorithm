#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> heights) {
	int n = heights.size();
	vector<int> answer;

	for (int i = n - 1; i>-1; i--) {
		int j;
		for (j = i - 1; j>-1; j--) {
			if (heights[i] < heights[j]) {
				answer.insert(answer.begin(), j + 1);
				break;
			}
		}
		if (j == -1)
			answer.insert(answer.begin(), 0);
	}
	return answer;
}