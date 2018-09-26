#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	int phone_n = phone_book.size();

	sort(phone_book.begin(), phone_book.end());

	for (int i = 0; i<phone_n - 1; i++) {
		for (int j = i + 1; j<phone_n; j++) {
			int k, size = phone_book[i].size();
			for (k = 0; k<size; k++)
				if (phone_book[i][k] != phone_book[j][k]) break;
			if (k == size) return false;
		}
	}

	return answer;
}