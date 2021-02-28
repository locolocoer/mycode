#include <malloc.h>
typedef struct LNode {
	struct LNode* next;
	int data;
}LinkNode;
void split(LinkNode*& L, LinkNode*& L1, LinkNode*& L2)
{
	LinkNode* p = L->next,*q,*r1;
	L1 = L;
	r1 = L1;
	L2 = (LinkNode*)malloc(sizeof(LinkNode));
	L2->next = NULL;
	while(p!=NULL)
	{
		r1->next = p;
		r1 = p;
		p = p->next;
		q = p->next;
		p->next = L2->next;
		L2->next = p;
		p = q;
	}
	r1->next = NULL;
}