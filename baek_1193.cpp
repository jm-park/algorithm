#include <iostream>

using namespace std;

int main() {

	int line_num, n, sum = 0;

	scanf("%d", &n);

	for (line_num = 1; sum < n; line_num++)
		sum += line_num;

	line_num--;

	if (line_num % 2) // È¦¼ö
		printf("%d/%d\n", sum - n + 1, line_num - sum + n);
	else // Â¦¼ö
		printf("%d/%d\n", line_num - sum + n, sum - n + 1);

	return 0;
}