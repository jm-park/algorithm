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

		// �켱������� �������� ����
		sort(priority_que.begin(), priority_que.end(), greater<int>());

		while (true) {
			// �켱������ ���� ������ �տ� �ִ� ��� �ڷ� ������
			if (priority_que.front() > que.front()) {
				// �ش� ������ �Է¹��� "���ϴ� ����"�� ���, �ε����� ������ �� ���������� �ٲ���
				// �ش� ������ ���ϴ� ������ �ƴҰ��, "���ϴ� ����"�� �ε����� ��ĭ �մ����
				m = m != 0 ? m - 1 : n - 1;
				que.push_back(que.front());
				que.erase(que.begin());
			}
			// �켱������ �´� ������ �տ� �ִ� ��� ���
			else if (priority_que.front() == que.front()) {
				// �ش� ������ ���ϴ� ������ �ƴ� ���, "���ϴ� ����"�� �ε����� ��ĭ �մ����
				if (m != 0) {
					m--;
					n--;
					priority_que.erase(priority_que.begin());
					que.erase(que.begin());
					cnt++;
				}
				// �ش� ������ �Է¹��� "���ϴ� ����"�� ��� �״�� Ż��
				else {
					printf("%d\n", cnt);
					break;
				}
			}
		}

	}

	return 0;
}