#include<stdio.h>
#include<conio.h>
#include<process.h>
int insert(int a[], int num, int pos, int len);
int delete(int a[], int pos, int len);
void display(int a[], int len);
void main()
{
     int a[100];
     int ch,i,num,len,pos;
     clrscr();
     printf("ENTER THE NO. OF ELEMENTS OF ARRAY\t");
     scanf("%d",&len);
     printf("ENTER THE ELEMENTS OF ARRAY ONE BY ONE\n");
     for(i=0;i<len;i++)
     {
		     scanf("%d",&a[i]);
     }
     printf("1.Display\n2.Insert\n3.delete4.exit\nEnter your choice");
     scanf("%d",&ch);
     do
     {
		     switch (ch)
		      {
		      case 1:
			   display(a,len);
		      break;
		      case 2:
			   printf("ENTER THE ELEMENT AND THE POSITION OF THE ARRAY");
			   scanf("%d %d",&num,&pos);
			   insert(a,num,pos,len);
			   break;
		      case 3:
			   printf("ENTER THE POSITION OF THE ELEMENT TO BE DELETED");
			   scanf("%d",&pos);
			   delete(a,pos,num);
			   break;
		      case 4:
			   exit(0);
		      default:
			      printf("WRONG CHOICE");
			      }
     }while(ch==4);
     getche();
}
void display(int a[], int len)
{
     int j;
 for(j=0;j<len;j++)
 {
		 printf("%d\n",a[j]);
 }
}
int insert(int a[], int num, int pos, int len)
{
		int k;
		 for(k=len;k>=pos;k--)
		 a[k]=a[k-1];
		 a[pos-1]=num;
		 len++;
		 return len;
}
int delete(int a[], int pos, int len)
{
    int l;
    for(l=pos;l<len;l++)
    a[l-1]=a[l];
    len--;
    return len;
}
