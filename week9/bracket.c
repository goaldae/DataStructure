#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stack[1000];
int top = -1;
int STACK_SIZE;

void pop() {
	if (top == -1) { return; }

	top--;
}

void push(char x) {
	if (top >= STACK_SIZE-1) { return; }
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
		
		return 'd'; 
	}

	return stack[top];
}

void duplicate() {
	if (top == -1) return;

	push(stack[top]);
}

void downRotate(int n) {
	if (n >= STACK_SIZE) return;
	
	char temp;
	for (int i = 0; i < n - 1; i++) {
		temp = stack[top - (n - 1) + i + 1];
		stack[top - (n - 1) + i + 1] = stack[top - (n - 1) + i];
		stack[top - (n - 1) + i] = temp;
	}
}

void upRotate(int n) {
	if (n >= STACK_SIZE) return;

	char temp;
	for (int i = 0; i < n - 1; i++) {
		temp = stack[top - i - 1];
		stack[top - i - 1] = stack[top - i];
		stack[top - i] = temp;
	}	
}

int main() {
	char cal[1000];
	int n = 0;
	scanf("%[^\n]", cal);
	STACK_SIZE = 1000;

	for (int i = 0; i < strlen(cal); i++) {
		if (cal[i] == '(' || cal[i] == '{' || cal[i] == '[' || cal[i] == ')' || cal[i] == '}' || cal[i] == ']') {
			n++;
		}
	}
	char data;
	for (int i = 0; i < strlen(cal); i++) {
		if (cal[i] == '(' || cal[i] == '{' || cal[i] == '[') {
			push(cal[i]);
		}else if (cal[i] == ')' || cal[i] == '}' || cal[i] == ']') {
			data = peek(); //½ºÅÃ
			
			if (cal[i] == '}') {
				if (data != '{') {
					printf("Wrong_%d", n);
					return 0;
				}
			}else if (cal[i] == ']') {
				if (data != '[') {
					printf("Wrong_%d", n);
					return 0;
				}
				
			}else if(cal[i] == ')') {
				if (data != '(') {
					printf("Wrong_%d", n);
					return 0;
				}
			}
			pop();

		}
	}
	if (top > -1) {
		printf("Wrong_%d", n);
		return 0;
	}
	printf("OK_%d", n);

	return 0;
}
