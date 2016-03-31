#include<stdio.h>
main( )
{
       float x,sum,avg;
       int i;

       clrscr();
       for ( i=1;i<=5;i++)
       {
       printf("enter number\n");
       scanf("%f",&x);
       sum += x;
       avg=sum/5;
       }
       printf("Average = %f",avg);
       getch();
}