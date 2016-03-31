//Program to implement doubly linked list
#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct doubly
{
	struct doubly *prev;
	int data;
	struct doubly *next;
};
typedef struct doubly NODE;

void append(NODE **, int);
void display(NODE *);
void del_first(NODE **);
void del_last(NODE **);
void del_any(NODE **, int);

int main()
{
	NODE *start=NULL;
	int ch,num;
	clrscr();
	do
	{
	printf("1.Append 2.Delete 1st Node 3.Delete last Node 4.Delete any Node\n5.Display 6.Exit\nEnter your choice : ");
	scanf("%d",&ch);
	switch (ch)
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
				del_first(&start);
				break;
			}
		case 3:
			{
				del_last(&start);
				break;
			}
		case 4:
			{
				printf("Enter the number : ");
				scanf("%d",&num);
				del_any(&start,num);
				break;
			}
		case 5:
			{
				display(start);
				break;
			}
		case 6:
			{
				return 0;
			}
		default:
			{
				printf("Wrong choice\n");
			}
		}
	}while(ch!=6);
	return 0;
}

void append(NODE **ps, int num)
{
	NODE *p,*temp;
	p=(NODE *)malloc(sizeof(NODE));
	p->data=num;
	p->next=NULL;
	if (*ps==NULL)
	{
		*ps=p;
		p->prev=NULL;
		return;
	}
	temp=*ps;
	while (temp->next!=NULL)
		temp=temp->next;
	temp->next=p;
	p->prev=temp;
}

void del_first(NODE **ps)
{
	NODE *p;
	if (*ps==NULL)
	{
		printf("List is Empty.\n");
		return;
	}
	if((*ps)->next==NULL)
	{
		free(*ps);
		*ps=NULL;
		return;
	}
	p=(*ps)->next;
	p->prev=NULL;
	free(*ps);
	*ps=p;
}


void del_last(NODE **ps)
{
	NODE *p;
	if (*ps==NULL)
	{
		printf("List is Empty.\n");
		return;
	}
	if((*ps)->next==NULL)
	{
		free(*ps);
		*ps=NULL;
		return;
	}
	p=*ps;
	while(p->next!=NULL)
		p=p->next;
	p->prev->next=NULL;
	free(p);
}

void del_any(NODE **ps, int num)
{
	NODE *p;
	p=*ps;
	if (*ps==NULL)
	{
		printf("List is Empty.\n");
		return;
	}
	if (p->data==num)
	{
		if(p->next==NULL)
		{
			free(*ps);
			*ps=NULL;
			return;
		}
		*ps=(*ps)->next;
		(*ps)->prev=NULL;
		free(p);
		return;
	}
	while ((p->data)!=num&&(p->next!=NULL))
		p=p->next;
	if (p->data==num)
	{
		p->prev->next=p->next;
		if (p->next!=NULL)
			p->next->prev=p->prev;
		free(p);
	}
	else
		printf("Element not found\n");
}

void display(NODE *ps)
{
	if (ps==NULL)
	{
		printf("List is Empty.\n");
		return;
	}
	while (ps!=NULL)
	{
		printf("%d\n",ps->data);
		ps=ps->next;
	}
}
