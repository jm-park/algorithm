#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, tmp;
	vector<int> nums;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		nums.push_back(tmp);
	}

	if (next_permutation(nums.begin(), nums.end()))
		for (int i = 0; i < n; i++)
			printf("%d ", nums[i]);
	else 
		printf("-1\n");

	return 0;
}