#include <iostream>
using namespace std;

int main() {
	int e, s, m, year;

	scanf("%d %d %d", &e, &s, &m);
	
	if (m == 19)
		m = 0;
	if (e == 15)
		e = 0;

	for (int i = 0;; i++) {
		year = 28 * i + s;

		if (year % 19 != m)
			continue;
		if (year % 15 == e)
			break;
	}

	printf("%d\n", year);

	return 0;
}