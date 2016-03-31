#include<iostream>
#include<malloc.h>
#define N 5
using namespace std;

struct node{
	int data;
	struct node *next;
	struct node *random;
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

NODE *getPointer(NODE *start, int data){
	NODE *temp=start;
	while(1){
		if(temp->data==data || temp==NULL)
			break;
		temp=temp->next;
	}
	return temp;
}

void createList(NODE **start){
	int i, a[N]={50,40,30,20,10};
	int random[N]={30,50,10,20,40};
	NODE *temp;
	for(i=0; i<N; i++)
		insert(start,a[i]);
	//Arrange the random
	for(temp=*start , i=0; temp!=NULL; temp=temp->next , i++)
		temp->random=getPointer(*start, random[i]);
		
}

void showList(NODE *start){
	for(;start!=NULL; start=start->next)
		printf("NODE = %d\tRANDOM = %d\n",start->data, start->random->data);
}
void showSimpleList(NODE *start){
	for(NODE *temp=start; temp!=NULL; temp=temp->next)
		cout<<temp->data<<"\t";
}
void insertTemp(NODE *start){
	NODE *temp;
	while(start!=NULL){
		temp=(NODE *)malloc(sizeof(NODE));
		temp->data=start->data;
		temp->next=start->random;
		start->random=temp;
		start=start->next;
	}
}
void tempPointRandom(NODE *start){
	NODE *temp;
	while(start->next!=NULL){
		temp=start->random;
		temp->random=start->next->random;
		start=start->next;
	}
	start->random->random=NULL;
}
	
NODE *rearrangeList(NODE *start){
	NODE *copy=start->random, *temp;
	while(start!=NULL){
		temp=start->random;
		start->random=temp->next;
		start=start->next;
	}
	return copy;
}
void reverseRandomAndNext(NODE *start){
	NODE *next, *random;
	while(start!=NULL){
		random=start->random;
		next=start->next;
		start->next=random;
		start->random=next;
		start=start->next;
	}
}

NODE *getCopy(NODE *start){
	NODE *copy;
	insertTemp(start);
	tempPointRandom(start);
	 copy=rearrangeList(start);
	reverseRandomAndNext(copy);
	return copy;
}		

int main(){
	NODE *start=NULL;
	createList(&start);
	NODE *copy=getCopy(start);
	showList(copy);
	return 0;
}
