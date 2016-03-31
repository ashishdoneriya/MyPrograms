#include<stdio.h>
#include<conio.h>
void main()
{
int a=10;
int *p;
int **q;
clrscr();
p=&a;
q=&p;
printf(" a *p **q &a       p     &p      *q\n%d %d %d %u    %u %u %u",a,*p,**q,&a,p,&p,*q);
getch();
}