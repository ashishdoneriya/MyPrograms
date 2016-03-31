#include<stdio.h>
#include<conio.h>
void main()
{
int x,y,age;
char str;
clrscr();
printf("enter the name and age\n");
x=scanf("%s %d",str,&age);
y=printf("%s %d",str,age);
window(1,3,20,3);  //define the area
clrscr();
printf("x=%d , y=%d",x,y);
getch();
}