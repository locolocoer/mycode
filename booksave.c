#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10
//char * s_gets(char *st,int n);
char * s_gets(char *st,int n)
{
	char *ret_val;
	char *find;
	ret_val=fgets(st,n,stdin);
	if(ret_val){
		find=strchr(st,'\n');
		if(find)
		*find='\0';
		else
		while(getchar()!='\n')
		continue;
	}
	return ret_val;
}
struct book{
	char title[MAXTITL];
	char author[MAXAUTL];
	float value; 
};
int main()
{
	struct book libarary[MAXBKS];
	int count=0;
	int index,filecount;
	FILE* pbooks;
	int size=sizeof(struct book);
	if((pbooks=fopen("book.dat","a+b"))==NULL){
		fputs("Cann't open book.dat file\n",stderr);
		exit(1);
	}
	rewind(pbooks);
	while(count<MAXBKS&&fread(&libarary[count],size,1,pbooks)==1){
		if (count==0)
		puts("current contents of book.dat:");
		printf("%s by %s:$%.2f\n",libarary[count].title,libarary[count].author,libarary[count].value);
		count++;
	}
	filecount=count;
	if(count==MAXBKS){
		fputs("The book.dat file is full.",stderr);
		exit(2);
	}
	puts("Please add new book titles.");
	puts("Press enter at the start of a line to stop");
	while(count<MAXBKS&&s_gets(libarary[count].title,MAXTITL)!=NULL&&(libarary[count].title[0])!='\0'){
		puts("Now enter the author.");
		s_gets(libarary[count].author,MAXAUTL); 
		puts("Now enter the value.");
		scanf("%f",&libarary[count++].value);
		while(getchar()!='\n'){
		continue;	}
		if(count<MAXBKS)
		puts("Enter the next title."); 

   } 
	if(count>0){
		puts("Here if the list of your books:");
		for(index=0;index<count;index++){
		printf("%s by %s:$%.2f\n",libarary[index].title,libarary[index].author,libarary[index].value);
			
		}
		fwrite(&libarary[filecount],size,count-filecount,pbooks); 
		
	}else{
		puts("No books? Too bad.\n");
	}
	puts("BYE\n");
	fclose(pbooks);
	return 0;
}

