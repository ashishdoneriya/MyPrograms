//Program to implement doubly sircular using linked list
//Source code created by Ashish

#include<stdio.h>
#include<malloc.h>

struct cdoubly
{
	struct cdoubly *prev;
	int data;
	struct cdoubly *next;
};
typedef struct cdoubly NODE;

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
	if (*ps==NULL)
	{
		p->next=p->prev=*ps=p;
		return 0;
	}
}
