//IMPEMENTATION OF QUEUE
//SOURCE CODE CREATED BY :- MR. ASHISH DONERIYA
#include<stdio.h>
#define N 3
void insert();
void delete();
void display();
int queue[N];
int front=-1,rear=-1;
int main()
{
	int choice,num,i;
	do
	{
		printf("\n\n1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT");
		printf("\nENTER YOUR CHOICE : ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				insert();
				break;
			case 2:
				delete();
				break;
			case 3:
				display();
				break;
			case 4:
				return 0;
			default :
				printf("YOU ENTER WRONG CHOICE");
		}
	}while (choice!=4);
return 0;
}

//INSERTING THE ELEMENT FROM REAR
void insert()
{
	int num;
	if (rear==N-1)
	printf("OVERFLOW");
	else
	{
		printf("ENTER THE NUMBER : ");
		scanf("%d",&num);
		if (front==-1&&rear==-1)
		{
			front=0;
			rear=0;
		}					
		else
			rear=rear+1;
		queue[rear]=num;
	}
}

//DELETING THE ELEMENT FROM FRONT
void delete()
{
	int num;
	if (front==-1)
		printf("THEIR IS NO ELEMENT IN THE QUEUE");
	else
	{
		num=queue[front];
		front=front+1;
		if (front==(rear+1))
		{
			front=-1;
			rear=-1;
		}
		printf("NUMBER DELETED IS %d",num);
	}
}

//DISPLAYING THE ELEMENT OF QUEUE
void display()
{
	int i;
	if (front==-1&&rear==-1)
		printf("NO ELEMENT IN THE QUEUE");
	else
		{
		for (i=rear;i>=front;i--)
			printf("%d\t",queue[i]);
		}
}
