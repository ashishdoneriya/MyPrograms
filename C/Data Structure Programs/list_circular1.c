//Program to implement circular linked list
//source code created by ashish

#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct cnode
{
	int data;
	struct cnode *next;
};

typedef struct cnode NODE;
void append(NODE **, int);
void display(NODE *);
void delfirst(NODE **);
void dellast(NODE **);
void delany(NODE **, int);
void insert_any(NODE **, int, int);

int main()
{
	clrscr();
	NODE *start=NULL;
	int choice,num,pos;
	do
	{
		printf("1.Append\n2.Delete 1st node\n3.Delete last node\n4.Delelte any number");
		printf("\n5.Add at particular position\n6.Display\n7.Exit\nEnter your choice : ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				{
					printf("Enter the number : ");
					scanf("%d",&num);
					append(&start,num);
					break;
				}
			case 2:
				{
					delfirst(&start);
					break;
				}
			case 3:
				{
					dellast(&start);
					break;
				}
			case 4:
				{
					printf("Enter the number : ");
					scanf("%d",&num);
					delany(&start,num);
				}
			case 5:
				{
					printf("Enter number and its position : ");
					scanf("%d %d",&num,&pos);
					insert_any(&start,pos,num);
					break;
				}
			case 6:
				{
					display(start);
					break;
				}
			case 7:
				{
					return 0;
				}
			default:
				{
					printf("Wrong choice\n");
				}			
		}
	}while (choice!=7);
	getch();
	return 0;
}


//Function to add the node at last
void append(NODE **ps, int num)
{
	NODE *temp,*q;
	temp=(NODE *)malloc(sizeof(NODE));
	if (temp==NULL)
	{
		printf("Can't add\n");
		return;
	}
	temp->data=num;
	if (*ps==NULL)
		*ps=temp;
	else
	{
		q=*ps;
		while (q->next!=*ps)
			q=q->next;
		q->next=temp;
	}
	temp->next=*ps;
}


//Function to display the elements of the list
void display(NODE *p)
{
	NODE *q;
	if (p==NULL)
	{
		printf("list is empty\n");
		return;
	}
	q=p;
	do
	{
		printf("%d\n",q->data);
		q=q->next;
	}while (q!=p);
}

//Function to delete 1st node of the list
void delfirst(NODE **ps)
{
	NODE *temp,*p;
	if (*ps==NULL)
	{
		printf("List is empty\n");
		return;
	}
	temp=*ps;
	if(*ps==temp->next)
	{
		*ps=NULL;
		free(temp);
		return;
	}
	while (temp->next!=*ps)
		temp=temp->next;
	*ps=(*ps)->next;
	free(temp->next);
	temp->next=*ps;
}

//Function to delete the last element of the node
void dellast(NODE **ps)
{
	NODE *temp,*p;
	if (*ps==NULL)
	{
		printf("List is empty\n");
		return;
	}
	temp=*ps;
	if(*ps==temp->next)
	{
		*ps=NULL;
		free(temp);
		return;
	}
	while (temp->next!=*ps)
	{
		p=temp;
		temp=temp->next;
	}
	p->next=*ps;
	free(temp);
}

//Function to delete any number of the list
void delany(NODE **ps, int num)
{
	NODE *p,*temp,*prev;
	if (*ps==NULL)
	{
		printf("List is empty");
		return;
	}
	p=*ps;
	if ((*ps)->data==num)
	{
		if (*ps==(*ps)->next)
		{
			free(*ps);
			*ps=NULL;
			return;
		}
		while (p->next!=*ps)
			p=p->next;
		p->next=(*ps)->next;
		free(*ps);
		*ps=p->next;
	}
	while ((p->next!=*ps)&&(p->data!=num))
	{
		prev=p;
		p=p->next;
	}
	if (p->data!=num)
	{
		printf("Node not found");
		return;
	}
	prev->next=p->next;
	free(p);
}

void insert_any(NODE **ps,int pos, int num)
{
	NODE *temp,*q;
	int i;
	temp=(NODE *)malloc(sizeof(NODE));
	temp->data=num;
	if (pos==1)
	{
		if (*ps==NULL)
		{
			*ps=temp;
			temp->next=*ps;
			return;
		}
		q=*ps;
		while(q->next!=*ps)
			q=q->next;
		temp->next=q->next;
		q->next=temp;
		*ps=temp;
		return;
	}
	q=*ps;
	for (i=1;((i<(pos-1))&&(q!=NULL));i++)
		q=q->next;
	if (q==NULL)
		printf("Position not exist\n");
	else
	{
		temp->next=q->next;
		q->next=temp;
	}
}
