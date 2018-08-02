#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, num;
	int ans[10001] = {0,};

	scanf("%d", &N);

	while (N--) {
		scanf("%d", &num);
		ans[num]++;
	}

	for (int i = 1; i <= 10000; i++) {
		if (ans[i] == 0)
			continue;
		else if (ans[i] > 1) {
			for (int j = 1; j < ans[i]; j++)
				printf("%d\n", i);
		}
		printf("%d\n", i);
	}
		

	return 0;
}