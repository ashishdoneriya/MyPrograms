#include<conio.h>
#include<stdio.h>
#define N 10
int a[N]={1,6,9,13,19,22,39,51,66,98};
int search(int *,int);
void display();
void main()
{
int n,pos;
clrscr();
display();
printf("\nenter the number to be searched");
scanf("%d",&n);
pos=search(a,n);
if(pos==-1)
printf("\nnumber not found");
else
printf("\nnumber found at %d position",pos);
getch();
}
int search(int *a,int n)
{
int i;
for(i=0;i<10;i++)
if(a[i]==n)
return (i+1);
if(i==10)
return (-1);
}
void display()
{
int i;
for(i=0;i<10;i++)
printf("\n%d",a[i]);
}