#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
	int a, b;
	double ans;

	scanf("%d %d", &a, &b);
	
	ans = (double)a / b;
	
	// 1. c++ cout�� �Ҽ��� ����
	cout.setf(ios::fixed); //�Ҽ��� �Ʒ� �ڸ��� ��� ����
	cout.precision(9); // ���ϴ� �ڸ���
	cout << ans << endl;

	// 2. c printf�� �Ҽ��� ����
	//printf("%.9lf\n", (double)a / b);
	
	return 0;
}
