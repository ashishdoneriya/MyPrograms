#include<stdio.h>
struct stack
{
	int stk[5];
	int tos;
};
void push(struct stack *,int);
int pop(struct stack *);
void display(struct stack *p);
int main()
{
	struct stack s;
	int num,choice;
	s.tos=-1;
	do
	{
		printf("\n1.PUSH\t2.POP\t3.DISPLAY\t4.EXIT\nEnter your choice : ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				printf("Enter the number");
				scanf("%d",&num);
				push(&s,num);
				break;
			case 2:
				num=pop(&s);
				if (num==130112)
					printf("STACK UNDERFLOW");
				else
					printf("Deleted number is %d",num);
				break;
			case 3:
				display(&s);
				break;
			case 4:
				return 0;
			default:
				printf("You enter wrong choice");
		}
	}while(choice!=4);
	return 0;
}

//insert a number in stack
void push(struct stack *p,int num)
{
	if (p->tos==4)
	{
		printf("Overflow");
		return ;
	}
	p->stk[++p->tos]=num;
}

//Delete a number from stack
int pop(struct stack *p)
{
	if (p->tos==-1)
		return (130112);
	return (p->stk[(p->tos)--]);
}

//aDisplay the elements of stack
void display (struct stack *p)
{
	int i;
	for(i=p->tos;i>=0;i--)
		printf("%d\n",p->stk[i]);	
}
