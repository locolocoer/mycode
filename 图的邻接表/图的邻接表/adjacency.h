#pragma once
#include <malloc.h>
#define INF 32467
#define MAXV 100
typedef struct ANode
{
	int adjvex;
	struct ANode* nextarc;
	int weight;
}ArcNode;
typedef struct Vnode
{
	int data;
	ArcNode* firstarc;
}VNode;
typedef struct {
	VNode adjlist[MAXV];
	int n, e;

}AdjGraph;
void CreateGraph(AdjGraph*& G, int A[MAXV][MAXV], int n, int e);