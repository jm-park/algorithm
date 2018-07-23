#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

string croatian_alphabets[] = {
	"dz=", "c=", "c-", "d-", "lj", "nj", "s=", "z="
};

int main() {
	string word;
	int word_length, pos;

	getline(cin, word);
	word_length = word.length();
	
	for (int i = 0; i < 8; i++) {
		// 입력받은 word에 크로아티안 알파벳이 속해있는지 확인
		if ((pos = word.find(croatian_alphabets[i])) != string::npos) {
			// word 알파벳 개수 update
			word_length = word_length - croatian_alphabets[i].length() + 1;			
			// 이미 구해진 크로아티아알파벳 문자 공란으로 변경 (중복카운트를 피하기 위함)
			word.replace(pos, croatian_alphabets[i].length(), " ");
			i--; // 같은 크로아티아알파벳 문자가 존재할 수 있기 때문에 다시 해당 문자 비교
		}
	}

	printf("%d\n", word_length);

	return 0;
}