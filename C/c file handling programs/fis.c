#include<stdio.h>
#include<miss.h>
int main()
{
	FILE *fp;
	int i,n;
	char str[50];
	fp=fopen("ashish.txt","a");
	printf("Number of names you want to add : ");
	scanf("%d",&n);
	flush();
	for(i=0;i<n;i++)
	{
		printf("Enter name : ");
		gets(str);
		fputs(str,fp);
		fputs("\n",fp);
	}
	fclose(fp);
}
