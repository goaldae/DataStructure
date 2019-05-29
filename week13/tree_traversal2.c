#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int res = 0;

typedef struct LinkedList {
	struct LinkedList* left;
	int id;
	int data;
	struct LinkedList* right;
}linkedlist;

linkedlist* createNode(int data, int id) {
	linkedlist* f;
	f = (linkedlist*)malloc(sizeof(linkedlist));
	f->id = id;
	f->data = data;
	f->left = NULL;
	f->right = NULL;

	return f;
}

void preOrder(linkedlist* T) {
	if (!(T == NULL)){
		res += T->data;
		preOrder(T->left);
		preOrder(T->right);
	}
}

void inOrder(linkedlist* T) {
	if (!(T == NULL)) {
		inOrder(T->left);
		printf("%d ", T->data);
		inOrder(T->right);
	}
}

void postOrder(linkedlist* T) {
	if (!(T == NULL)) {
		postOrder(T->left);
		postOrder(T->right);
		printf("%d ", T->data);
	}
}


int main(void) {
	int input1;
	
	linkedlist* T[9];

	T[1] = createNode(20, 1);
	T[2] = createNode(30, 2);
	T[3] = createNode(50, 3);
	T[4] = createNode(70, 4);
	T[5] = createNode(90, 5);
	T[6] = createNode(120, 6);
	T[7] = createNode(130, 7);
	T[8] = createNode(80, 8);

	T[6]->left = T[7];
	T[6]->right = T[8];

	T[3]->right = T[6];
	
	T[2]->left = T[4];
	T[2]->right = T[5];

	T[1]->right = T[3];
	T[1]->left = T[2];

	int input2;

	scanf("%d", &input2);

	if (input2 > 8) {
		printf("-1");
	}
	else  {
		preOrder(T[input2]);
		printf("%d", res);
	}
	


	return 0;
}

