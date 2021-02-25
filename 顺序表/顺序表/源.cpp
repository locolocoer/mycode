#include "sqlist.h"
#include <stdio.h>
int main()
{
	int i = 0;
	int a[3] = { 3,2,3 };
	SqList* L;
	createList(&L, a, 3);
	/*while (i < 3) {
		printf("%d\n", L->data[i]);
		i++;
	}*/
	//ListInsert(L, 3, 8);
	//ListDelete(L, 1);
	deletenode2(L,3);
	DispList(L);
	//int c = LocateElem(L, 3);
	//printf("%d", c);
	DestoryList(L);

}
