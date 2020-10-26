#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int N;
	string str;
	vector<int> que;

	scanf("%d", &N);
	getchar();
	while (N--) {
		getline(cin, str);

		if (str.find("push_back") != string::npos) {
			str.erase(0, 10);
			que.push_back(stoi(str));
		}
		else if (str.find("push_front") != string::npos) {
			str.erase(0, 10);
			que.insert(que.begin(), stoi(str));
		}
		else if (str.find("pop_front") != string::npos) {
			if (que.empty())
				printf("-1\n");
			else {
				printf("%d\n", que.front());
				que.erase(que.begin());
			}
		}
		else if (str.find("pop_back") != string::npos) {
			if (que.empty())
				printf("-1\n");
			else {
				printf("%d\n", que.back());
				que.pop_back();
			}
		}
		else if (str.find("size") != string::npos) {
			que.empty() ? printf("0\n") : printf("%d\n", que.size());
		}
		else if (str.find("empty") != string::npos) {
			que.empty() ? printf("1\n") : printf("0\n");
		}
		else if (str.find("front") != string::npos) {
			que.empty() ? printf("-1\n") : printf("%d\n", que.front());
		}
		else if (str.find("back") != string::npos) {
			que.empty() ? printf("-1\n") : printf("%d\n", que.back());
		}

	}
	return 0;
}