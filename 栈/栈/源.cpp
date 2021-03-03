#include "stack.h"
int main()
{
	SqStack* s;
	InitStack(s);
	int e = 1;
	Push(s, e);
	printf("%d", !StackEmpty(s));
}