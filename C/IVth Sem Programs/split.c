/*WAP to take string in input and then print the sentence words by words in separate line*/
/*Name :- Ashish Doneriya */
/*Scholar number :- 101112011 */
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
