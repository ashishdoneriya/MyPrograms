#include<stdio.h>
#include<conio.h>
#include<malloc.h>

int main()
{
	int **p,r,c,i,j,sum;
	clrscr();
	printf("Enter row size : ");
	scanf("%d",&r);
	p=(int **)malloc(r*sizeof(int *));
	printf("Enter column size : ");
	scanf("%d",&c);
	for (i=0;i<r;i++)
	{
		p[i]=(int *)malloc(c*sizeof(int));
	}
	printf("Enter the Matrix:\n");
	for (i=0;i<r;i++)
	{
		for (j=0;j<c;j++)
			scanf("%d",(*(p+i)+j));
	}
	for (i=0;i<r;i++)
	{
		for (j=0;j<c;j++)
		{
			printf("%d ",*(*(p+i)+j));
			sum=sum+*(*(p+i)+j);
		}
		printf("\n");
	}
	printf("Sum = %d",sum);
	printf("\nAverage = %f\n",(float)sum/(r*c));
	for (i=0;i<r;i++)
		free (*(p+i));  //or free(p[i];
	free(p);
	getch();
	return 0;
}
