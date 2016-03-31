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
void deleteOdd(NODE *p){
    NODE *temp;
    while(p!=NULL){
        temp=p->next;
        if(temp!=NULL){
            p->next=temp->next;
            free(temp);
        }
        p=p->next;
    }
}
NODE *getLastN(NODE *start,int x){
    NODE *p,*q;
    int i;
    for(i=0, q=start; i<x; i++, q=q->next);
    for(p=start; q!=NULL; p=p->next, q=q->next);
    return p;
}
NODE *getHalf(NODE *start){
    NODE *p,*q,*prev;
    for(prev=p=q=start; (q!=NULL) && (q->next!=NULL);){
        prev=p;
        p=p->next;
        q=q->next;
        q=q->next;
    }
    prev->next=NULL;
    return p;
}

NODE *splitFrom(NODE **start, int x){
    NODE *p,*prev;
    if((*start)->data==x){
        p=*start;
        *start=NULL;
    }
    else{
        for(p=prev=*start; (p!=NULL) && (p->data!=x); prev=p, p=p->next);
        prev->next=NULL;
    }
    return p;

}
NODE *getAlternate(NODE *p){
    NODE *q=NULL,*r;
    if((p==NULL) || (p->next==NULL))
        return NULL;
    while((p!=NULL) && (p->next!=NULL)){
        if(q==NULL)
            q=r=p->next;
        else{
            r->next=p->next;
            r=r->next;
        }
        p->next=r->next;
        r->next=NULL;
        p=p->next;
    }
    return q;
}

int main(void)
{
    NODE *start=NULL,*p;
    insert(&start,10);
    insert(&start,20);
    insert(&start,30);
    insert(&start,40);
    insert(&start,50);
    insert(&start,60);
    insert(&start,70);
    insert(&start,80);
    display(start);
    p=getAlternate(start);
    display(start);
    display(p);
    return 0;
}

