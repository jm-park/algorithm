#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, a, b;
	vector<int> ans;

	scanf("%d", &n);
	ans.reserve(n + 5);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		ans.push_back(a + b);
	}
	
	for (vector<int>::iterator i = ans.begin(); i < ans.end(); i++)
		cout << *i << '\n';

	return 0;
}
