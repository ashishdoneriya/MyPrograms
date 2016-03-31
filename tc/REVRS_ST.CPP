#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
char str[200
];
int j,out_loop,str_size,temp;
clrscr();
printf("Enter the string : ");
scanf("%s",str);
str_size=strlen(str);
for(out_loop=0;out_loop<str_size;out_loop++)
	{
	printf("%s\n",str);
	temp=str[0];
	for(j=0;j<str_size-1;j++)
		str[j]=str[j+1];
	str[j]=temp;
	}
getch();
}