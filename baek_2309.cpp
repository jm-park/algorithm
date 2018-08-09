#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int bp = 0, sum = 0, dwarfs[9];

	for (int i = 0; i < 9; i++) {
		scanf("%d", &dwarfs[i]);
		sum += dwarfs[i];
	}
		
	for (int i = 0; i < 9 && bp == 0; i++) {
		for (int j = 0; j < 9; j++) {

			// ���� ����� �ι� �̴� ��� ����
			if (i == j) continue; 
			
			// 2���� �������� �� �������� ���� 100�� ��찡 ��
			if ((sum - dwarfs[i] - dwarfs[j]) == 100) {
				dwarfs[i] = dwarfs[j] = 500;
				bp = 1;
				break;
			} // if�� END

		}  // �ι�° for�� END
	} // ù��° for�� END

	sort(dwarfs, dwarfs + 9);

	for (int k = 0; k < 7; k++)
		printf("%d\n", dwarfs[k]);

	return 0;
}