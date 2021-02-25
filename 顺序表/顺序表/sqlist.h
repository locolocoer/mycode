#pragma once
/*
时间：2021年2月22日21:51
姓名：冯仁尧



*/
#define MAXSIZE 100
#include <malloc.h>
#include <stdio.h>
typedef int ElemType;
typedef struct {
	ElemType data[MAXSIZE];
	int length;
}SqList;
void createList(SqList** L, ElemType a[], int n);
void InitList(SqList*& L);
void DestoryList(SqList* L);
bool IsEmpty(SqList*& L);
int ListLength(SqList*& L);
void DispList(SqList *L);
bool GetElme(SqList* L, int n, ElemType& e);
int LocateElem(SqList* L, ElemType e);
bool ListInsert(SqList*& L, int i, ElemType e);
bool ListDelete(SqList*& L, int i);
void deletenode1(SqList*& L, int x); 
void deletenode2(SqList*& L, int x);