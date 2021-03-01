#pragma once
#include <malloc.h>
typedef int	Elemtype;
typedef struct Dnode
{
	struct Dnode* prior;
	struct Dnode* next;
	Elemtype data;
}DLinkNode;
void CreateListF(DLinkNode*& L, Elemtype a[], int n);
void CreateListR(DLinkNode*& L, Elemtype a[], int n);
bool ListInsert(DLinkNode*& L, int i, Elemtype e);