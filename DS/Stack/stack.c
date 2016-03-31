#include<stdio.h>
#include<malloc.h>
struct stack{
	int data;
	struct stack *next;
};
typedef struct stack STACK;
void push(STACK **s, int x){
	STACK *temp;
	temp=(STACK *)malloc(sizeof(STACK));
	temp->data=x;
	temp->next=*s;
	*s=temp;
}
int pop(STACK **s){
	int x;
	STACK *temp;
	if(*s==NULL)
	return -1;
	temp=*s;
	x=(*s)->data;
	(*s)=(*s)->next;
	free(temp);
	return x;
}
int isEmpty(STACK *s){
	if(s==NULL)
		return 1;
	else return 0;
}
/*
int main(){
	STACK *s=NULL;
	push(&s,10);
	push(&s,20);
	push(&s,30);
	push(&s,40);
	push(&s,50);
	push(&s,60);
	push(&s,70);
	push(&s,80);
	printf("%d\n",pop(&s));
	printf("%d\n",pop(&s));
	printf("%d\n",pop(&s));
	printf("%d\n",pop(&s));
	printf("%d\n",pop(&s));
	printf("%d\n",pop(&s));
	printf("%d\n",pop(&s));
	printf("%d\n",pop(&s));
	printf("%d\n",pop(&s));
	
	return 0;
}
*/
