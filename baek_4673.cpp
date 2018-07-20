#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

vector<int> selfnumber;

// ������ ����
int ctor(int num) {	
	int next_num = num;

	while (num != 0) {
		next_num += num % 10;
		num /= 10;
	}
	
	return next_num;
}

int main() {
	// 1: �����ѹ�, 0: �����ѹ��� �ƴ� ��
	selfnumber.assign(20005, 1); // selfnumber�迭�� ��簪�� 1�� �ʱ�ȭ
	
	for (int i = 1; i <= 10000; i++) {
		selfnumber[ctor(i)] = 0;
		if (selfnumber[i])
			printf("%d\n", i);
	}

	return 0;
}