#include<stdio.h>
#include<conio.h>
#include<conio.h>

struct btree
{
	struct btree *left;
	int data;
	struct btree *right;
};
typedef struct btree TREE;

struct stack
{
	struct btree *stk[10];
	int tos;
};

void append(TREE **, int);
void preorder(TREE *);
void push(struct stack *p,struct btree *);
TREE *pop(struct stack *);

int main()
{
	TREE *root=NULL;
	clrscr();
	append(&p,1);
	append(&p,2);
	append(&p,3);
	append(&p,4);
	append(&p,5);
	append(&p,6);
	append(&p,7);
	append(&p,8);
	append(&p,9);
	append(&p,10);
	append(&p,11);
	append(&p,12);
	append(&p,13);
	append(&p,14);
	append(&p,15);
	preorder(root);
	return 0;
}

void append(TREE *ps, int num)
{
	TREE *p,*temp,*prev;
	p=(TREE *)malloc(sizeof(TREE));
	p->data=num;
	p->left=p->right=NULL;
	if (*ps==NULL)
	{
		*ps=p;
		return;
	}
	temp=*ps;
	while (temp!=NULL)
	{
		prev=temp;
		if ((temp->data)>num)
			temp=temp->left;
		else
			temp=temp->right;
	}
	if ((prev->data)>num)
		prev->left=p;
	else
		prev->right=p;
}

void push(stuct stack *p, TREE *pnode)
{
	if(p->tos==9)
		printf("Stack Overflow\n");
	else
		p->stk[++(p->tos)]=pnode;
}

TREE *pop(struct stack *p)
{
	if (p->tos==-1)
		printf("Stack Overflow\n");
	else
		return (p->stk[(p->tos)--]);
}

void preorder(TREE *pnode)
{
	struct stack S;
	S.tos=-1
}
