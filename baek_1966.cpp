#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

int main() {
	int t, m, n;

	scanf("%d", &t);

	while (t--) {
		vector<int> que;
		vector<int> sort_que;
		int  cnt = 1;

		scanf("%d %d", &n, &m);
		que.resize(n);

		for (int i = 0; i < n; i++) {			
			scanf("%d", &que[i]);
			sort_que.push_back(que[i]);
		}

		sort(sort_que.begin(), sort_que.end(), greater<int>());

		while (!sort_que.empty()) {
			while (true) {
				if (sort_que.front() > que.front()) {
					m = m != 0 ? m - 1 : n - 1;
					que.push_back(que.front());
					que.erase(que.begin());
				}
				else if (sort_que.front() == que.front()) {
					if (m != 0) {
						m--;
						n--;
						sort_que.erase(sort_que.begin());
						que.erase(que.begin());
						cnt++;
					}						
					else {
						printf("%d\n", cnt);
						sort_que.clear(); 
						break;
					}
				}
			}
		}
	}
	
	return 0;
}