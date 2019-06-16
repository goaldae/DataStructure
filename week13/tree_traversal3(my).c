#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	
	if (!(T == NULL)) {
		printf("%d ", T->data);
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

linkedlist* findAddress(linkedlist* t, int x) {
	linkedlist* a;
	linkedlist* b;

	if (t == NULL) {
		return NULL;
	}
	if (t->id == x) {
		return t;
	}

	a = findAddress(t->left, x);
	b = findAddress(t->right, x);

	if (a) {
		return a;
	}
	else if (b) {
		return b;
	}
	else {
		return NULL;
	}


}


int main(void) {
	int input1;

	linkedlist* tree;

	tree = createNode(20, 1);
	tree->left = createNode(30, 2);
	tree->right = createNode(50, 3);

	tree->left->left = createNode(70, 4);
	tree->left->right = createNode(90, 5);

	tree->right->right = createNode(120, 6);
	tree->right->right->left = createNode(130, 7);
	tree->right->right->right = createNode(80, 8);

	int input2;

	scanf("%d %d", &input1, &input2);
	
	if (input2 > 8) {
		printf("-1");
	}
	else if (input1 == 1) {
		preOrder(findAddress(tree, input2));
	}
	else if (input1 == 2) {
		inOrder(findAddress(tree, input2));
	}
	else if (input1 == 3) {
		postOrder(findAddress(tree, input2));
	}

	return 0;
}
