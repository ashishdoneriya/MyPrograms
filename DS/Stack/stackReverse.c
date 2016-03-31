#include<stdio.h>
#include<malloc.h>
#include "stack.c"
void insertAtBottom(STACK **s, int x){
	int temp;
	if(isEmpty(*s)){
		push(s,x);
		return ;
	}
	temp=pop(s);
	insertAtBottom(s,x);
	push(s,temp);
}
void reverseStack(STACK **s){
	int x;
	if(isEmpty(*s))
		return;
	x=pop(s);
	reverseStack(s);
	insertAtBottom(s,x);
}
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
	reverseStack(&s);
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
