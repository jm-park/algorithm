#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int r = a%b;
		a = b;
		b = r;
	}
	return a;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main() {
	int T, M, N, x, y;
	vector<int> ans;

	scanf("%d", &T);

	while (T--) {
		scanf("%d %d %d %d", &M, &N, &x, &y);

		int i , year = -1, max = lcm(M, N);

		for (i = 0; x+i*M <= max; i++) {
			// 60 -10(60/10)
			int cnt_y = (x + i*M) - N*((x + i*M) / N);
			if (y == cnt_y || N == y && cnt_y == 0) {
				year = x+i*M;
				break;
			}
		}

		ans.push_back(year);
	}

	for (vector<int>::iterator i = ans.begin(); i < ans.end(); i++)
		printf("%d\n", *i);

	return 0;
}