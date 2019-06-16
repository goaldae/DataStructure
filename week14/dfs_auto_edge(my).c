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
	graphNode* node2;


	if (u >= g->n || v >= g->n) {
		printf("\n 그래프에 없는 정점입니다!");

		return;
	}

	node = (graphNode *)malloc(sizeof(graphNode));
	node->vertex = v;
	node->link = NULL;

	graphNode* old = NULL;
	graphNode* cur = g->adjList_H[u];

	while (cur != NULL && cur->vertex < v) {
		old = cur;
		cur = cur->link;
	}

	if (old == NULL) {
		node->link = cur;
		g->adjList_H[u] = node;
	}
	else {
		old->link = node;
		node->link = cur;
	}

	node2 = (graphNode *)malloc(sizeof(graphNode));
	node2->vertex = u;
	node2->link = NULL;

	
	old = NULL;
	cur = g->adjList_H[v];
		
	while (cur != NULL && cur->vertex < u) {
		old = cur;
		cur = cur->link;
	}
	if (old == NULL) {
		node2->link = cur;
		g->adjList_H[v] = node2;
	}
	else {
		old->link = node2;
		node2->link = cur;
	}

}


int pop() {
	int temp;
	if (top == -1) {
		return -1;

	}
	temp = stack[top];
	top--;

	return temp;
}


void DFS(graphType* g, int v) {
	graphNode* w;

	g->visited[v] = 1;
	printf(" %d", v);

	while (v != -1) {
		w = g->adjList_H[v];
		
		while (w != NULL) { //아직 훑어볼게 있다면

			if (g->visited[w->vertex] != 1) { //인접노드중에 방문안한게 있다면
				push(v);
				g->visited[w->vertex] = 1;
				printf(" %d", w->vertex);
				v = w->vertex;
				w = g->adjList_H[v];

			}
			else { //방문한거라면
				w = w->link;
			}
		}
		v = pop(); //훑어볼게 없으니 새로운걸 물어보러 간다
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
	
	insertEdge(g, 2, 4);
	insertEdge(g, 2, 3);
	
	DFS(g, 4);

	return 0;
}