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
		vector<int> priority_que;
		int  cnt = 1;

		scanf("%d %d", &n, &m);
		que.resize(n);

		for (int i = 0; i < n; i++) {
			scanf("%d", &que[i]);
			priority_que.push_back(que[i]);
		}

		// 우선순위대로 오름차순 정렬
		sort(priority_que.begin(), priority_que.end(), greater<int>());

		while (true) {
			// 우선순위가 낮은 문서가 앞에 있는 경우 뒤로 보내줌
			if (priority_que.front() > que.front()) {
				// 해당 문서가 입력받은 "원하는 문서"일 경우, 인덱스를 문서의 맨 마지막으로 바꿔줌
				// 해당 문서가 원하는 문서가 아닐경우, "원하는 문서"의 인덱스를 한칸 앞당겨줌
				m = m != 0 ? m - 1 : n - 1;
				que.push_back(que.front());
				que.erase(que.begin());
			}
			// 우선순위에 맞는 문서가 앞에 있는 경우 출력
			else if (priority_que.front() == que.front()) {
				// 해당 문서가 원하는 문서가 아닐 경우, "원하는 문서"의 인덱스를 한칸 앞당겨줌
				if (m != 0) {
					m--;
					n--;
					priority_que.erase(priority_que.begin());
					que.erase(que.begin());
					cnt++;
				}
				// 해당 문서가 입력받은 "원하는 문서"일 경우 그대로 탈출
				else {
					printf("%d\n", cnt);
					break;
				}
			}
		}

	}

	return 0;
}