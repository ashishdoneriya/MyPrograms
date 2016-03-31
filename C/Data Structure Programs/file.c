#include<stdio.h>
#include<miss.h>
int main()
{
	FILE *fp;
	char str[30];
	int i,choice,c;
	fp=fopen("ashish.txt","a");
	do
	{	
		printf("Enter name : ");
		gets(str);
		for(i=0;str[i]!='\0';i++)
		{
			c=str[i];
			fputc(c,fp);
		}
		fputc('\n',fp);
		printf("Do you want to continue (y=1/n=0) : ");
		scanf("%d",&choice);
		flush();
	}while (choice==1);
	fclose(fp);
	return 0;
}
