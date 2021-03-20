#include <stdio.h>
#include <stdlib.h>
int main()
{
	char c;
	int row,i,j,k;
	
	
//	printf("%d",row);
//	printf("%c",'A'+1);
//for(j=0;j<5;j++){
//			printf("%c",'A'+j);
//		}
while(scanf("%c",&c)){
	row=c-'A'+1;
	for(i=1;i<=row;i++){
		int a=row-i;
		for(j=0;j<a;j++){
			printf(" ");
		}
		for(j=0;j<i;j++){
			printf("%c",'A'+j);
		}
		for(k=0;k<i-1;k++){
			printf("%c",'A'+i-2-k);
		}
		printf("\n");
		
	}	
}

	system("pause");
	 
 } 
