//Program to implement queue using stack
#include<stdio.h>
#include<conio.h>
struct queue
{
	int arr[5];
	int front;
	int rear;
};

void insert (struct queue *, int);
int del(struct queue *);
void display(struct queue);
int main()
{
	struct queue s;
	int choice,num,i;
	s.front=0;
	s.rear=-1;
	system ("clear");
	do
	{
		printf("\n\n1.INSERT\t2.DELETE\t3.DISPLAY\t4.EXIT");
		printf("\nENTER YOUR CHOICE : ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				printf("Enter the number : ");
				scanf("%d",&num);
				insert(&s,num);
				break;
			case 2:
				num=del(&s);
				if (num==-1)
					break;
				printf("deleted number is : %d",num);
				break;
			case 3:
				display(s);
				break;
			case 4:
				return 0;
			default :
				printf("YOU ENTER WRONG CHOICE");
		}
	}while (choice!=4);
return 0;
}

void insert (struct queue *p, int num)
{
	if(p->rear==4)
	{
		printf("Queue overflow");
		return;
	}
	p->arr[++p->rear]=num;
}

int del (struct queue *p)
{
	int num;
	if (p->front>p->rear)
	{
		printf("Queue underflow");
		return -1;
	}
	return (p->arr[(p->front)++]);
}

//DISPLAYING THE ELEMENT OF QUEUE
void display(struct queue p)
{
	int i;
	if (p.front==0&&p.rear==-1)
		printf("NO ELEMENT IN THE QUEUE");
	else
		{
		for (i=p.rear;i>=p.front;i--)
			printf("%d\t",p.arr[i]);
		}
}
