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