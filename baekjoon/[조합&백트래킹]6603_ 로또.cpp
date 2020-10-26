#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int k = 1;

	while (k != 0) {
		scanf("%d", &k);
		if (k == 0) break;

		vector<int> nums(k);
		for (int i = 0; i < k; i++)
			scanf("%d", &nums[i]);

		vector<int> ck;
		for (int i = 0; i < k - 6; i++) ck.push_back(0);
		for (int i = 0; i < 6; i++) ck.push_back(1);

		vector<vector<int>> ans;
		do {
			vector<int> curr;
			for (int i = 0; i < k; i++)
				if (ck[i]) curr.push_back(nums[i]);
			ans.push_back(curr);
		} while (next_permutation(ck.begin(), ck.end()));
		
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++) {
			for (int j = 0; j < 6; j++)
				printf("%d ", ans[i][j]);
			printf("\n");
		}
		printf("\n");

	}

	return 0;
}