#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int main() {
	int T, n, pos;
	vector<int> num_arr;
	char arr[400005], func_p[100005];
	scanf("%d", &T);

	while (T--) {
		bool normal = true;
		int pos = 0;

		num_arr.clear();

		scanf("%s %d %s", &func_p, &n, &arr);

		char * tmp = strtok(arr, "[,]");
		while (tmp) {
			num_arr.push_back(stoi(tmp));
			tmp = strtok(NULL, "[,]");
		}

		int point = 0, start = 0, end = n;

		for (int i = 0; func_p[i]; i++) {

			// 정수 배열이 비어있어서 함수를 실행할 수 없는 경우 : error
			if (start == end && func_p[i] == 'D') {
				normal = false;
				break;
			}

			// 함수 실행
			switch (func_p[i]){
				case 'R':
					point = point == start ? end : start;
					break;
				case 'D':
					point = point == start ? ++start : --end;
					break;
			}

		}
		
		if (!normal)
			printf("error\n");
		else {
			printf("[");
			
			if (point == start && start != end) {
				for (int j = start; j < end-1; j++)
					printf("%d,", num_arr[j]);	
				printf("%d", num_arr[end-1]);
			}
			else if(start != end) {				
				for (int j = end-1; j > start; j--)
					printf("%d,", num_arr[j]);
				printf("%d", num_arr[start]);
			}
			
			printf("]\n");
		}

	}

	return 0;
}