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
		// �Է¹��� word�� ũ�ξ�Ƽ�� ���ĺ��� �����ִ��� Ȯ��
		if ((pos = word.find(croatian_alphabets[i])) != string::npos) {
			// word ���ĺ� ���� update
			word_length = word_length - croatian_alphabets[i].length() + 1;			
			// �̹� ������ ũ�ξ�Ƽ�ƾ��ĺ� ���� �������� ���� (�ߺ�ī��Ʈ�� ���ϱ� ����)
			word.replace(pos, croatian_alphabets[i].length(), " ");
			i--; // ���� ũ�ξ�Ƽ�ƾ��ĺ� ���ڰ� ������ �� �ֱ� ������ �ٽ� �ش� ���� ��
		}
	}

	printf("%d\n", word_length);

	return 0;
}