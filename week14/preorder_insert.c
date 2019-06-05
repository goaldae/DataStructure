#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LinkedList {
	struct LinkedList* left;
	int data;
	struct LinkedList* right;
}linkedlist;

linkedlist* createNode() {
	linkedlist* f;
	f = (linkedlist*)malloc(sizeof(linkedlist));
	f->data = NULL;
	f->left = NULL;
	f->right = NULL;

	return f;
}

linkedlist* preOrder(linkedlist* T , int data) {	
	if (T == NULL) { //마지막까지 갔는데 없을때
		return NULL;
	}
	if (T->data == data) { //찾았을 때
		
		return T;
	}
	
	linkedlist* l = preOrder(T->left, data);
	linkedlist* r = preOrder(T->right, data);
	
	if (l != NULL) {
		return l;
	}
	if (r != NULL) {
		return r;
	}
}

void makeTree(linkedlist* T, int data, int l, int r) {
	linkedlist* lnode = createNode();
	linkedlist* rnode = createNode();
	lnode->data = l;
	rnode->data = r;

	if (T->data == NULL) {
		T->data = data;
		T->left = lnode;
		T->right = rnode;
		return;
	}

	linkedlist* temp = preOrder(T, data);
	
	if(l != 0) temp->left = lnode;
	if(r != 0) temp->right = rnode;
}


int main(void) {
	int input;
	int n;
	int a, b, c;
	char sinput[1000];
	char arr[1000];

	linkedlist* T = createNode();
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		makeTree(T, a, b, c);
	}

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		linkedlist* tempT = T;
		scanf("%s", sinput);
		printf("%d ", tempT->data);
		for (int j = 0; j < strlen(sinput); j++) {
			if (sinput[j]=='L') {
				tempT = tempT->left;
				printf("%d ", tempT->data);
			}
			else {
				tempT = tempT->right;
				printf("%d ", tempT->data);
			}
		}
		printf("\n");
	}
	
	return 0;
}
