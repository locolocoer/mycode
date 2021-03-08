#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MaxSize 100000
int main()
{
	int n,i=0,y=0;
	int w[MaxSize], score[MaxSize];
	scanf("%d", &n);
	for (i; i < n; i++)
	{
		scanf("%d %d", &(w[i]), &(score[i]));
	}
	i = 0;
	for (i; i < n; i++)
	{
		y = y + w[i] * score[i];
		//printf("%d,%d\n", w[i], score[i]);
	}
	if (y > 0)
		printf("%d", y);
	else
	{
		y = 0;
		printf("%d", y);
	}
}
