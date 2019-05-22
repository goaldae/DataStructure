#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct LinkedList{
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

int main(void){
	int input;

	linkedlist* arr[9];

	arr[1] = createNode(20);
	arr[2] = createNode(30);
	arr[3] = createNode(50);
	arr[4] = createNode(70);
	arr[5] = createNode(90);
	arr[6] = createNode(120);
	arr[7] = createNode(130);
	arr[8] = createNode(80);

	arr[6]->left = arr[7];
	arr[6]->right = arr[8];
	
	arr[2]->left = arr[4];
	arr[2]->right = arr[5];

	arr[3]->right = arr[6];
	
	arr[1]->left = arr[2];
	arr[1]->right = arr[3];

	
	scanf("%d", &input);

	if (input >= 9) {
		printf("%d", -1);
	}
	else if (arr[input]->left == NULL && arr[input]->right != NULL) {
		printf("%d %d", arr[input]->data, arr[input]->right->data);
	}
	else if (arr[input]->right == NULL && arr[input]->left != NULL) {
		printf("%d %d", arr[input]->data, arr[input]->left->data);
	}
	else if (arr[input]->right == NULL && arr[input]->left == NULL) {
		printf("%d", arr[input]->data);
	}
	else {
		printf("%d %d %d", arr[input]->data, arr[input]->left->data, arr[input]->right->data);
	}
	
	return 0;
}

