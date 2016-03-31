#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct rider
{
	char name[30];
	struct rider *next;
};
typedef struct rider man;
void append(man **);
void kill(man **, int);
void display(man *);
int main()
{
	man *start;
	start=NULL;
	int num;
	char ch;
	clrscr();
	do
	{
		append(&start);
		flush();
		printf("Do you want to add more (Y/n) :");
		scanf("%c",&ch);
	}while (ch=='Y'||ch=='y');
	display(start);
	printf("Enter the skip number : ");
	scanf("%d",&num);
	kill(&start,num);
	if (start==NULL)
		return 0;	
	printf("Final rider left is %s",start->name);
	getch();
	return 0;
}

void append(man **ps)
{
	man *temp,*p;
	temp=(man *)malloc(sizeof(man));
	if (temp==NULL)
	{
		printf("Can't add more rider\n");
		return;
	}
	flush();
	printf("Enter the name of rider : ");
	gets(temp->name);
	if (*ps==NULL);
	{
		*ps=temp;
		temp->next=*ps;
		return;
	}
	p=*ps;
	while(p->next!=*ps)
		p=p->next;
	p->next=temp;
	temp->next=*ps;
}

void kill(man **ps, int num)
{
	man *temp,*p=*ps,*q;
	int c=1;
	if ((*ps==NULL)||(*ps==(*ps)->next))
		return;
	while (*ps!=(*ps)->next)
	{
		if(c==num)
		{
			q->next=p->next;
			temp=p;
			p=p->next;

			free(temp);
			*ps=p;
			c=1;
			continue;
		}
		q=p;
		p=p->next;
		c++;
	}
	
}

void display(man *p)
{
	man *q=p;
	if (p==NULL)
	{
		printf("list is empty\n");
		return;
	}
	while (q!=p)
	{
		printf("%s\n",q->name);
		q=q->next;
	}
}
