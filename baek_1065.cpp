#include <iostream>

using namespace std;

int main() {

	int n, cnt = 99;

	scanf("%d", &n);

	// n�� 100�̸��� ���� �ش� �������� �Ѽ��� ����
	if (n < 100)
		cnt = n;
	else {
		int num100, num10, num1;

		for (int i = 100; i <= n; i++) {
			num100 = i / 100;
			num10 = (i % 100) / 10;
			num1 = (i % 100) % 10;

			if (num100 - num10 == num10 - num1 || num10 - num100 == num1 - num10)
				cnt++;
		}
	}

	printf("%d\n", cnt);

	return 0;
}