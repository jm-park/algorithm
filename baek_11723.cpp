#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int m, num, S[21] = { 0, };
	char func[10];

	scanf("%d", &m);

	while (m--) {
		scanf("%s", func);

		if (!strcmp(func, "all")) {
			for (int i = 0; i < 21; i++)
				S[i] = 1;
			continue;
		}
		else if (!strcmp(func, "empty")) {
			for (int i = 0; i < 21; i++)
				S[i] = 0;
			continue;
		}
		
		scanf("%d", &num);

		if (!strcmp(func, "add"))
			S[num] = 1;
		else if (!strcmp(func, "check"))
			S[num] == 1 ? printf("1\n") : printf("0\n");
		else if (!strcmp(func, "remove") && S[num] == 1)
			S[num] = 0;
		else if (!strcmp(func, "toggle"))
			S[num] = S[num] == 1 ? 0 : 1;
	}

	return 0;
}