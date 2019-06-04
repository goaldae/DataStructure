#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top = -1;
int stack[100];


typedef struct graphNode {
	int vertex;
	struct graphNode* link;
}graphNode;

typedef struct graphType {
	int n;
	graphNode *adjList_H[1000];
	int visited[1000];
}graphType;


typedef struct stackNode {
	int data;
	struct stackNode *link;
}stackNode;

void push(int t) {
	top++;
	stack[top] = t;
}

void insertEdge(graphType* g, int u, int v) {

	graphNode* node;
	

	if (u >= g->n || v >= g->n) {
		printf("\n �׷����� ���� �����Դϴ�!");

		return;
	}
	
	node = (graphNode *)malloc(sizeof(graphNode));
	node->vertex = v;
	node->link = g->adjList_H[u];
	g->adjList_H[u] = node;

	
}


int pop() {
	int temp;
	if (top == -1) {
		printf("df");
		return -1;
		
	}
	temp = stack[top];
	top--;
	
	return temp;
}


void DFS(graphType* g, int v) {
	graphNode* w;

	g->visited[v] = 1;
	

	while (v != -1) {
		w = g->adjList_H[v];
		printf(" %d", w->vertex);
		while (w != NULL) { //���� �Ⱦ�� �ִٸ�

			if (g->visited[w->vertex] != 1) { //��������߿� �湮���Ѱ� �ִٸ�
				push(v);
				g->visited[w->vertex] = 1;
				
				v = w->vertex;
				w = g->adjList_H[v];
				printf(" %d", w->vertex);
			}
			else { //�湮�ѰŶ��
				w = w->link;
				printf(" %d", w->vertex);
			}
		}
		v = pop(); //�Ⱦ�� ������ ���ο�� ����� ����
	}

}

int main(void) {

	graphType* g;
	g = (graphType*)malloc(sizeof(graphType));
	g->n = 5;

	for (int i = 0; i < g->n; i++) {
		g->adjList_H[i] = NULL;
	}

	
	insertEdge(g, 0, 2);
	insertEdge(g, 0, 1);
	insertEdge(g, 1, 3);
	insertEdge(g, 1, 2);
	insertEdge(g, 1, 0);

	insertEdge(g, 2, 4);
	insertEdge(g, 2, 3);
	insertEdge(g, 2, 1);
	insertEdge(g, 2, 0);


	insertEdge(g, 3, 2);
	insertEdge(g, 3, 1);
	insertEdge(g, 4, 2);
	
	DFS(g, 0);

	return 0;
}