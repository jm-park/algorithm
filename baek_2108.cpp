#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, x, max = -4005, min = 4005, sum = 0, mode_cnt = 0, mode_num;
	vector<int> num;
	vector<int> mode;
	int cnt_num[8005] = { 0, };

	scanf("%d", &N);
	num.reserve(N);
	mode.reserve(N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &x);
		
		// 중간값을 위함
		num.push_back(x);

		// 산술평균을 위함
		sum += x;

		// 최소값, 최대값 범위를 위함
		if (max < x)
			max = x;
		if (min > x)
			min = x;

		// 최빈값 저장
		int idx = x < 0 ? 8001+x : x;
		cnt_num[idx]++;
		if (mode_cnt < cnt_num[idx]) {
			mode_cnt = cnt_num[idx];
			mode.clear();
			mode.push_back(x);
		}
		else if (mode_cnt == cnt_num[idx]) {
			mode.push_back(x);
		}
	}

	sort(num.begin(), num.end());

	mode_num = mode[0];
	// 최빈값이 여러개인 경우 두번째로 작은 값 선택
	if (mode.size() > 1) {
		sort(mode.begin(), mode.end());
		mode_num = mode[1];
	}
	
	printf("%.0f\n%d\n%d\n%d\n", (double)sum / N, num[N/2], mode_num, max - min);

	return 0;
}