
#include<stdio.h>
#include<conio.h>
  void main()
  {
  int arr[5],i;
      clrscr();
      printf("Enter the elements of an array");
      for(i=0;i<5;i++)
      {
       scanf("%d",&arr[i]);
      }
      printf("The entered array is ");
      for(i=0;i<5;i++)
      {
       printf("%d\n",arr[i]);
      }
     getch();
    }

