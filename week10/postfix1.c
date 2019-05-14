#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>
#define MAX 100

typedef struct Oper{
	char data;
	int pri;
}oper;

int top = 0;

int priority(char* input, int j)
{
	if (input[j] == '+' || input[j] == '-') {
		if (j == 0 || input[j - 1] == '!' || input[j - 1] == '*' || input[j - 1] == '/' || input[j - 1] == '>'
			|| input[j - 1] == '<' || input[j - 1] == '&' || input[j - 1] == '|' || input[j - 1] == '+' || input[j - 1] == '-') {
			return 6;
		}
		else
		{
			return 4;
		}
	}
	else
	{
		switch (input[j]) {
		case '!':
			return 6;
		case '*':case '/':
			return 5;
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
	
}
void push(oper* stack, char* input, int j)
{
	top++;
	stack[top].data = input[j];
	stack[top].pri = priority(input, j);

}

void printStack(oper* stack) {
	while (stack[top].data!=' ')
	{
		if (stack[top].data == '(' || stack[top].data == ')') {
			top--;
		}
		else {
			printf("%c", stack[top].data);
			top--;
		}
	}
}

int main(void)
{
	char input[100];
	int n;

	scanf("%d", &n); //반복횟수

	for (int i = 0; i < n; i++) {
		
		scanf("%s", input);
		
		oper stack[MAX];
		stack[0].data = ' ';
		stack[0].pri = 0;
		
		for (int j = 0; j < strlen(input); j++) {
			if (j == strlen(input)-1) {
				if (input[j] == '(' || input[j] == ')') {
					printStack(stack);
				}
				else
				{
					printf("%c", input[j]);
					printStack(stack);
				}
				printf("\n");
							
			}
			else if (input[j] == '(')
				push(stack, input, j);
			else if (input[j] == ')') {
				while (stack[top].data != '(')
					printf("%c", stack[top--].data);
				top--;
			}
			else if (input[j] == '+' || input[j] == '-' || input[j] == '*' || input[j] == '/' || input[j] == '>' || input[j] == '<' || input[j] == '!') {
				while (stack[top].pri >= priority(input, j))
					printf("%c", stack[top--].data);
				push(stack, input, j);
				
			}
			else if (input[j] == '&' || input[j] == '|') {
				if (input[j] != stack[top].data) { //첫번째거일때
					while (stack[top].pri >= priority(input, j)) {
						printf("%c", stack[top--].data);
					}
					push(stack, input, j);
				}
				else {	//두번째꺼일때
					if (stack[top - 1].data == stack[top].data) {
						while (stack[top].pri >= priority(input, j)) {
							printf("%c", stack[top--].data);
						}
						push(stack, input, j);
					}
					else {
						push(stack, input, j);
					}

				}
			
			}
			else {
				
				printf("%c", input[j]);
				if (stack[top].pri == 6) {
					printf("%c", stack[top--].data);
				}
			}
		}	
	}

	return 0;
}



