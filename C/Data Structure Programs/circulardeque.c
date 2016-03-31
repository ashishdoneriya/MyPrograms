//IMPEMENTATION OF QUEUE
//SOURCE CODE CREATED BY :- MR. ASHISH DONERIYA
#include<stdio.h>
#define N 3
void addatfront();
void delatfront();
void addatrear();
void delatrear();
void display();
int queue[N];
int front=-1,rear=-1;
int main()
{
	int choice,num,i;
	do
	{
		printf("\n\n1.ADD AT FRONT\t2.ADD AT REAR\t3.DELETE FROM FRONT\t4.DELETE FROM REAR\t5.DISPLAY\t6.EXIT\n");
		printf("\nENTER YOUR CHOICE : ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				addatfront();
				break;
			case 2:
				addatrear();
				break;
			case 3:
				delatfront();
				break;
			case 4:
				delatrear();
				break;
			case 5:
				display();
				break;
			case 6:
				return 0;
			default :
				printf("YOU ENTER WRONG CHOICE");
		}
	}while (1);
return 0;
}

//ADD ELEMENT AT FRONT
void addatfront()
{
	int num;
	if (front==0||front==-1)
		printf("CAN'T ADD AT FRONT");
	else
	{
		printf("ENTER THE NUMBER : ");
		scanf("%d",&num);
		front=front-1;
		queue[front]=num;
	}
}
//ADD ELEMENT FROM REAR
void addatrear()
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
void delatfront()
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
//DELETING THE ELEMENT FROM REAR
void delatrear()
{
	int num;
	if (front==rear&&rear!=0)
		printf("THEIR IS NO ELEMENT IN THE QUEUE");
	else
	{
		num=queue[rear];
		rear=rear-1;
		if ((front==rear)&&rear!=-1)
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
		for (i=front;i<=rear;i++)
			printf("%d\t",queue[i]);
		}
}
