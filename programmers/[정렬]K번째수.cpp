#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int st1[] = { 1, 2, 3, 4, 5 };
int st2[] = { 2, 1, 2, 3, 2, 4, 2, 5 };
int st3[] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<int> cnt(3);
	for (int i = 0; i<answers.size(); i++) {
		if (answers[i] == st1[i % 5]) cnt[0]++;
		if (answers[i] == st2[i % 8]) cnt[1]++;
		if (answers[i] == st3[i % 10])cnt[2]++;
	}

	int max = *max_element(cnt.begin(), cnt.end());

	for (int i = 0; i<3; i++)
		if (cnt[i] == max)
			answer.push_back(i + 1);

	return answer;
}