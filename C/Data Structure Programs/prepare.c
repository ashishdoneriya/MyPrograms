//Conversion of infix to prefix
#include<stdio.h>
#include<conio.h>
#include<string.h>
struct stack
{
	char stk[50];
	int tos;
};

void push (struct stack * , char);		
char pop (struct stack *);
int prcd (char, char);
int isempty(struct stack);
void convert(char [], char []);
int isopand (char);
void reverse(char []);
int main()
{
	char infix[30],prefix[30];
	system("clear");
	printf("Enter a infix expression : ");
	scanf("%s",infix);
	convert(infix,prefix);
	printf("prefix is : %s\n",prefix);
	getch();
}

//converting epression into prefix
void convert (char infix[], char prefix[])
{
	struct stack s;
	int i,j=0,x;
	char ch;
	s.tos=-1;
	for (i=0;infix[i]!='\0';i++);
	for(i=i-1;i>=0;i--)
	{
		ch=infix[i];
		if(isopand(ch)==1)
		{
			prefix[j]=ch;
			j++;
		}
		else if(isopand(ch)==2)
		{
			if (ch==')')
			{
				push(&s,ch);
			}
			else
			{
				while (s.stk[s.tos]!=')')
				{
					prefix[j]=pop(&s);
					j++;
				}
				pop(&s);	
			}
		}

		else
		{
			while(isempty(s)==0)
			{
				x=prcd(s.stk[s.tos],ch);
				if(x==0)
					break;
				else if (x==2)
				{
					break;
				}

				prefix[j]=pop(&s);
				j++;
			}
			push(&s,ch);
		}
	}
	while(isempty(s)==0)
	{
		prefix[j]=pop(&s);
		j++;
	}
	prefix[j]='\0';
	reverse(prefix);
}

//check if stack is empty or not
int isempty(struct stack s)
{
	return (s.tos==-1);
}

//cheak if character is operand or operator
int isopand(char ch)
{
	if (ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='%'||ch=='$')
		return 0;
	else if (ch=='('||ch==')')
		return 2;
	else
		return 1;
}

//check the precedence of operator
int prcd(char op1, char op2)
{
	if (op1==')')
		return 2;
	else if (op1=='$'&&op2!='$')
		return 1;
	else if (op2=='$')
		return 0;
	else if ((op1=='*'||op1=='/'||op1=='%')&&(op2!='*'||op2!='/'||op2!='%'))
		return 1;
	else if (op2=='*'||op2=='/'||op2=='%')
		return 0;
	else if ((op1=='+'||op1=='-')&&(op2!='+'||op2!='-'))
		return 1;
	else 
		return 0;
}

void push(struct stack *p,char num)
{
	p->stk[++p->tos]=num;
}

//Delete a number from stack
char pop(struct stack *p)
{
	return (p->stk[(p->tos)--]);
}

void reverse(char prefix [])
{
	int len,i;
	char revrs[30];
	len=strlen(prefix);
	for (i=0;i<len;i++)
		revrs[i]=prefix[len-i-1];
	revrs[i]='\0';
	strcpy(prefix,revrs);
}
