/*
微信发红包的问题，输入两个数m和n，分别表示要发的钱数以及红包总包数，然后输出每个人发到了多少钱。

输入格式：

红包的金额总数
人数
输出格式：

每个人抢到的金额
输入样例：

5.2
4
输出样例：

0.85 1.74 0.24 2.37
*/
#include <stdlib.h>
#include <stdio.h>
int main()
{
	double total_money;
	int i,n;
	srand((int)time(NULL)); 
	printf("请输入总金额：");
	scanf("%lf",&total_money);
	printf("\n请输入总人数");
	scanf("%d",&n);
	double *m=(double *)malloc(n*sizeof(double));
    for(i=0;i<n-1;i++){
    	double temp;
    	do{
    		temp=rand()%((int)(total_money*100))/100;
		}while(temp>=total_money||temp<=0);
		m[i]=temp;
		total_money-=temp;
	}
	m[n-1]=total_money;
	for(i=0;i<n;i++){
		printf("%lf ",m[i]);
	}
 } 
