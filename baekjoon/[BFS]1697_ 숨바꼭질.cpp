#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, k, next_x;
	queue<int> que;
	int move[] = { -1, 1, 2 };
	int dist[100005] = { 0, };
	bool ck[100005] = { false, };
	
	scanf("%d %d", &n, &k);
	que.push(n);
	dist[n] = 0;
	ck[n] = true;

	while (!que.empty() || ck[k] == false) {
		int x = que.front();
		que.pop();
		
		for (int i = 0; i < 3; i++) {
			if (i == 2) next_x = x*move[i];
			else next_x = x + move[i];

			if (ck[next_x] == false && next_x >= 0 && next_x <= 100000) {
				que.push(next_x);
				ck[next_x] = true;
				dist[next_x] = dist[x] + 1;
			}
		}
	}

	printf("%d\n", dist[k]);
	return 0;
}