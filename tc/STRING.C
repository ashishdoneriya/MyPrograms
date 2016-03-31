#include<stdio.h>
#include<conio.h>
#include<string.h>
main()
{
     int i,n,v,space,cons; 
     char str[20];
     char str1[30]={"HELLO"};
     printf("ENTER YOUR NAME ");
     gets(str);
     strcat(str1,"");
     strcat(str1,str);
     n=strlen(str);
     printf("HELLO MR. %s",str);
     for (i=0,v=0,space=0,cons=0;i<=n-1;i++)
     {
         if(str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U'||str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')
         v=v+1;
         else if(str[i]==32)
         space=space+1;
         else
         cons=cons+1;
     }
     printf("\nNUMBER OF VOWELS = %d\nNUMBER OF CONSONENTS = %d",v,cons);
     printf("\nLENGTH = %d",n);
     printf("\nBASE ADDRESS = %u",str);
     printf("\nREVERSE :- ");
     for (i=n;i>=0;i--)
         printf("%c",str[i]);
     getche
     ();
     }
