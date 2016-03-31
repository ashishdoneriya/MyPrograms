#include<stdio.h>
#define N 20
struct stack{
	char arr[N];
	int tos;
};
typedef struct stack STACK;

void push(STACK *stk, char num){
	stk->arr[++(stk->tos)]=num;
}

char pop(STACK *stk){
	char x=stk->arr[(stk->tos)--];
	return x;
}

int isStackEmpty(STACK *stk){
	if((stk->tos)==-1)
		return 1;
	else return 0;
}
int operatorPriority(char ch){
	if(ch=='$')
		return 3;
	if(ch=='*' || ch=='/')
		return 2;
	else
		return 1;
}
int isOperator(char ch){
	if(ch=='$' || ch=='+' || ch=='-' || ch=='*' || ch=='/')
		return 1;
	else return 0;
}
int isBracket(char ch){
	if(ch=='(' || ch==')')
		return 1;
	else return 0;
}
int isOperand(char ch){
	if(isOperator(ch) || isBracket(ch))
		return 0;
	else return 1;
}
void convertInfixToPostfix(char *infix, char *postfix){
	STACK stk;
	int i,j;
	char ch;
	stk.tos=-1;
	for(i=0 , j=0 ; infix[i]!='\0'; i++){
		if(isOperand(infix[i]))
			postfix[j++]=infix[i];
		else if(infix[i]=='(')
			push(&stk,'(');
		else if(infix[i]==')'){
			while(1){
				ch=pop(&stk);
				if(ch!='(')
					postfix[j++]=ch;
				else
					break;
			}
		}
		else{
			while(!isStackEmpty(&stk)){
				ch=pop(&stk);
				if(ch=='('){
					push(&stk,ch);
					break;
				}
				else if(operatorPriority(ch)<operatorPriority(infix[i])){
					push(&stk,ch);
					break;
				}
				else
					postfix[j++]=ch;
				push(&stk,infix[i]);
			}
		}
	}
	while(!isStackEmpty(&stk))
		postfix[j++]=pop(&stk);
	postfix[j]='\0';
}

int main(){
	char infix[30],postfix[30];
	printf("Enter Infix Expression : ");
	scanf("%s",infix);
	convertInfixToPostfix(infix,postfix);
	printf("Postfix : %s",postfix);
	return 0;
}
