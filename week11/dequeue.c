#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct LinkedList{
	struct LinkedList* left;
	int data;
	struct LinkedList* right;
}linkedlist;

linkedlist* rear = NULL;
linkedlist* front = NULL;

void add_front(linkedlist* D, int x) {

	if (rear == NULL && front == NULL) { //첫 원소일때
		D = (linkedlist*)malloc(sizeof(linkedlist));
		D->left = NULL;
		D->right = NULL;
		D->data = x;
		rear = D;
		front = D;
		
	}
	else {
		linkedlist* new;
		new = (linkedlist*)malloc(sizeof(linkedlist));
		new->data = x;
		new->right = front;
		new->left = NULL;

		front->left = new;
		front = new;
	}
	
}

void add_rear(linkedlist* D, int x) {

	if (rear == NULL && front == NULL) { //첫 원소일때
		D = (linkedlist*)malloc(sizeof(linkedlist));
		D->left = NULL;
		D->right = NULL;
		D->data = x;
		rear = D;
		front = D;

	}
	else {
		linkedlist* new;
		new = (linkedlist*)malloc(sizeof(linkedlist));
		new->data = x;
		new->right = NULL;
		new->left = rear;

		rear->right = new;
		rear = new;
	}

}

void delete_front(linkedlist* D) {

	if (rear == NULL && front == NULL) { //첫 원소일때
		printf("underflow\n");
		exit(1);
	}
	else if(rear!=front){
		front = front->right;
		front->left = NULL;
	}
	else {
		D = NULL;
		front = NULL;
		rear = NULL;
	}

}

void delete_rear(linkedlist* D) {

	if (rear == NULL && front == NULL) { //첫 원소일때
		printf("underflow\n");
		exit(1);
	}
	else if (rear != front) {
		rear = rear->left;
		rear->right = NULL;
	}
	else {
		D = NULL;
		front = NULL;
		rear = NULL;
	}

}

void printAll(linkedlist* D) {
	linkedlist* cur = front;
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->right;
	}
	printf("\n");
}

int main(void){
	
	int n;
	char select[10];
	int input;

	linkedlist* D = NULL;
	
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		getchar();
		scanf("%s", select);
	
		if (strcmp(select, "AF")==0) {

			scanf("%d", &input);
			add_front(D, input);
			
			
		}else if (strcmp(select, "AR") == 0) {
			scanf("%d", &input);
			add_rear(D, input);
		}
		else if (strcmp(select, "DF") == 0) {
			delete_front(D);
		}
		else if (strcmp(select, "DR") == 0) {
			delete_rear(D);
		}
		else if (strcmp(select, "P") == 0) {
			printAll(D);
		}
	
		
	}

	return 0;
}
