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

			// 같은 사람을 두번 뽑는 경우 제외
			if (i == j) continue; 
			
			// 2명을 제외했을 때 나머지의 합이 100인 경우가 답
			if ((sum - dwarfs[i] - dwarfs[j]) == 100) {
				dwarfs[i] = dwarfs[j] = 500;
				bp = 1;
				break;
			} // if문 END

		}  // 두번째 for문 END
	} // 첫번째 for문 END

	sort(dwarfs, dwarfs + 9);

	for (int k = 0; k < 7; k++)
		printf("%d\n", dwarfs[k]);

	return 0;
}