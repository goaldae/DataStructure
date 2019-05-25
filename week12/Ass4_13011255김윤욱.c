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
	 
	while (cur != NULL) { //������ �ڸ� Ž��
		if (data == cur->data) return;

		search = cur;

		if (data < cur->data) cur = cur->left;
		else cur = cur->right;
	}

	linkedlist* tempT = createNode();  //������ ��� �����
	tempT->data = data;

	if (T->data == NULL) T->data = data; // Ž���� �ڸ��� ��� ����
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

	printf("Ʈ���� ����� ���� 8-3-10-2-5-14-4-11-16 ������ �Է��ϼ���:\n");

	for (int i = 0; i < 9; i++) {
		scanf("%d", &input);
		insert(T, input);
	}

	printf("���� ��带 �Է��ϼ���:\n");
	scanf("%d", &input);
	printf("���س����  ��������Ʈ������  ���� ū ���� %d, ��������Ʈ������ ���� ���� ���� %d �Դϴ�.\n", maxNode(T, input), minNode(T, input));

	//�� ���� ���� Ʈ���� ���� ���� �������� ����
	
	return 0;
}
