#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stack[100];
int top = -1;
int STACK_SIZE;

void pop() {
	if (top == -1) { printf("Stack Empty\n"); return; }

	top--;
}

void push(char x) {
	if (top >= STACK_SIZE - 1) { printf("Stack FULL\n"); return; }
	top++;
	stack[top] = x;
}

void print() {
	for (int i = top; i >= 0; i--) {
		printf("%c", stack[i]);
	}
	printf("\n");
}

char peek() {
	if (top == -1) {
		printf("Stack Empty\n");
		return NULL;
	}

	return stack[top];
}

void duplicate() {
	if (top == -1) return;

	push(stack[top]);
}

void downRotate(int n) {
	if (n > strlen(stack)) return;

	char temp;
	for (int i = 0; i < n - 1; i++) {
		temp = stack[top - (n - 1) + i + 1];
		stack[top - (n - 1) + i + 1] = stack[top - (n - 1) + i];
		stack[top - (n - 1) + i] = temp;
	}
}

void upRotate(int n) {
	if (n > strlen(stack)) return;

	char temp;
	for (int i = 0; i < n - 1; i++) {
		temp = stack[top - i - 1];
		stack[top - i - 1] = stack[top - i];
		stack[top - i] = temp;
	}
}

int main() {

	int calNum;
	char ch[10];
	char data;
	int num;

	scanf("%d", &STACK_SIZE);
	scanf("%d", &calNum);

	for (int i = 0; i < calNum; i++) {
		scanf("%s", ch);
		getchar();

		if (strcmp(ch, "POP") == 0) {
			pop();
		}
		else if (strcmp(ch, "PUSH") == 0) {
			scanf("%c", &data);
			getchar();
			push(data);
		}
		else if (strcmp(ch, "PEEK") == 0) {
			char res = peek();
			if (res != NULL)	printf("%c\n", res);
		}
		else if (strcmp(ch, "DUP") == 0) {
			duplicate();
		}
		else if (strcmp(ch, "UpR") == 0) {
			scanf("%d", &num);
			upRotate(num);
		}
		else if (strcmp(ch, "DownR") == 0) {
			scanf("%d", &num);
			downRotate(num);
		}
		else if (strcmp(ch, "PRINT") == 0) {
			print();
		}
	}
	return 0;
}
