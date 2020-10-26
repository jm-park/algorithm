#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m, start = 0, end = 0, ans = 0;
	
	scanf("%d %d", &n, &m);
	vector<int> arr(n);
	
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

	int sum = arr[0];
	while (true) {
		if (sum < m && end >= n - 1) break;
		else if (sum > m && start >= n - 1)break;
		else if (sum == m) {
			ans++;
			end < n - 1? sum += arr[++end]: sum -= arr[start++];
		}
		else if (sum < m) sum += arr[++end];
		else if (sum > m) 	sum -= arr[start++];
	}

	printf("%d\n", ans);

	return 0;
}