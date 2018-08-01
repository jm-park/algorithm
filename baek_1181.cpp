#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int n;
	string str;
	vector<string> ans;
	vector<string>::iterator s;

	scanf("%d", &n);

	cin >> str;
	ans.push_back(str);
	n--; 

	while (n--) {
		int skip = 0;

		cin >> str;

		for (s = ans.begin(); s < ans.end(); s++) {
			if (str.compare(*s) == 0)
				skip = 1;
			else if (str.length() < (*s).length()) // str�� vector�� s��ġ�� ���ڿ����� ���̰� ����
				break;
			else if (str.length() == (*s).length()) {
				if (str.compare(*s) < 0) // str�� ���������� ���� ��
					break;
			}
		}

		if(!skip)
			ans.insert(s, str);
	}

	for (vector<string>::iterator i = ans.begin(); i < ans.end(); i++)
		cout << *i << '\n';

	return 0;
}