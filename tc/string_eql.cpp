#include<stdio.h>
#include<conio.h>
#include<string.h>
main()
{
     char arr[10],brr[10];
     int x;
     printf("ENTER TWO STRINGS\n");
     scanf("%s %s",arr,brr);
     x=strcmp(arr,brr);
     if (x==0)
        printf("STRINGS ARE EQUAL");
     else
         printf("STRINGS NOT EQUAL");
     getch();
}
s
