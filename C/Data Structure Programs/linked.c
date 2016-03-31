//IMPLEMENTATION OF LINKED LIST
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
void add_at_first(NODE **,int);	//To Insert the node at first place
void append(NODE **,int);	//To Insert the node at last place
void del_at_first(NODE **);	//To Delete the node at first place
void del_at_last(NODE **);	//To Delete the node at last place
void del_any_num(NODE **,int);	//To Delete a particulat number
void reverse(NODE **);
void display(NODE *);			//To Display the elements of the list
int main()
{
	NODE *start;		//Making a pointer of type NODE ie. struct node
	start=NULL;
	int ch,num;
	do
	{
		getch();
		clrscr();
		printf("1.Insert at Ist\n2.Append\n3.Delete at Ist\n4.Delete at last\n5.Delete any number\n6.Reverse\n7.Display list\n8.Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch (ch)
		{
			case 1:
				{
					printf("Enter the number : ");	//Asking  the user to input number
					scanf("%d",&num);
					add_at_first(&start, num);
					break;
				}
			case 2:
				{
					printf("Enter the number : ");
					scanf("%d",&num);
					append(&start, num);
					break;
				}
			case 3:
				{
					del_at_first(&start);
					break;
				}
			case 4:
				{
					del_at_last(&start);
					break;
				}
			case 5:
				{
					printf("Enter the number : ");
					scanf("%d",&num);
					del_any_num(&start, num);
					break;
				}
			case 6:
				{
					reverse(&start);
					break;
				}
			case 7:
				{
					display(start);
					break;
				}
			case 8:
				{
					return 0;
				}
			default:
				{
					printf("Wrong choice\n");
				}
		}
		
		getch();
	}while (ch!=8);
	return 0;
}

void add_at_first(NODE **p, int num)
{
	NODE *temp;
	temp=(NODE *) malloc (sizeof (NODE));
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

void append(NODE **ps, int num)
{
	NODE *temp,*loop;
	temp=(NODE *) malloc (sizeof (NODE));
	temp->data=num;
	temp->next=NULL;
	if (*ps==NULL)
	{
		*ps=temp;
		return;
	}
	loop=*ps;
	while (loop->next!=NULL)
	{
		loop=loop->next;
	}
	loop->next=temp;
}

void del_at_first(NODE **p)
{
	NODE *temp;
	if ((*p)==NULL)
	{
		printf("List is empty\n");
		return;
	}
	temp=*p;
	(*p)=(*p)->next;
	free(temp);
}

void del_at_last(NODE **p)
{
	NODE *temp,*prev;
	if ((*p)==NULL)
	{
		printf("List is empty\n");
		return;
	}
	temp=*p;
	while(temp->next!=NULL)
	{
		prev=temp;
		temp=temp->next;
	}
	free (temp);
	prev->next=NULL;
}

void del_any_num(NODE **ps, int num)
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

void reverse(NODE **ps)
{
	NODE *temp,*nul,*q;
	if (*ps==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if ((*ps)->next==NULL)
	{
		return;
	}
	nul=*ps;
	q=(*ps)->next;
	while (q!=NULL)
	{
		temp=q->next;
		q->next=*ps;
		*ps=q;
		q=temp;
	}
	nul->next=NULL;
}
