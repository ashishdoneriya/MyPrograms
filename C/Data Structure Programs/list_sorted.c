//Implementation of linked list
//In sorted order
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

void add(NODE **, int);
void del_num(NODE **,int);	//To Delete a particulat number
void display(NODE *);		//To Display the elements of the list
int main()
{
	NODE *start;			//Making a pointer of type NODE ie. struct node
	start=NULL;
	int ch,num;
	do
	{
		printf("1.Add\t2.Delete\t3.Display list\t4.Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch (ch)
		{
			case 1:
				{
					printf("Enter the number : ");	//Asking  the user to input number
					scanf("%d",&num);
					add(&start, num);
					break;
				}
			case 2:
				{
					printf("Enter the number : ");
					scanf("%d",&num);
					del_num(&start, num);
					break;
				}
			case 3:
				{
					display(start);
					break;
				}
			case 4:
				{
					return 0;
				}
			default:
				{
					printf("Wrong choice\n");
				}
		}
	}while (ch!=4);
	return 0;
}

void add(NODE **ps, int num)
{
	NODE *p,*temp,*prev;
	temp=(NODE *)malloc(sizeof (NODE));
	temp->data=num;
	if (*ps==NULL)
	{
		temp->next=NULL;
		*ps=temp;
		return;
	}
	if (((*ps)->data)>=num)
	{
		temp->next=*ps;
		*ps=temp;
		return;
	}
	p=*ps;
	while ((p!=NULL)&&((p->data)<num))
	{
		prev=p;
		p=p->next;
	}
	temp->next=p;
	prev->next=temp;
}

void del_num(NODE **ps, int num)
{
	NODE *temp,*temp1,*prev;
	if ((*ps)==NULL)
	{
		printf("List is empty\n");
		return;
	}
	temp=*ps;
	if ((*ps)->data==num)
	{
		*ps=temp->next;
		free(temp);
		return;
	}
	while(temp->data!=num&&temp->next!=NULL)
	{
		prev=temp;
		temp=temp->next;
	}
	if (temp->data==num)
	{
		temp1=temp;
		prev->next=temp->next;
		free(temp1);
		return;
	}
	printf("Number not found\n");
}

void display(NODE *ps)
{
	NODE *s;
	if (ps==NULL)
	{
		printf("List is empty\n");
		return;
	}
	s=ps;
	while( s!=NULL)
	{
		printf("%d\t",s->data);
		s=s->next;
	}
	printf("\n");
}
