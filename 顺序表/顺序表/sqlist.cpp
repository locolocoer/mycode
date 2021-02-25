#include "sqlist.h"
void createList(SqList** L, ElemType a[], int n)
{
	int i = 0, j = 0;
    *L = (SqList*)malloc(sizeof(SqList));
	while (i < n)
	{
		(*L)->data[i] = a[i];
		i++;
		j++;
	}
	(*L)->length = j;
}

void InitList(SqList*& L)
{
	L = (SqList*)malloc(sizeof(SqList));
	L->length = 0;
}
void DestoryList(SqList* L)
{
	free(L);
}
bool IsEmpty(SqList*& L)
{
	return (L->length==0);
}

int ListLength(SqList*& L)
{
	return L->length;
}
void DispList(SqList* L)
{
	for (int i = 0; i < L->length; i++)
	{
		printf("第%d个元素为%d\n", i + 1, L->data[i]);
	}
}
bool GetElme(SqList* L, int n, ElemType& e)
{
	if (n < 0 || n >= L->length)
	{
		return false;
	}
	e = L->data[n - 1];
	return true;
}

int LocateElem(SqList* L, ElemType e)
{
	int i = 0;
	while (L->data[i]!= e && i <L->length)
		i++;
	if (i == L->length)
		return 0;
	else
		return (i + 1);

}
bool ListInsert(SqList*& L, int i, ElemType e)
{
	if (i<0 || i>L->length+1)
		return false;
	for (int j = L->length; j>=i;j--)
	{
		L->data[j] = L->data[j - 1];
	}
	L->data[i - 1] = e;
	L->length++;
	return true;
}
bool ListDelete(SqList*& L, int i)
{
	if (i<0 || i>L->length)
		return false;
	i--;
	for (int j = i; j < L->length - 1; j++) {
		L->data[j] = L->data[j + 1];
	}
	L->length--;
	return true;
}
void deletenode1(SqList*& L, int x)
{
	int k = 0, i = 0;
	while (i < L->length)
	{
		if (L->data[i] != x)
		{
			L->data[k] = L->data[i];
			k++;
		}
		i++;
	}
	L->length = k;
}
void deletenode2(SqList*& L, int x)
{
	int k = 0, i = 0;
	for (i; i < L->length; i++) {
		if (L->data[i] == x)
			k++;
		else
			L->data[i - k] = L->data[i];
		L->length -= k;
	}
}