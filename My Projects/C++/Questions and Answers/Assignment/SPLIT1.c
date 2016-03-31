//Name Saurabh Tamrakar
//Scholar No.101112012
/*WAP To Take 1 String In Input By Keyboard And Then Store
Its All Component In Double Dimension Array using C Program*/

#include<stdio.h>
#include<conio.h>
int main()
{
 char name[10][30],ch[150];
 int i;
 int j=0;
 int k=0;
 clrscr();
 printf("Enter The String\n");
 gets(ch);
 for(i=0;ch[i]!='\0';i++)
  {
      if(ch[i]!=32)
       {
	name[j][k]=ch[i];
	k++;
       }
      else
       {
	name[j][k]='\0';
	j++;
	k=0;
       }
  }
  name[j][k]='\0';
  for(i=0;i<=j;i++)
   {
   printf("%s\n",name[i]);
   }
 getch();
 return 0;
 }
