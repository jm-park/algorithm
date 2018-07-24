#include <iostream>

using namespace std;

int main() {
	int n, kg, quotient, remainder, ans = 0;

	scanf("%d", &n);

	while (n > 2) {
		if (n % 5 == 0) {
			ans += n / 5;
			n = 0;
			break;
		}
		n -= 3;
		ans++;
	}

	if (n) // n의 무게가 아직 남아있는 경우
		ans = -1;

	printf("%d\n", ans);

	return 0;
}