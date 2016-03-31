#include<stdio.h>
#include<conio.h>
void multi();
void main()
{
int i;
clrscr();
multi(10);
getch();
}
void multi(int n)                                        
{
if(n<10000)
 {
   multi(n*10);
   }
printf("\n %d",n);
}
