#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode { //�ܼ����Ḯ��Ʈ�� ��� ���� ����
	struct ListNode* prev;
	char elem[10];
	struct ListNode* next;
} listNode;

listNode* createLinkedList(void) { //���� ���Ḯ��Ʈ ���� ����
	listNode* L;
	listNode* T;

	L = (listNode*)malloc(sizeof(listNode)); //��� ��� �Ҵ�
	T = (listNode*)malloc(sizeof(listNode));
	L->prev = NULL;
	T->next = NULL;

	L->next = T; //���� ����Ʈ�̹Ƿ� NULL ����
	T->prev = L;

	return L;
}

void add(listNode* L, int j, char* x) {
	listNode* newNode;
	listNode* pre;

	newNode = (listNode*)malloc(sizeof(listNode));
	pre = (listNode*)malloc(sizeof(listNode));

	strcpy(newNode->elem, x);
	newNode->next, newNode->prev = NULL;

	pre = L;

	for (int i = 0; i < j - 1; i++) {
		pre = pre->next;
		if (pre->next == NULL) {
			printf("invalid position\n");
			return;
		}

	}
	newNode->next = pre->next;
	pre->next->prev = newNode;

	pre->next = newNode;
	newNode->prev = pre;
}

void delete(listNode* L, int j) {
	listNode* old;

	old = L->next;

	if (old->next == NULL) {
		printf("invalid position\n");
		return;
	}

	for (int i = 0; i < j - 1; i++) {
		old = old->next;
		if (old->next == NULL) {
			printf("invalid position\n");
			return;
		}
	}

	old->prev->next = old->next;
	old->next->prev = old->prev;
	free(old);
}

char* get(listNode* L, int j) {
	listNode* old;

	old = L->next;

	if (old->next == NULL) return "invalid position";

	for (int i = 0; i < j - 1; i++) {
		old = old->next;
		if (old->next == NULL) return "invalid position";
	}

	return old->elem;
}

void printList(listNode* L) { //��� ������� ����Ʈ�� ����ϴ� ����
	listNode* p;

	p = L->next;
	while (p->next != NULL) {
		printf("%s", p->elem);
		p = p->next;
	}
}

int main() {
	listNode* L;
	L = createLinkedList();
	int n;
	char ch;
	scanf("%d", &n);
	int j;
	char e[100];

	for (int i = 0; i < n; i++) {
		getchar();
		scanf("%c", &ch);

		switch (ch) {
		case 'A':
			scanf("%d %s", &j, e);
			add(L, j, e);
			break;
		case 'D':
			scanf("%d", &j);
			delete(L, j);
			break;
		case 'G':
			scanf("%d", &j);
			printf("%s\n", get(L, j));
			break;
		case 'P':
			printList(L);
			printf("\n");
			break;
		default:
			break;
		}
	}

	return 0;
}