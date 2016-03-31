#include<stdio.h>
#include<conio.h>
main()
{
     char arr[10],brr[10];
     int i,n;
     printf("ENTER THE STRINGS\n");
     scanf("%s",arr);
     for (i=0;arr[i]!='\0';i++);
     printf("length %d",i);
     n=i;
     for (i=0;i<n;i++)
         brr[i]=arr[n-i-1];
     brr[n]='\0';
     printf("%s",brr);
     getch();
}
