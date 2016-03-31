#include<stdio.h>
#include<malloc.h>
int main()
{
	int *a, n, i, sum=0;
/*	Here 'a' is the integer pointer that will hold the base address of the dynamic array
 * 	'n'   is used to store the size of array
 * 	'i'   is temporary variable
 */
	float average;
	printf("Enter the size of array : ");
	scanf("%d",&n);
	
/*	Making the dynamic array	*/
	a=(int *)malloc(n*sizeof(int));
	
/*	Accepting the values of array from the user */
	for(i=0; i<n; i++)
	{
		printf("Enter number : ");
		scanf("%d", (a+i));
	}
	
	printf("Numbers stored in array are\n");
	for(i=0; i<n; i++)
	{
		printf("%d\t",*(a+i));	/* Here *(a+i) denotes the value at index number 'i' */
		sum = sum + *(a+i);		/* Calulating the sum of the numbers */
	}
	printf("\nTheir sum is %d",sum);
	
	average=(float)sum/n;
	printf("\nTheir average is %f",average);
	return 0;
}
