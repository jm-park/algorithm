#include <cstdio>
#include <cstdlib>
#include <iostream>

#define MAX_SIZE 100005
int stack[MAX_SIZE] = { 1, };
int seq_idx = 0, stack_top = 0;

using namespace std;

// num을 STACK에 push하도록 하는 함수
int push(int num) {
	stack[++stack_top] = num;
	return 1;
}

// STACK에서 top을 pop하도록 하는 함수
int pop() {
	if (stack_top != -1) 
		return stack[stack_top--];
	else
		return 0;
}

int main() {
	int n;
	int seq[MAX_SIZE];
	char answer[MAX_SIZE*2] = {'+', 0, };
	int ans_idx = 1;
	int stack_value = 2;
	int ret;

	// 입력값 받음
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &seq[i]);
	}

	while (seq_idx < n) {
		
		// stack_top 값과 seq_idx 값이 같으면 pop
		if (stack[stack_top] == seq[seq_idx]) {
			ret = pop();
			seq_idx++;
			answer[ans_idx++] = '-';
		}
		// 이미 stack에 모든 값을 넣은 경우 stack이 비게될 때 까지 pop
		else if (stack_value > n) {
			ret = pop();
			// pop한 값이 수열의 값과 다른 경우
			if (ret != seq[seq_idx])
				ret = 0;
			answer[ans_idx++] = '-';
		}
		// stack_top 값과 seq_idx 값이 다르면 push
		else if (stack[stack_top] != seq[seq_idx]) {
			ret = push(stack_value++);
			answer[ans_idx++] = '+';
		}

		// pop혹은 push중 이상 상황 발견: NO에 해당
		if (!ret)
			break;
	}

	if (ret) {
		for (int i = 0; answer[i]; i++)
			printf("%c\n", answer[i]);
	}
	else
		printf("NO\n");

	return 0;
}