#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> que;
vector<int> ans;

int main() {
	int n;
	string str;

	scanf("%d", &n);
	que.reserve(n+5);
	ans.reserve(n+5);
	
	cin.ignore(); // 입력버퍼 비움

	for (int i = 0; i < n; i++) {
		getline(cin, str);

		if (!str.compare("pop")) {
			if (que.empty())
				ans.push_back(-1);
			else {
				ans.push_back(que.front());
				que.erase(que.begin());
			}
		}
		else if (!str.compare("size"))
			ans.push_back(que.size());
		else if (!str.compare("empty")) {
			if (que.empty())
				ans.push_back(1);
			else
				ans.push_back(0);
		}
		else if (!str.compare("front")) {
			if (que.empty())
				ans.push_back(-1);
			else 
				ans.push_back(que.front());				
		}
		else if (!str.compare("back")) {
			if (que.empty())
				ans.push_back(-1);
			else
				ans.push_back(que.back());
		}
		else if(str.find("push") != string::npos) {
			str.erase(0, 5);
			que.push_back(atoi(str.c_str()));			
		}
	}
	
	for (vector<int>::iterator i = ans.begin(); i < ans.end(); i++)
		cout << *i << '\n';
	

	return 0;
}