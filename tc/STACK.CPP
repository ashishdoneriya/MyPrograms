#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<process.h>

struct node
{
int data;
struct node *link;
}

void push(struct node **);
void pop(struct node **);
void display(struct node *);

void main()
{
struct  node *p;
int ch;
p=(struct node *)malloc(sizeof(struct node);
p=NULL;
do
	{
	clrscr();
	printf("1.Push\n2.Pop\n3.display\n4.Exit\nEnter your choice : ");
	scanf("%d",&ch);
	switch ch
		{
		case 1:
			push(&p);
			break;
		case 2:
			pop(&p);
			break;
		case 3:
			display(p);
			break;
		case 4:
			exit(0);
		default:
			printf("You enter wrong choice");
		}
	}while(ch!=4);
getch();
}

void push(struct node **q)
{
struct node *temp;
int num;
printf("Enter the number ");
scanf("%d",&num);
temp=(struct node)malloc(sizeof(struct node));
temp->data=num;
temp->link=*q;
*q=temp;
}

void pop(struct node **q)
{
int old;
*q->data=old;
*q=*q->link;
printf("Number deleted is %d",old);
}

void display(struct node q)
{
struct node *temp;
temp=q;
while(*temp!=NULL)
{
printf("%d\n",*q->data);

}
}