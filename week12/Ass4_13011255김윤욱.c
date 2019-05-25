#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct LinkedList{
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

void insert(linkedlist* T, int data) {
	linkedlist* cur = T;
	linkedlist* search = T;
	 
	while (cur != NULL) { //삽입할 자리 탐색
		if (data == cur->data) return;

		search = cur;

		if (data < cur->data) cur = cur->left;
		else cur = cur->right;
	}

	linkedlist* tempT = createNode();  //삽입할 노드 만들기
	tempT->data = data;

	if (T->data == NULL) T->data = data; // 탐색한 자리에 노드 연결
	else if(data < search->data){
		search->left = tempT;
	}
	else {
		search->right = tempT;
	}
	return;
}

int maxNode(linkedlist* T, int data) {
	linkedlist* cur = T;

	while (cur->data != data) {
		if (cur->data > data) cur = cur->left;
		else cur = cur->right;
	}

	cur = cur->left;

	while (cur->right != NULL) {
		cur = cur->right;
	}

	return cur->data;
}

int minNode(linkedlist* T, int data) {
	linkedlist* cur = T;

	while (cur->data != data) {
		if (cur->data > data) cur = cur->left;
		else cur = cur->right;
	}

	cur = cur->right;

	while (cur->left != NULL) {
		cur = cur->left;
	}

	return cur->data;
}
int main(void){
	int input;

	linkedlist* T = createNode();

	printf("트리를 만들기 위해 8-3-10-2-5-14-4-11-16 순으로 입력하세요:\n");

	for (int i = 0; i < 9; i++) {
		scanf("%d", &input);
		insert(T, input);
	}

	printf("기준 노드를 입력하세요:\n");
	scanf("%d", &input);
	printf("기준노드의  좌측서브트리에서  가장 큰 노드는 %d, 우측서브트리에서 가장 작은 노드는 %d 입니다.\n", maxNode(T, input), minNode(T, input));

	//좌 우측 서브 트리가 없는 경우는 구현하지 않음
	
	return 0;
}
