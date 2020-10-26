#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int n = 2;
	vector<int> ans;

	scanf("%d", &n);

	while (n) {
		int cnt = 0;

		// n ~ 2*n 범위의 각 숫자 소수 조사
		for (int i = n + 1; i <= 2 * n; i++) {

			if (i == 2) {
				cnt++;
				continue;
			}

			int j;
			// 소수 여부 확인 
			for (j = 2; j <= sqrt(i + 1); j++) {
				if (i%j == 0) 
					break;
			}
				
			if (sqrt(i + 1) < j)
				cnt++;
		}
		
		ans.push_back(cnt);
		
		scanf("%d", &n);
	}

	for (vector<int>::iterator i = ans.begin(); i < ans.end(); i++)
		cout << *i << '\n';

	return 0;
}