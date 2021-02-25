#include "LinkList.h"
void CreateListF(LinkNode*& L, ElemType a[], int n)
{
	LinkNode* s;
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;
	for (int i = 0; i < n; i++) {
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];
		s->next =L->next;
		L->next = s;

	}
	
}
void CreateListr(LinkNode*& L, ElemType a[], int n)
{
	LinkNode* s, * r;
	L = (LinkNode*)malloc(sizeof(LinkNode));
	r = L;
	for (int i = 0; i < n; i++)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
}
void InitList(LinkNode*& L) {
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;
}
void DestoryList(LinkNode*& L)
{
	LinkNode* pre=L,*p=L->next;
	while (p != NULL) {
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);
}
bool IsEmpty(LinkNode* L)
{
	return(L->next == NULL);
}
int ListLength(LinkNode* L)
{
	int i = 0;
	LinkNode* s;
	s = L;
	while (s->next != NULL)
	{
		i++;
		s = s->next;
	}
	return i;
}
void DispList(LinkNode* L)
{
	LinkNode* p = L->next;
	while (p != NULL)
	{
		printf("%d", p->data);
		p = p->next;
	}
	printf("\n");
}
bool GetElem(LinkNode* L, int i, ElemType& e)
{
	int j = 1;
	LinkNode* p;
	p = L->next;
	if (i < 1)
		return false;
	while(j<i&&p!=NULL)
	{
		p = p->next;
		j++;
	}
	if (p == NULL)
		return false;
	e = p->data;
	return true;
	

}

int LocateElem(LinkNode* L, ElemType e)
{
	int i = 1;
	LinkNode* p;
	p = L->next;
	while (p->data != e && p != NULL) {
		p = p->next;
		i++;
	}
	if (p = NULL)
		return -1;
	else
		return i;
}