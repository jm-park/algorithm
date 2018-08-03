#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int T;
	char ps;
	vector<char> stack;

	scanf("%d", &T);
	getchar();

	while (T--) {
		stack.clear();
	
		while((ps = getchar()) != '\n'){

			if (!stack.empty() && stack.back() == '(' && ps == ')')
				stack.pop_back();
			else
				stack.push_back(ps);

		}
		puts(stack.empty() ? "YES" : "NO");
	}

	return 0;
}