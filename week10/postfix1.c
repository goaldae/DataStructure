#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MAX 100

void push(char*, char);
int priority(char);

int top = 0;
char stack[MAX];

void printOp() {
	if (stack[top] == '$') {
		printf("%c", '+');
		top--;
		return;
	}else if (stack[top] == '%') {
		printf("%c", '-');
		top--;
		return;
	}
	printf("%c", stack[top--]);
}


int oper = 1;

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char in;
		
		stack[0] = 0;
		in = getchar();
		while (in != EOF)
		{
			if (in == 10) {
				while (stack[top])
					printOp();
				puts("");
			}
			else if (in == '(')
				push(stack, in);
			else if (in == ')') {
				while (stack[top] != '(')
					printOp();
				top--;
			}
			else if (in == '+' || in == '-' || in == '*' || in == '/' || in == '>' || in == '<' || in == '!') {
				if (oper == 1) {
					if (in == '+' ) {
						while (priority(stack[top]) >= 6)
							printOp();
						push(stack, '$');
					}
					else if (in == '-') {
						while (priority(stack[top]) >= 6)
							printOp();
						push(stack, '%');
					}
					oper = 0;
				}
				while (priority(stack[top]) >= priority(in))
					printOp();
				push(stack, in);
				oper = 1;
			}
			else if (in == '&' || in == '|') {
				if (in != stack[top]) { //첫번째거일때
					while (priority(stack[top]) >= priority(in)) {
						printOp();
					}
					push(stack, in);
				}
				else {	//두번째꺼일때
					if (stack[top - 1] == stack[top]) {
						while (priority(stack[top]) >= priority(in)) {
							printOp();
						}
						push(stack, in);
					}
					else {
						push(stack, in);
					}

				}
				oper = 1;
			}
			else {
				oper = 0;
				printf("%c", in);
			}
			in = getchar();
		}
	}

	return 0;
}

void push(char *s, char data)
{
	s[++top] = data;
}

int priority(char c)
{
	switch (c) {
	case '$':
		return 6;
	case '%':
		return 6;
	case '!':
		return 6;
	case '*':case '/':
		return 5;
	case '-':case '+':
		return 4;
	case '<':case '>':
		return 3;
	case '&':
		return 2;
	case '|':
		return 1;
	default:
		return 0;
	}
}