#include <iostream>
using namespace std;

int main() {
	int t, a, b, ans;
	int reward_2017[] = { 0, 500,300,200,50,30,10 }, reward_2018[] = { 0, 512,256,128,64,32 }, people_2017[] = { 0, 1,3,6,10,15,21 }, people_2018[] = { 0, 1,3,7,15,31 };

	scanf("%d", &t);

	while (t--) {
		ans = 0;
		scanf("%d %d", &a, &b);

		for (int i = 0; i < 6; i++) {
			if (people_2017[i] < a && a <= people_2017[i + 1]) {
				ans += reward_2017[i + 1];
				break;
			}
		}
			
		for (int i = 0; i < 5; i++) {
			if (people_2018[i] < b && b <= people_2018[i + 1]) {
				ans += reward_2018[i + 1];
				break;
			}
		}

		printf("%d\n", ans * 10000);
	}
		
		
	return 0;
}