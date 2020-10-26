#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int M, N, min = 10001, sum = 0;

	scanf("%d %d", &M, &N);

	for (int i = M; i <= N; i++) {
		
		// 1일때와 2일때 예외 처리
		if (i == 1)
			continue;
		else if (i == 2) {
			sum += i;
			min = i;
			continue;
		}
			
		// 제곱근까지 나눠 소수여부 판단
		int j, max = sqrt(i);
		for (j = 2; j <= max; j++) {
			if (i%j == 0)
				break;
		}
		// 제곱근까지 나눠도 나눠떨어지는 경우가 없는 경우 소수처리
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