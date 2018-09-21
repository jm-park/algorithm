
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
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
