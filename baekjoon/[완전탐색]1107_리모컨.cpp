#include <iostream>
#include <bitset>
using namespace std;

bitset<11> enable_btn;

int possible_btn(int c) {
	int cnt = 0;

	if (c == 0)
		return enable_btn[0] == false ? 1 : -1;

	while (c > 0) {
		if (enable_btn[c % 10] == true)
			return -1;
		c /= 10;
		cnt++;
	}
	return cnt;
}

int main() {
	int n, m, tmp, ans;
	enable_btn.reset();

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		scanf("%d", &tmp);
		enable_btn[tmp] = true;
	}

	ans = n - 100 < 0 ? (n - 100)*-1 : n - 100;
	if (ans > 2) {
		for (int i = 0; i <= 1000000; i++) {
			int res = possible_btn(i);

			if (res != -1) {
				int ch = n - i < 0 ? (n - i) * -1 : n - i;
				if (ans > ch + res)					
					ans = ch + res;					
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}