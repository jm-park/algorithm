#include <iostream>
#include <string>

using namespace std;

int main() {
	int cnt = 0;
	string n;
	int nums[10] = { 0, };

	getline(cin, n);

	// �Է¹��� ���ڵ� ������ ����Ƚ�� ī��Ʈ
	for (int i = 0; i < n.length(); i++) {
		if (n[i] == '9') // '9'�� ���� '6'���� ī��Ʈ
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