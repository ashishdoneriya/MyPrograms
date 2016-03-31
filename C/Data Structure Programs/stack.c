//IMPEMENTATION OF STACK
//SOURCE CODE CREATED BY :- MR. ASHISH DONERIYA
#include<stdio.h>
#define N 10
int push();
int pop();
void display();
int tos=-1;
int stk[N];
int main()
{
	int choice,num;
	do
	{
		printf("\n\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT");
		printf("\nENTER YOUR CHOICE : ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				return 0;
			default :
				printf("YOU ENTER WRONG CHOICE : ");
		}
	}while (choice!=4);
return 0;
}

//ADDING AN ELEMENT IN TOP OF STACK

int push(int num)
{
	if (tos==N-1)
	{
		printf("OVERFLOW");
		return 0;
	}
	printf("ENTER THE NUMBER : ");
	scanf("%d",&num);
	tos=tos+1;
	stk[tos]=num;
	return 0;
}

//DELETING AN ELEMENT FROM TOPP OF STACK

int pop()
{
	int num;
	if (tos==-1)
	{
		printf("UNDERFLOW");
		return 0;
	}
	num=stk[tos];
	tos=tos-1;
	printf("NUMBER DELETED IS %d",num);
	return num;
}

//DISPLAYING THE ELEMENTS OF STACK

void display()
{
	int i;
	for (i=tos;i>=0;i--)
		printf("%d\n",stk[i]);
}	
