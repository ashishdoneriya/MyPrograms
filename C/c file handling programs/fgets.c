#include<stdio.h>
#include<miss.h>
int main()
{
	FILE *fp;
	int i;
	char str[50];
	fp=fopen("ashish.txt","r");
	while (fgets(str,20,fp)!=NULL)
		printf("Hello %s",str);
	fclose(fp);
}
