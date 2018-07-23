#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
	double n;
	int i, pos = 1;

	scanf("%lf", &n);
	
	for (i = 1;; i++) {
		if (pos >= n)
			break;
		else 
			pos += 6 * i;
		
	}
	printf("%d\n", i);

	return 0;
}
