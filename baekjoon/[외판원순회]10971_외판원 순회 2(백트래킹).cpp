#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int ans = 210000000, n, w[15][15] = { 0, };
	vector<int>dist;

	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		dist.push_back(i);	// 0, 1, 2, ... , n-1 저장
		for (int j = 0; j < n; j++)
			scanf("%d", &w[i][j]);
	}

	// 순열을 사용하여 순회할 수 있는 모든 방법을 탐색함
	// 단, 문제 조건의 '시작점으로 다시 돌아감'이 있기 때문에 시작점을 1로 고정시켜서 순열을 돌린다.
	do {
		int i, sum = 0;

		for (i = 0; i < n - 1; i++) {
			if (w[dist[i]][dist[i + 1]] == 0) break; // i->i+1의 비용이 0 인경우 순회 불가
			else sum += w[dist[i]][dist[i + 1]]; // i->i+1의 비용을 더해줌
		}

		// 순회 중간의 비용이 0이 없으면서 j->i로 돌아가는 비용이 0이 아닌 경우
		if (i >= n - 1 && w[dist[i]][dist[0]] != 0) {
			sum += w[dist[i]][dist[0]];	// 돌아가는 비용을 더해줌
			if (sum < ans) ans = sum; // 최소비용 저장
		}

	} while (next_permutation(dist.begin()+1, dist.end()));
	
	printf("%d\n", ans);

	return 0;
}