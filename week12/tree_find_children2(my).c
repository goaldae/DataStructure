#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct LinkedList {
	struct LinkedList* left;
	int data;
	struct LinkedList* right;
}linkedlist;

linkedlist* createNode(int data) {
	linkedlist* f;
	f = (linkedlist*)malloc(sizeof(linkedlist));
	f->data = data;
	f->left = NULL;
	f->right = NULL;

	return f;
}


linkedlist* findAddress(linkedlist* t, int x) {
	linkedlist* a;
	linkedlist* b;

	if (t == NULL) {
		return NULL;
	}
	if (t->data == x) {
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
	int input;



	linkedlist*f1 = createNode(20);
	linkedlist*f2 = createNode(30);
	linkedlist*f3 = createNode(50);
	linkedlist*f4 = createNode(70);
	linkedlist*f5 = createNode(90);
	linkedlist*f6 = createNode(120);
	linkedlist*f7 = createNode(130);
	linkedlist*f8 = createNode(80);


	f6->left = f7;
	f6->right = f8;

	f2->left = f4;
	f2->right = f5;

	f3->right = f6;

	f1->left = f2;
	f1->right = f3;


	scanf("%d", &input);


	linkedlist* temp = findAddress(f1, input);
	printf("%d", temp->data);
	

	return 0;
}
