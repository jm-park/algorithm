#include <iostream>
#include <vector>
using namespace std;

int main() {
	int k, n, t, tmp, residents[15][15] = { 0, };
	vector<int> ans;

	// 0Ãş ÃÊ±âÈ­
	for (int i = 0; i <15; i++) {
		residents[0][i] = i;
	}

	int j = 1;
	for (int i = 1; i <= 14 * 14; i++) {
		tmp = i % 14;
		if (i % 14 == 0)
			tmp = 14;
		residents[j][tmp] = residents[j][tmp - 1] + residents[j - 1][tmp];
		if (tmp == 14)
			j++;
	}

	scanf("%d", &t);

	while (t--) {
		scanf("%d %d", &k, &n);
		ans.push_back(residents[k][n]);
	}

	for (vector<int>::iterator i = ans.begin(); i < ans.end(); i++)
		cout << *i << '\n';


	return 0;
}