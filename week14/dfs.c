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

	if (top >= 100) {
		printf("\n    Stack overflow.");
		return;
	}

	stack[++top] = t;
}

void insertEdge(graphType* g, int u, int v) {

	graphNode* node;
	graphNode* node2;

	if (u >= g->n || v >= g->n) {
		printf("\n 그래프에 없는 정점입니다!");

		return;
	}

	node = (graphNode *)malloc(sizeof(graphNode));
	node->vertex = v;
	node->link = g->adjList_H[u];
	g->adjList_H[u] = node;

	node2 = (graphNode *)malloc(sizeof(graphNode));
	node2->vertex = u;
	node2->link = g->adjList_H[v];
	g->adjList_H[v] = node2;
}


int pop() {
	int item;
	stackNode* temp = top;

	if (top == NULL) {
		printf("stack is empty!\n");
		return -1;
	}
	else {
		item = temp->data;
		top = temp->link;
		free(temp);
		return item;
	}
}


void DFS(graphType* g, int v) {
	graphNode* w;
	top = NULL;
	g->visited[v] = 1;
	printf(" %d", v);

	while (v != -1) {
		
		w = g->adjList_H[v];
		while (w) {
			if (!(g->visited[w->vertex])) {
				push(v);
				g->visited[w->vertex] = 1;
				printf(" %d", w->vertex);
				v = w->vertex;
				w = g->adjList_H[v];
			}
			else w = w->link;
		}
		v = pop();
	}

}

int main(void) {

	graphType* g;
	g = (graphType*)malloc(sizeof(graphType));
	g->n = 5;
	
	insertEdge(g, 0, 1);
	insertEdge(g, 0, 2);
	insertEdge(g, 1, 2);
	insertEdge(g, 1, 3);
	insertEdge(g, 2, 3);
	insertEdge(g, 2, 4);

	DFS(g, 0);

	return 0;
}

