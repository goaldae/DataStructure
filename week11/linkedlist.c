#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int queue[10000];
int rear = 0;
int front = 0;

void printAll(int size) {
	for (int i = 0; i < size; i++) {
		printf(" %d", queue[i]);
	}
	printf("\n");
}

int isFull(int size) {
	if ((rear + 1) % size == front) {
		printf("overflow");
		printAll(size);
		return 1;
	}
	return 0;
}

int isEmpty(int size) {
	if (rear == front) {
		printf("underflow");
		return 1;
	}
	return 0;
}

void insert(int x, int size) {
	if (isFull(size)) exit(1);
	else {
		
		rear = (rear + 1) % size;
		queue[rear] = x;
	}
}

void delete(int size) {
	if (isEmpty(size)) exit(1);
	else {
		front = (front + 1) % size;
		queue[front] = 0;
	}
}



int main(void){
	int size;
	int n;
	char select;
	int input;

	scanf("%d", &size);
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		getchar();
		scanf("%c", &select);
		
	
		switch (select)
		{
		case 'I':			
			scanf("%d", &input);
			insert(input, size);			
			break;
		case 'D':
			delete(size);
			break;
		case 'P':
			printAll(size);
			break;
		default:
			break;
		}
	}

	return 0;
}



