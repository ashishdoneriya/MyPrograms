#include<stdio.h>
#include<malloc.h>

int main()
{
	int *p;
	int i,size;
	p=(int *)malloc(15*sizeof(int));
	printf("\n\nENTER THE SIZE OF ARRAY : ");
	scanf("%d",&size);
	printf("\nENTER THE NUMBERS FROM 1 TO %d\n",size);
	for (i=0;i<size;i++)
	{
		scanf("%d",p+i);
	}
	printf("ENTERED NUMBERS ARE :-\n");
	for (i=0;i<size;i++)
	{
		printf("%d\n",*(p+i));
	}
	return 0;
}
