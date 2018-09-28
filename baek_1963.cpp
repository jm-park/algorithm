#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int change(int num, int idx, int val) {
	if (idx == 0 && val == 0) return -1;
	string next_num = to_string(num);
	next_num[idx] = val + '0';
	return stoi(next_num);
}

int main() {
	int t, now, want;
	bool not_prime[10005] = { false, };

	for (int i = 2; i <= 10000; i++) {
		if (not_prime[i]) continue;
		for (int j = i*i; j <= 10000; j+=i)
			not_prime[j] = true;
	}

	scanf("%d", &t);

	while (t--) {
		queue<int> que;
		bool visit[10003] = { false, };
		int dist[10003] = { 0, };
		
		scanf("%d %d", &now, &want);
		que.push(now);
		visit[now] = true;

		while (!que.empty()) {
			int x = que.front();
			que.pop();
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j <= 9; j++) {
					int ret = change(x, i, j);
					if (ret != -1 && visit[ret] != true && not_prime[ret] == 0) {
						que.push(ret);
						visit[ret] = true;
						dist[ret] = dist[x] + 1;
					}
				}
			}
		}
		printf("%d\n", dist[want]);
	}

	return 0;
}