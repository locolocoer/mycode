#include <stdio.h>
#pragma once
#define MAXSIZE 20
#include <malloc.h>
#include <stdio.h>
typedef struct {
	int n;
	char x, y, z;
	bool flag;
}ElemType;

typedef struct {
	ElemType data[MAXSIZE];
	int top;
}SqStack;
void InitStack(SqStack*& s) {
	s = (SqStack*)malloc(sizeof(SqStack));
	s->top = -1;
}
void DestoryStack(SqStack*& s)
{
	free(s);
}
bool StackEmpty(SqStack* s)
{
	return (s->top == -1);
}
bool Push(SqStack*& s, ElemType e)
{
	if (s->top == MAXSIZE - 1)
		return false;
	s->top++;
	s->data[s->top] = e;
	return true;
}
bool Pop(SqStack*& s, ElemType& e)
{
	if (s->top == -1)
		return false;
	e = s->data[s->top];
	s->top--;
	return true;
}
bool GetTop(SqStack* s, ElemType& e)
{
	if (s->top == -1)
		return false;
	e = s->data[s->top];
	return true;
}

void Hanoil(int n, char X, char Y, char Z)
{
	if (n == 1)
		printf("\t将第%d个盘片从%c移动到%c\n", n, X, Z);
	else
	{
		Hanoil(n - 1, X, Z, Y);
		printf("\t将第%d个盘片从%c移动到%c\n", n, X, Z);
		Hanoil(n - 1, Y, X, Z);
	}
}
void Hanoi2(int n, char X, char Y, char Z)
{
	SqStack* st;
	ElemType e, e1, e2, e3;
	if (n <= 0)return;
	InitStack(st);
	e.n = n;
	e.x = X;
	e.y = Y;
	e.flag = false;
	Push(st, e);
	while (!StackEmpty(st))
	{
		Pop(st, e);
		if (e.flag == false)
		{
			e1.n = e.n - 1; e1.x = e.y; e1.y = e.x; e1.z = e.z;
			if (e1.n == 1)
				e1.flag = true;
			else
				e1.flag = false;
			Push(st, e1);
			e2.n = e.n; e2.x = e.x; e2.y = e.y; e2.z = e.z; e2.flag = true;
			Push(st, e2);
			e3.n = e.n - 1; e3.x = e.x; e3.y = e.z; e3.z = e.y;
			if (e3.n == 1)
				e3.flag = true;
			else
				e3.flag = false;
			Push(st, e3);

		}
		else
			printf("\t将第%d个盘片从%c移动到%c\n", e.n, e.x,e.z);
	}
	DestoryStack(st);
}
int main()
{
	int n=4;
	char a = 'X', b = 'Y', c = 'Z';
	//Hanoil(n, a, b, c);
	Hanoi2(n, a, b, c);
}