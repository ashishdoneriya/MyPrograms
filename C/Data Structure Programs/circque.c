//IMPEMENTATION OF QUEUE
//SOURCE CODE CREATED BY :- MR. ASHISH DONERIYA
#include<stdio.h>
#define N 3
int main()
{
	int choice,num,i;
	int queue[N];
	int front=-1,rear=-1;
	do
	{
		printf("\n\n1.INSERT\t2.DELETE\t3.DISPLAY\t4.EXIT");
		printf("\nENTER YOUR CHOICE : ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				if (front==(rear+1)%N)
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
						rear=(rear+1)%N;
					queue[rear]=num;
				}
				break;
			case 2:
				if (front==-1)
					printf("THEIR IS NO ELEMENT IN THE QUEUE");
				else
				{
					num=queue[front];
					front=(front+1)%N;
					if (front==(rear+1))
						{
						front=-1;
						rear=-1;
						}
					printf("NUMBER DELETED IS %d",num);

				}
				break;
			case 3:
				if (front==-1&&rear==-1)
					printf("NO ELEMENT IN THE QUEUE");
				else
					{
					for (i=rear;i>=front%N;i=(i-1)%N)
					printf("%d\t",queue[i]);
					}
					break;
			case 4:
				return 0;
			default :
				printf("YOU ENTER WRONG CHOICE");
		}
	}while (choice!=4);
return 0;
}	
