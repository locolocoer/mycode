#pragma once
#include <malloc.h>
#include <stdio.h>
typedef int ElemType;
typedef struct Lnode
{
	ElemType data;
	Lnode* next;
}LinkNode;
void CreateListF(LinkNode*& L, ElemType a[], int n);
void CreateListr(LinkNode*& L, ElemType a[], int n);
void InitList(LinkNode*& L);
void DestoryList(LinkNode*& L);
bool IsEmpty(LinkNode* L);
int ListLength(LinkNode* L);
void DispList(LinkNode* L);
bool GetElem(LinkNode* L, int i, ElemType& e);
int LocateElem(LinkNode* L, ElemType e);
bool ListInsert(LinkNode*& L, int i, ElemType e);