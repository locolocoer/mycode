#include "LinkList.h"
int main()
{
	int a[4] = { 1,2,3,5 };
	LinkNode* L;
	int e=-4;
	CreateListF(L, a, 4);
	GetElem(L, 5, e);
	printf("%d\n", e);
	printf("%d\n", LocateElem(L, 1));
	DispList(L);
	DestoryList(L);
	CreateListr(L, a, 4);
	DispList(L);
	DestoryList(L);
}