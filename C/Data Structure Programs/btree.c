//Implementation of the concept of binary tree
#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct btree
{
	struct btree *left;
	int data;
	struct btree *right;
};
typedef struct  btree TREE;

struct stack
{
	struct btree *arr[10];
	int tos;
};
typedef struct stack STK;


void append(TREE **, int);
void push(STK *, TREE *);
TREE *pop(STK *);
void preorder(TREE *);
void inorder(TREE *);



void append(TREE **pr, int x)
{
	struct btree *p,*temp,*prev;
	p=(TREE *)malloc(sizeof(TREE));
	p->data=x;
	p->left=p->right=NULL;
	if (*pr==NULL)
	{
		*pr=p;
		return;
	}
	temp=*pr;
	while (temp!=NULL)
	{
		prev=temp;
		if ((temp->data)>x)
			temp=temp->left;
		else
			temp=temp->right;
	}
	if ((prev->data)>x)
		prev->left=p;
	else
		prev->right=p;
}

void push(STK *p, TREE *pnode)
{
	if (p->tos==9)
		printf("stack Overflow\n");
	else
		p->arr[++(p->tos)]=pnode;
}

TREE *pop(STK *p)
{
	TREE *address;
	if (p->tos=-1)
	{
		printf("Stack Overflow\n");
		return NULL;
	} 
	return (p->arr[(p->tos)--]);
}

void preorder(TREE *root)
{
	TREE *temp;
	STK s;
	s.tos=-1;
	if (root==NULL)
	{
		printf("Tree is Empty\n");
		return;
	}
	push(&s,root);
	while(s.tos!=-1)
	{
		temp=pop(&s);
		while (temp!=NULL)
		{
			printf("\n%d",temp->data);
			if (temp->right!=NULL)
				push(&s,temp->right);
			temp=temp->left;
		}
	}
}


void inorder(TREE *root)
{
	TREE *temp;
	STK s;
	s.tos=-1;
	if (root==NULL)
	{
		printf("Stack is empty\n");
		return;
	}
	temp=root;
	trav_left:
		while (temp!=NULL)
		{
			push(&s,temp);
			temp=temp->left;
		}
		temp=pop(&s);
		while (temp!=NULL)
		{
			printf("\n%d",temp->data);
			if(temp->right!=NULL)
			{
				temp=temp->right;
				goto trav_left;
			}
			temp=pop(&s);
		}
}

int main()
{
	TREE *root=NULL;
	int ch,num;
	clrscr();
	do
	{
		printf("1.Append\t2.Pre Order Display\t3.Inorder Display\t4.Exit");
		printf("\tEnter your choice : ");
		scanf("%d",&ch);
		switch (ch)
		{
			case 1:
				{
					printf("Enter number : ");
					scanf("%d",&num);
					append(&root,num);
					break;
				}
			case 2:
				{
					preorder(root);
					break;
				}
			case 3:
				{
					inorder(root);
					break;
				}
			case 4:
					return 0;
			default:
					printf("wrong choice\n");
			}
		}while(ch!=4);
	getch();
	return 0;
}
