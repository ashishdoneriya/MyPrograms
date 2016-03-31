#include<stdio.h>
#include<miss.h>
int main()
{
	FILE *fp;
	char c;
	int i,choice;
	fp=fopen("ashish.txt","r");
	printf("Names are :-\n");
	while(1)
	{
		c=fgetc(fp);
		if(c==EOF)
			break;
		printf("%c",c);
	}
	fclose(fp);
	hold();
}
