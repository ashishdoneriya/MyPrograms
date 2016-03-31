#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
int nod=0,x,i,zeros;
int num,temp,rev;
clrscr();
printf("Enter the number::");
scanf("%d",&num);
temp=num;
while(temp>0)
{
temp=temp/10;
nod++;
}
temp=num;
for(temp=num;nod>=0;nod=nod-1,temp=temp/10)
{
x=temp%10;
for(i=1,zeros=1;i<nod;i++)
	zeros=zeros*10;
rev=rev+x*zeros;
}
temp=rev;
printf("%d",temp);
getch();
}