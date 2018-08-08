#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m, idx = 0, cnt;
	vector<int> nums;

	scanf("%d %d", &n, &m);
	// nums ���� �ʱ�ȭ: 1~n���� ������� ����
	for (int i = 1; i <= n; i++)
		nums.push_back(i);

	idx = m - 1;
	printf("<");
	while (nums.size() > 1) {
		printf("%d, ", nums[idx]);
		nums.erase(nums.begin() + idx);
		idx += m - 1;
		idx %= nums.size();
	}
	printf("%d>\n", nums[0]);

	return 0;
}