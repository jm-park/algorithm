#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

long long fac[21] = { 1 };

int main() {
	int n, question;
	long long cnt = 0, k;
	bitset<21> is_num;
	vector<int> nums;

	for (int i = 1; i <= 20; i++)
		fac[i] = fac[i - 1] * i;
	
	scanf("%d %d", &n, &question);
	is_num.reset();
	nums.resize(n);

	if (question == 1) {
		scanf("%lld", &k);
		
		for (int i = 0; i < n; i++) {
			for (int j = 1; j <= n; j++) {
				if (is_num[j] == true) continue;

				if (fac[n - i - 1] < k) {
					k -= fac[n - i - 1];
				}					
				else {					
					nums[i] = j;
					is_num[j] = true;
					break;
				}
			}
		}

		for (int i = 0; i < n; i++)
			printf("%d ", nums[i]);
	}
	else {
		for (int i = 0; i < n; i++)
			scanf("%d", &nums[i]);
		
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < nums[i]; j++) {
				if (is_num[j] == false) 
					cnt += fac[n - i - 1];
			}
			is_num[nums[i]] = true;
		}

		printf("%lld\n", ++cnt);
	}

	return 0;
}