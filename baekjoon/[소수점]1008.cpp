#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
	int a, b;
	double ans;

	scanf("%d %d", &a, &b);
	
	ans = (double)a / b;
	
	// 1. c++ cout로 소수점 지정
	cout.setf(ios::fixed); //소수점 아래 자리수 출력 지정
	cout.precision(9); // 원하는 자리수
	cout << ans << endl;

	// 2. c printf로 소수점 지정
	//printf("%.9lf\n", (double)a / b);
	
	return 0;
}
