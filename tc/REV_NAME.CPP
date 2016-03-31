#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
char name[30];
int i,count=0,j,size;
clrscr();
printf("Enter your name : ");
gets(name);
size=strlen(name);
for (i=0;i<size;i++)
	{
	if (name[i]!=32)
		count=count+1;
	else
		{
		for (j=i-1;j>=(i-count);j--)
			printf("%c",name[j]);
		printf(" ");
		count=0;
		}

	}
for (j=i-1;j>=(i-count);j--)
	printf("%c",name[j]);
getch();
}