#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int element;

typedef struct stackNode {
	element data;
	struct stackNode *link;
}stackNode;

stackNode*top;

void push(element item) {
	stackNode * newNode = (stackNode*)malloc(sizeof(stackNode));

	newNode->data = item;
	newNode->link = top;
	top = newNode;
}

element  pop() {
	element item;
	stackNode *temp = top;
	if (top == NULL) {
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else {
		item = temp->data;
		top = temp->link;
		free(temp);
		return item;
	}
}

element peek() {
	element item;
	if (top == NULL) {
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else {
		item = top->data;
		return item;
	}
}
void del() {
	stackNode * temp;
	if (top == NULL) {
		printf("\n\n Stack is empty !\n");
	}
	else {
		temp = top;
		top = top->link;
		free(temp);
	}
}
void printStack() {
	stackNode * p = top;
	printf("\n STACK [");
	while (p) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf("] ");
}

//���� ǥ����� ����� �Լ� ����
void infix_to_postfix(char *exp) {

	char symbol;
	int i, length = strlen(exp);
	top = NULL;

	for (i = 0;i < length + 1;i++) {
		symbol = exp[i];
		if (symbol == NULL) {
			while (top) {
				printf("%c ", pop());
			}
		}
		else if (symbol != '+' && symbol != '-' && symbol != '*' && symbol != '/' && symbol != '(' && symbol != ')') {
			printf("%c ", symbol);
		}
		else {
			switch (symbol) {
			case '+': push(symbol); break;
			case '-': push(symbol); break;
			case '*': push(symbol);break;
			case '/': push(symbol);break;
			case ')': printf("%c ", pop()); break;
			}
		}
	}
}
//���� ǥ����� ����ϴ� ����
element evalPostfix(char *exp)
{
	int opr1, opr2, value, i = 0;
	int length = strlen(exp);
	char symbol;
	top = NULL;

	for (i = 0; i < length;i++) {
		symbol = exp[i];
		if (symbol != '+' && symbol != '-' && symbol != '*' && symbol != '/') {
			//char���̱⶧����  -'0'�� ���ָ� ���ڷ� ��ȯ�� �����ϴ�. �ٷ� �Ұ�쿡 ���� �ٸ������ �Ǿ������.
			value = symbol - '0';
			push(value);
		}
		else {
			opr2 = pop();
			opr1 = pop();
			switch (symbol) {
			case '+': push(opr1 + opr2); break;
			case '-': push(opr1 - opr2); break;
			case '*': push(opr1*opr2); break;
			case '/': push(opr1 / opr2); break;
			}
		}
	}
	return pop();
}
void main(void) {
	int result;
	int n;

	scanf("%d", &n);
	
	char express[100];

	for (int i = 0; i < n; i++) {
		scanf("%s", express);
		result = evalPostfix(express);
		printf("%d\n", result);
	}
	 
	getchar();
}

