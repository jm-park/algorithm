#include <cstdio>
#include <cstdlib>
#include <iostream>

#define MAX_SIZE 100005
int stack[MAX_SIZE] = { 1, };
int seq_idx = 0, stack_top = 0;

using namespace std;

// num�� STACK�� push�ϵ��� �ϴ� �Լ�
int push(int num) {
	stack[++stack_top] = num;
	return 1;
}

// STACK���� top�� pop�ϵ��� �ϴ� �Լ�
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

	// �Է°� ����
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &seq[i]);
	}

	while (seq_idx < n) {
		
		// stack_top ���� seq_idx ���� ������ pop
		if (stack[stack_top] == seq[seq_idx]) {
			ret = pop();
			seq_idx++;
			answer[ans_idx++] = '-';
		}
		// �̹� stack�� ��� ���� ���� ��� stack�� ��Ե� �� ���� pop
		else if (stack_value > n) {
			ret = pop();
			// pop�� ���� ������ ���� �ٸ� ���
			if (ret != seq[seq_idx])
				ret = 0;
			answer[ans_idx++] = '-';
		}
		// stack_top ���� seq_idx ���� �ٸ��� push
		else if (stack[stack_top] != seq[seq_idx]) {
			ret = push(stack_value++);
			answer[ans_idx++] = '+';
		}

		// popȤ�� push�� �̻� ��Ȳ �߰�: NO�� �ش�
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