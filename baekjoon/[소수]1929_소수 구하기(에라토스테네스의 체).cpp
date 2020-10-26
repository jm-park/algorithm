#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_SIZE 1000000
using namespace std;

int main() {
	int M, N, min = 10001, sum = 0;
	bool not_prime_num[MAX_SIZE + 5] = {false, };

	not_prime_num[1] = true;

	for (int item = 2; item <= MAX_SIZE;item++) {
		if (not_prime_num[item] == false) {
			for (int i = 2; i*item <= MAX_SIZE; i++) 
					not_prime_num[i*item] = true; // 소수가 아닌 수 지움
		}
	}

	scanf("%d %d", &M, &N);

	for (int i = M; i <= N; i++)
		if (!not_prime_num[i])
			printf("%d\n", i);

	return 0;
}