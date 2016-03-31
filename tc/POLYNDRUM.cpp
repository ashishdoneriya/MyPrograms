#include<stdio.h>
#include<conio.h>
main()
{
     char arr[10];
     int i,j,n;
     printf("ENTER THE STRING\n");
     scanf("%s",arr);
     for (i=0;arr[i]!='\0';i++);
     for (j=0,n=0;j<=i/2;j++)
     { 
         if(arr[j]==arr[i-1-j])
         n=n+1;
         else
         break;       
     }
     if (n>=(i/2))
     printf("POLYNDRUM");
     else
     printf("NOT A POLYNDRUM");
     getch();
}
