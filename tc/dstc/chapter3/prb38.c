# include<stdio.h>
#include<conio.h>
# define n 3
# define m 3
void main()
{ int i,j;
int a[n][m] = {
			   {1,2,3},     {5,6,7},
		     {9,10,11}
			 };
printf("Contents of array are:\n");
for(i=0;i<=n-1;++i)
 {
  for(j=0;j<=m-1;++j)
  printf("\n%d",a[i][j]);
 }
getch();
}