#include <stdio.h>
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
int main()
{
	int n=4;
	char a = 'X', b = 'Y', c = 'Z';
	Hanoil(n, a, b, c);
}