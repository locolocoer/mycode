/*
΢�ŷ���������⣬����������m��n���ֱ��ʾҪ����Ǯ���Լ�����ܰ�����Ȼ�����ÿ���˷����˶���Ǯ��

�����ʽ��

����Ľ������
����
�����ʽ��

ÿ���������Ľ��
����������

5.2
4
���������

0.85 1.74 0.24 2.37
*/
#include <stdlib.h>
#include <stdio.h>
int main()
{
	double total_money;
	int i,n;
	srand((int)time(NULL)); 
	printf("�������ܽ�");
	scanf("%lf",&total_money);
	printf("\n������������");
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
