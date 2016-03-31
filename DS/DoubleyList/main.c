#include <stdio.h>
#include <malloc.h>
#include <math.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
};
typedef struct node NODE;

void insert(NODE **start, int x){
    NODE *temp,*p;
    temp=(NODE *)malloc(sizeof(NODE));
    temp->data=x;
    temp->next=NULL;
    if(*start==NULL){
        temp->prev=NULL;
        *start=temp;
        return;
    }
    for(p=*start; p->next!=NULL; p=p->next);
    p->next=temp;
    temp->prev=p;
}

void display(NODE *p){
    printf("\n");
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}

NODE *getList(int num){
    NODE *start=NULL;
    int c,i,x=num,n=num;
    for(c=0; num>0; num/=10, c++ ); //Counting the number of digits
    c=(c%4?1:0)+c/4;
    for(i=0; i<c; i++){
        x=n%10000;
        n=n/10000;
        insert(&start,x);
    }
    return start;
}


int main(){
    NODE *start=NULL;
    start=getList(987654321);
    display(start);
    return 0;
}
//  1 2 3 4 5 4 3 2 1
