#include <stdio.h>
#include <malloc.h>
struct node{
    int data;
    struct node *next;
};

typedef struct node NODE;

void insert(NODE **start,int x){
    NODE *p=(NODE *)malloc(sizeof(NODE));
    p->data=x;
    if(*start==NULL){
        *start=p;
        p->next=NULL;
        return;
    }
    p->next=*start;
    *start=p;
}
void display(NODE *p){
    printf("\n");
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}

int isAvailableK(NODE *temp, int k){
	int c;
	if(temp==NULL)
		return 0;
	for(c=0; c<k && temp!=NULL ; c++, temp=temp->next);
	if(c==k)
		return 1;
	else
		return 0;
}

NODE *getReverse(NODE *start){
	NODE *p=NULL, *n;
	if(start==NULL || start->next==NULL)
		return start;
	n=start->next;
	while(n!=NULL){
		start->next=p;
		p=start;
		start=n;
		n=start->next;
	}
	start->next=p;
	
	return start;
}

void changeK(NODE **start, int k){
/* Original = 10 20 30 40 50 60
	if k=2
	20 10 40 30 60 50
	if k=3
	30 20 10 60 50 40
	if k=4
	40 30 20 10 50 60
 */
	NODE *gen=*start,*temp,*temp1, *prevgen;
	int flag=1, i;
	while(isAvailableK(gen,k)){
		for(i=1, temp=gen ; i<k ; i++, temp=temp->next);
		temp1=temp->next;
		temp->next=NULL;
		if(flag==1){
			flag=0;
			*start=getReverse(*start);
			for(prevgen=*start; prevgen->next!=NULL; prevgen=prevgen->next);
		}
		else{
			prevgen->next=getReverse(gen);
			for(prevgen=gen; prevgen->next!=NULL; prevgen=prevgen->next);
		}
		prevgen->next=temp1;
		gen=temp1;
	}
}
					

int main(void)
{
    NODE *start=NULL;
    int large,small;
    insert(&start,10);
    insert(&start,20);
    insert(&start,30);
    insert(&start,40);
    insert(&start,50);
    insert(&start,60);
    display(start);
    printf("\n");
   changeK(&start,5);
    //start=getReverse(start);
    display(start);
	return 0;
}
