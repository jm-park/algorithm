#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N, M, num, cnt = 0;
	vector<int> deque;

	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
		deque.push_back(i);

	for (int j = 0; j < M; j++) {
		scanf("%d", &num);

		for (int i = 0; i < N; i++) 
			if (deque[i] == num) {
				cnt += min(i, N - i); // 앞/뒤에서 탐색한 것 중에서 빠른 쪽을 cnt더해줌
				rotate(deque.begin(), deque.begin() + i + 1, deque.end() - j);
				break;
			}

		N--; // 원소하나를 뽑아냈기 때문에 Deque의 원소 갯수가 줄어듬
	}

	printf("%d\n", cnt);

	return 0;
}