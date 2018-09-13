#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	vector<int> nums;
	
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) 
		nums.push_back(i);
	
	do {
		for (int i = 0; i < n; i++)
			printf("%d ", nums[i]);
		printf("\n");
	}while (next_permutation(nums.begin(), nums.end()));

	return 0;
}