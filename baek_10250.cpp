#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t, h, w, n, floor, room_num;
	vector<int> ans;

	scanf("%d", &t);

	while (t--) {
		scanf("%d %d %d", &h, &w, &n);

		if (n%h) {
			floor = n%h;
			room_num = n / h + 1;
		}
		else {
			floor = h;
			room_num = n / h;
		}

		ans.push_back(floor * 100 + room_num);
	}

	for (vector<int>::iterator i = ans.begin(); i < ans.end(); i++)
		printf("%d\n", *i);

	return 0;
}