#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode { //단순연결리스트의 노드 구조 정의
	int data;
	struct ListNode* next;
} listNode;

listNode* createLinkedList(void) { //공백 연결리스트 생성 연산
	listNode* L;

	L = (listNode*)malloc(sizeof(listNode)); //헤드 노드 할당
	L->data, L->next = NULL;
	
	return L;
}

void add(listNode* L, int c) {
	listNode* newNode;
	listNode* pre;

	pre = L->next;
	newNode = createLinkedList();
	newNode->data = c;
	newNode->next = NULL;

	if (L->next == NULL) { //현재 리스트가 공백인 경우 :
		L->next = newNode;
		return;
	}

	while (pre->next != NULL) pre = pre->next;
	pre->next = newNode;
}

void printList(listNode* L) { //노드 순서대로 리스트를 출력하는 연산
	listNode* p;
	
	p = L->next->next;
	if (p == NULL) {
		printf("0");
	}
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
}

int subset(listNode* A, listNode* B) {
	listNode* pA;
	listNode* pB;
	pA = A;
	pB = B;

	while(1){
		if (pB->data < pA->data) { //B의 원소가 작을 때
			if (pB->next == NULL) return pA->data;
			pB = pB->next;			
		}
		else if (pA->data == pB->data) { // 원소가 서로 같을 때
			if (pA->next == NULL) return 0;
			pA = pA->next;		
		}
		else if (pB->data > pA->data) { //B의 원소가 더 클때
			return pA->data;
		}
	}
}

listNode* _union(listNode* A, listNode* B) {
	listNode* p1 = A;
	listNode* p2 = B;
	listNode* res = createLinkedList();
	
	while (p1 != NULL && p2 != NULL) {
		if (p1->data == p2->data) {
			add(res, p1->data);

			p1 = p1->next;
			p2 = p2->next;

		}
		else if (p2->data > p1->data) {
			add(res, p1->data);
			p1 = p1->next;
		}
		else if (p1->data > p2->data) {
			add(res, p2->data);
			p2 = p2->next;
		}
	}
	
	if (p1 == NULL) {
		while (p2 != NULL) {
			add(res, p2->data);
			p2 = p2->next;
		}
		
	}

	if (p2 == NULL) {
		while (p1 != NULL) {
			add(res, p1->data);
			p1 = p1->next;
		}
	}

	return res;
}
listNode* intersection(listNode* A, listNode* B) {
	listNode* p1 = A;
	listNode* p2 = B;
	listNode* res = createLinkedList();

	while (p1 != NULL && p2 != NULL) {
		if (p1->data == p2->data) {
			add(res, p1->data);

			p1 = p1->next;
			p2 = p2->next;
		}
		else if (p2->data > p1->data) {
			p1 = p1->next;
		}
		else if (p1->data > p2->data) {
		
			p2 = p2->next;
		}
	}
	return res;
}


int main() {
	listNode* A;
	listNode* B;
	
	A = createLinkedList();
	B = createLinkedList();

	int n;
	scanf("%d", &n);
	
	int c;
	for (int i = 0; i < n; i++) {
		scanf("%d", &c);
		add(A, c);
	}

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &c);
		add(B, c);
	}
;
	printList(_union(A, B));
	printf("\n");
	printList(intersection(A, B));
	
	return 0;
}