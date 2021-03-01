#include "DLinkNode.h"
void CreateListF(DLinkNode*& L, Elemtype a[], int n)
{
	DLinkNode* s;
	L = (DLinkNode*)malloc(sizeof(DLinkNode));
	L->next = NULL;
	L->prior = NULL;
	for (int i = 0; i < n; i++)
	{
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = a[i];
		s->next = L->next;
		if (L->next != NULL)
			L->next->prior = s;
		L->next = s;
		s->prior = L;

	}
}
void CreateListR(DLinkNode*& L, Elemtype a[], int n)
{
	DLinkNode* s, * r;
	r = L;
	for (int i = 0; i < n; i++)
	{
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = a[i];
		r->next = s;
		s->prior = r;
		r = s;
	}
	r->next = NULL;
}
bool ListInsert(DLinkNode*& L, int i, Elemtype e)
{
	int j = 0;
	DLinkNode* p = L, * s;
	if (i <= 0)
		return false;
	while (j<i-1&&p!=NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	else
	{
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = e;
		s->next = p->next;
		if (p->next != NULL)
			s->next->prior = s;
		s->prior = p;
		p->next = s;
		return true;
	}
}