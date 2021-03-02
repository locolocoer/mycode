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
typedef struct {
	Box data[MAXSIZE];
	int top;
}sttype;

bool mgpath(int xi, int yi, int xe, int ye)
{
	Box path[MAXSIZE], e;
	int i, j, di, il, jl, k;
	bool find;
	sttype* st;
	st = (sttype*)malloc(sizeof(sttype));
	st->top = -1;
}