//IMPLEMENTATION OF STACK THROUGH LINKED LIST
//SOURCE CODE BY ASHISH
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node		//Defining a structure
{
	int data;
	struct node *next;
};
typedef struct node NODE;

void push(NODE **,int);	//To Insert the node at first place
int pop(NODE **);	//To Delete the node at first place

int main()
{
	NODE *tos;		//Making a pointer of type NODE ie. struct node
	tos=NULL;
	int num;
	clrscr();
	push(&tos,10);
	push(&tos,20);
	push(&tos,30);
	push(&tos,40);
	push(&tos,50);
	push(&tos,60);
	push(&tos,70);
	push(&tos,80);
	push(&tos,90);
	push(&tos,100);
	push(&tos,110);
	push(&tos,120);
	push(&tos,130);
	push(&tos,140);
	push(&tos,150);
	push(&tos,160);
	num=pop(&tos);
	printf("Popped element = %d\n",num);
	num=pop(&tos);
	printf("Popped element = %d\n",num);
	num=pop(&tos);
	printf("Popped element = %d\n",num);
	num=pop(&tos);
	printf("Popped element = %d\n",num);
	num=pop(&tos);
	printf("Popped element = %d\n",num);
	num=pop(&tos);
	printf("Popped element = %d\n",num);
	num=pop(&tos);
	printf("Popped element = %d\n",num);
	num=pop(&tos);
	printf("Popped element = %d\n",num);
	num=pop(&tos);
	printf("Popped element = %d\n",num);
	num=pop(&tos);
	printf("Popped element = %d\n",num);
	num=pop(&tos);
	printf("Popped element = %d\n",num);
	num=pop(&tos);
	printf("Popped element = %d\n",num);
	num=pop(&tos);
	printf("Popped element = %d\n",num);
	num=pop(&tos);
	printf("Popped element = %d\n",num);
	num=pop(&tos);
	printf("Popped element = %d\n",num);
	num=pop(&tos);
	printf("Popped element = %d\n",num);
	num=pop(&tos);
	printf("Popped element = %d\n",num);
	num=pop(&tos);
	printf("Popped element = %d\n",num);
	num=pop(&tos);
	printf("Popped element = %d\n",num);
	num=pop(&tos);
	printf("Popped element = %d\n",num);
	num=pop(&tos);
	getch();
	return 0;
}


void push(NODE **p, int num)
{
	NODE *temp;
	temp=(NODE *) malloc (sizeof (NODE));
	if (temp==NULL)
	{
		printf("Stack Overflow\n");
		return;
	}
	temp->data=num;
	if (*p==NULL)
	{
		temp->next=NULL;
		*p=temp;
		return;
	}
	temp->next=*p;
	*p=temp;
}

int pop(NODE **p)
{
	int num;
	NODE *temp;
	if ((*p)==NULL)
	{
		printf("Stack is empty\n");
		return -1;
	}
	temp=*p;
	num=temp->data;
	(*p)=(*p)->next;
	free(temp);
	return num;
}
