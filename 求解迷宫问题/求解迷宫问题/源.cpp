#define M 8
#define N 8
#define MAXSIZE 1000
#include <stdio.h>
#include <malloc.h>
int mg[M + 2][N + 2] = { {1,1,1,1,1,1,1,1,1,1},
				         {1,0,0,1,0,0,0,1,0,1},
				         {1,0,0,1,0,0,0,1,0,1},
				         {1,0,0,0,0,1,1,0,0,1},
				         {1,0,1,1,1,0,0,0,0,1},
				         {1,0,0,0,1,0,0,0,0,1},
				         {1,0,1,0,0,0,1,0,0,1},
				         {1,0,1,1,1,0,1,1,0,1},
				         {1,1,0,0,0,0,0,0,0,1},
				         {1,1,1,1,1,1,1,1,1,1}
};

typedef struct
{
	int i;
	int j;
	int di;
}Box;
typedef Box ElemType;
typedef struct {
	Box data[MAXSIZE];
	int top;
}SqStack;

void InitStack(SqStack*& s) 
{
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

bool mgpath(int xi, int yi, int xe, int ye)
{
	Box path[MAXSIZE], e;
	int i, j, di, il, jl, k;
	bool find;
	SqStack* st;
	InitStack(st);
	e.i = xi;
	e.j = yi;
	e.di = -1;
	Push(st, e);
	mg[xi][yi] = -1;
	while (!StackEmpty(st))
	{
		GetTop(st, e);
		i = e.i;
		j = e.j;
		di = e.di;
		if (i == xe && j == ye)
		{
			k = 0;
			while (!StackEmpty)
			{
				Pop(st, e);
				path[k++] = e;
			}
			while (k >= 1)
			{
				k--;
				printf("\t(%d,%d)", path[i].i, path[k].j);
				if ((k + 2) % 5 == 0)
					printf("\n");

			}
			printf("\n");
			DestoryStack(st);
			return true;
		}
		find = false;
		while (di < 4 && !find)
		{
			di++;
			switch (di)
			{
			case 0:il = i - 1; jl = j; break;
			case 1:il = i; jl = j + 1; break;
			case 2:il = i + 1; jl = j; break; 
			case 3:il = i; jl = j - 1; break;
			}
			if (mg[il][jl] == 0)
				find == true;
		}
		if (find)
		{
			st->data[st->top].di == di;
			e.i = il;
			e.j = jl;
			e, di = -1;
			Push(st, e);
			mg[il][jl] = -1;
		}
		else
		{
			Pop(st, e);
			mg[e.i][e.j] = 0;
		}
	}
	DestoryStack(st);
	return false;
}
int main() {
	if (!mgpath(1, 1, M, N))
		printf("ц╩сп╫Б");
	return 1;
}