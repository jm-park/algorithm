#include <iostream>
#include <string>

using namespace std;

int main() {
	int x, y, k, n = 0;
	int day[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	string date[] = { "MON","TUE","WED","THU","FRI","SAT" ,"SUN"};

	scanf("%d %d", &x, &y);

	for (int i = 0; i < x ; i++) {
		if (i == x - 1)
			k = y - 1;
		else
			k = day[i];
		for (int j = 0; j < k; j++) {
			n++;
		}
	}

	cout << date[n%7] << '\n';

	return 0;
}