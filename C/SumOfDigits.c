#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	long num,b=1,c,d=0,i=1,j=0,p=0,q=0,n=0;
	
	clrscr();
	printf("Enter the number : ");
	scanf("%lu",&num);
	
	n=num;
	do{
		i=i*10;
		c=n/i;
		d++;
	}while(c>0);
	
	do{
		b=pow(10,((int)d-1));
		p=n/b;
		q=n%b;
		j=j+p;
		n=n-q;
		q=n+q;
		n=q-n;
		d--;
	}while(d>0);
	printf("Sum of all the digits of %lu is %ld",num,j);
	getch();
	return 0;
}
