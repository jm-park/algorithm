#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, s, cnt = 1, start = 0, end = 0, ans = 1000001;

	scanf("%d %d", &n, &s);
	vector<int> arr(n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

	int sum = arr[start];
	while (true) {
		if ((sum < s && end >= n - 1) || (sum > s && start >= n - 1)) break;
		else if (sum == s) {
			if (ans > cnt) ans = cnt;
			if (end < n - 1) {
				sum += arr[++end];
				cnt++;
			}
			else {
				sum -= arr[start++];
				cnt--;
			}
		}
		else if (sum < s) {		
			sum += arr[++end];
			cnt++;
		}
		else {
			if (ans > cnt) ans = cnt;
			sum -= arr[start++];
			cnt--;
		}

	}

	printf("%d\n", ans == 1000001 ? 0 : ans);

	return 0;
}