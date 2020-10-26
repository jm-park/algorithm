#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int t;

	scanf("%d", &t);

	while (t--) {
		int a, b;
		queue<int> que;
		char calcul[] = { 'D', 'S', 'L', 'R' }, how[10001] = { 0, };
		int from[10001] = { 0, };
		bool visit[10001] = { false, };
		
		scanf("%d %d", &a, &b);
		visit[a] = true;
		from[a] = -1;
		que.push(a);

		while (!que.empty()) {
			int now = que.front();			
			que.pop();
			vector<int> next_val(4);

			next_val[0] = (now * 2) % 10000;
			next_val[1] = now == 0 ? 9999 : now - 1;
			next_val[2] = (now % 1000) * 10 + (now / 1000);
			next_val[3] = (now % 10) * 1000 + (now / 10);

			for (int i = 0; i < 4; i++) {
				if (visit[next_val[i]] == false) {
					que.push(next_val[i]);
					visit[next_val[i]] = true;
					how[next_val[i]] = calcul[i];
					from[next_val[i]] = now;
				}
			}
		}
		string ans = "";
		while (b != a) {
			ans += how[b];
			b = from[b];
		}
		reverse(ans.begin(), ans.end());
		cout << ans << "\n";
	}

	return 0;
}