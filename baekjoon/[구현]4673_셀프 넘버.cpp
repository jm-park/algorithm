#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

vector<int> selfnumber;

// 생성자 집합
int ctor(int num) {	
	int next_num = num;

	while (num != 0) {
		next_num += num % 10;
		num /= 10;
	}
	
	return next_num;
}

int main() {
	// 1: 셀프넘버, 0: 셀프넘버가 아닌 수
	selfnumber.assign(20005, 1); // selfnumber배열의 모든값을 1로 초기화
	
	for (int i = 1; i <= 10000; i++) {
		selfnumber[ctor(i)] = 0;
		if (selfnumber[i])
			printf("%d\n", i);
	}

	return 0;
}