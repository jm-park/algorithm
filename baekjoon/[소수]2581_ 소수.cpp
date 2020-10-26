#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int M, N, min = 10001, sum = 0;

	scanf("%d %d", &M, &N);

	for (int i = M; i <= N; i++) {
		
		// 1�϶��� 2�϶� ���� ó��
		if (i == 1)
			continue;
		else if (i == 2) {
			sum += i;
			min = i;
			continue;
		}
			
		// �����ٱ��� ���� �Ҽ����� �Ǵ�
		int j, max = sqrt(i);
		for (j = 2; j <= max; j++) {
			if (i%j == 0)
				break;
		}
		// �����ٱ��� ������ ������������ ��찡 ���� ��� �Ҽ�ó��
		if (j > max) {
			sum += i;
			min = i < min ? i : min;
		}

	}

	if (!sum)
		printf("-1\n");
	else
		printf("%d\n%d\n", sum, min);

	return 0;
}