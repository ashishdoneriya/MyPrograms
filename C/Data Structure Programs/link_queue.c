//Implementation of queue using linked list
//Source code created by Ashish
#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct queue
{
	int data;
	struct queue *next;
};
typedef struct queue NODE;

void insert(NODE **,NODE **,int);
int del(NODE **,NODE **);

int main()
{
	NODE *front,*rear;
	int choice;
	front=rear=NULL;
	insert(&front,&rear,1);
	insert(&front,&rear,2);
	insert(&front,&rear,3);
	insert(&front,&rear,4);
	insert(&front,&rear,5);
	insert(&front,&rear,6);
	insert(&front,&rear,7);
	insert(&front,&rear,8);
	insert(&front,&rear,9);
	insert(&front,&rear,10);
	insert(&front,&rear,11);
	insert(&front,&rear,12);
	insert(&front,&rear,13);
	insert(&front,&rear,14);
	insert(&front,&rear,15);
	insert(&front,&rear,16);
	insert(&front,&rear,17);
	printf("Deleted Element = %d\n",del(&front,&rear));
	printf("Deleted Element = %d\n",del(&front,&rear));
	printf("Deleted Element = %d\n",del(&front,&rear));
	printf("Deleted Element = %d\n",del(&front,&rear));
	printf("Deleted Element = %d\n",del(&front,&rear));
	printf("Deleted Element = %d\n",del(&front,&rear));
	printf("Deleted Element = %d\n",del(&front,&rear));
	printf("Deleted Element = %d\n",del(&front,&rear));
	printf("Deleted Element = %d\n",del(&front,&rear));
	printf("Deleted Element = %d\n",del(&front,&rear));
	printf("Deleted Element = %d\n",del(&front,&rear));
	printf("Deleted Element = %d\n",del(&front,&rear));
	printf("Deleted Element = %d\n",del(&front,&rear));
	printf("Deleted Element = %d\n",del(&front,&rear));
	printf("Deleted Element = %d\n",del(&front,&rear));
	printf("Deleted Element = %d\n",del(&front,&rear));
	printf("Deleted Element = %d\n",del(&front,&rear));
	printf("Deleted Element = %d\n",del(&front,&rear));
	printf("Deleted Element = %d\n",del(&front,&rear));
	printf("Deleted Element = %d\n",del(&front,&rear));
	return 0;
}

void insert(NODE **pf, NODE **pr, int num)
{
	NODE *temp;
	temp=(NODE *)malloc(sizeof(NODE));
	if (temp==NULL)
	{
		printf("Queue overflow\n");
		return;
	}
	temp->data=num;
	temp->next=NULL;
	if (*pf==NULL&&*pr==NULL)
		*pf=temp;
	else
		(*pr)->next=temp;
	*pr=temp;
}

int del(NODE **pf, NODE **pr)
{
	NODE *temp;
	int num;
	if (*pf==NULL)
	{
		printf("Queue Underflow\n");
		return -1;
	}
	temp=*pf;
	num=temp->data;
	if (*pf==*pr)
		*pf=*pr=NULL;
	else
		*pf=(*pf)->next;
	free (temp);
	return num;
}
