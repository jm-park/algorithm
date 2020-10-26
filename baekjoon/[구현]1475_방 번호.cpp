#include <iostream>
#include <string>

using namespace std;

int main() {
	int cnt = 0;
	string n;
	int nums[10] = { 0, };

	getline(cin, n);

	// 입력받은 숫자들 각각의 등장횟수 카운트
	for (int i = 0; i < n.length(); i++) {
		if (n[i] == '9') // '9'의 값은 '6'으로 카운트
			n[i] = '6';
		nums[n[i] - '0']++;
	}

	nums[6] = (nums[6] + 1) / 2;

	for (int i = 0; i < 10; i++) {
		if (nums[i] > cnt)
			cnt = nums[i];
	}

	printf("%d\n", cnt);

	return 0;
}