#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode { //�ܼ����Ḯ��Ʈ�� ��� ���� ����
	int coef;
	int exp;
	struct ListNode* next;
} listNode;

listNode* createLinkedList(void) { //���� ���Ḯ��Ʈ ���� ����
	listNode* L;


	L = (listNode*)malloc(sizeof(listNode)); //��� ��� �Ҵ�
	L->coef, L->exp, L->next = NULL;

	return L;
}

void add(listNode* L, int c, int e) {
	listNode* newNode;
	listNode* pre;

	newNode = (listNode*)malloc(sizeof(listNode));
	pre = (listNode*)malloc(sizeof(listNode));

	newNode->coef = c;
	newNode->exp = e;

	newNode->next = NULL;

	pre = L;

	if (L->next == NULL) { //���� ����Ʈ�� ������ ��� :
		L->next = newNode;
		return;
	}

	while (pre->next != NULL) pre = pre->next;
	pre->next = newNode;
}

void printList(listNode* L) { //��� ������� ����Ʈ�� ����ϴ� ����
	listNode* p;

	p = L->next;
	while (p != NULL) {
		printf("%d %d ", p->coef, p->exp);
		p = p->next;
	}
}

listNode* addPoly(listNode* A, listNode* B) {
	listNode* R;
	R = createLinkedList();

	listNode* p1 = A->next;
	listNode* p2 = B->next;

	while ((p1 != NULL) && (p2 != NULL)) {
		if (p1->exp > p2->exp) {
			add(R, p1->coef, p1->exp);
			p1 = p1->next;
		}
		else if (p1->exp < p2->exp) {
			add(R, p2->coef, p2->exp);
			p2 = p2->next;
		}
		else {
			int sum = p1->coef + p2->coef;
			if (sum != 0) {
				add(R, sum, p1->exp);
			}
			p1 = p1->next;
			p2 = p2->next;
		}
	}

	while (p1 != NULL) {
		add(R, p1->coef, p1->exp);
		p1 = p1->next;
	}
	while (p2 != NULL) {
		add(R, p2->coef, p2->exp);
		p2 = p2->next;
	}

	return R;
}

int main() {
	listNode* A;
	listNode* B;

	A = createLinkedList();
	B = createLinkedList();

	int n;
	scanf("%d", &n);

	int c, e;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &c, &e);
		add(A, c, e);
	}

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &c, &e);
		add(B, c, e);
	}

	listNode* R = addPoly(A, B);
	printList(R);

	return 0;
}