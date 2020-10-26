#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, end = 0, start = 0, ans = 0;

	scanf("%d", &n);
	vector<int> primary(n + 1);
	vector<bool> is_primary(n + 1, true);

	for (int i = 2; i <= n; i++) {
		if (is_primary[i] == false) continue;
		primary.push_back(i);
		for (int j = 2; i*j <= n; j++)
			is_primary[i*j] = false;
	}
	
	int sum = primary.front();

	while (start <= end && end < primary.size()) {
		if (sum <= n) {
			if (sum == n) ans++;
			end++;
			if (end < primary.size()) sum += primary[end];
		}
		else
			sum -= primary[start++];
	}

	printf("%d\n", ans);

	return 0;
}