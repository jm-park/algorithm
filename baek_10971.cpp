#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int ans = 210000000, n, w[15][15] = { 0, };
	vector<int>dist;

	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		dist.push_back(i);	// 0, 1, 2, ... , n-1 ����
		for (int j = 0; j < n; j++)
			scanf("%d", &w[i][j]);
	}

	// ������ ����Ͽ� ��ȸ�� �� �ִ� ��� ����� Ž����
	// ��, ���� ������ '���������� �ٽ� ���ư�'�� �ֱ� ������ �������� 1�� �������Ѽ� ������ ������.
	do {
		int i, sum = 0;

		for (i = 0; i < n - 1; i++) {
			if (w[dist[i]][dist[i + 1]] == 0) break; // i->i+1�� ����� 0 �ΰ�� ��ȸ �Ұ�
			else sum += w[dist[i]][dist[i + 1]]; // i->i+1�� ����� ������
		}

		// ��ȸ �߰��� ����� 0�� �����鼭 j->i�� ���ư��� ����� 0�� �ƴ� ���
		if (i >= n - 1 && w[dist[i]][dist[0]] != 0) {
			sum += w[dist[i]][dist[0]];	// ���ư��� ����� ������
			if (sum < ans) ans = sum; // �ּҺ�� ����
		}

	} while (next_permutation(dist.begin()+1, dist.end()));
	
	printf("%d\n", ans);

	return 0;
}