#include "adjacency.h"
void CreateGraph(AdjGraph*& G, int A[MAXV][MAXV], int n, int e)
{
	int i, j;
	ArcNode* p;
	G = (AdjGraph*)malloc(sizeof(AdjGraph));
	for (i = 0; i < n; i++)
	{
		G->adjlist[i].firstarc = NULL;
	}
	for (i = 0; i < n; i++)
	{
		for (j = n-1; j >= 0; j--)
		{
			if (A[i][j] != 0 && A[i][j] != INF)
			{
				p = (ArcNode*)malloc(sizeof(ArcNode));
				p->adjvex = j;
				p->weight = A[i][j];
				p->nextarc = G->adjlist[i].firstarc;
				G->adjlist[i].firstarc = p;
			}
		}

	}
	G->n = n; G->e = e;
}