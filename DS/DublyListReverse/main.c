#include <stdio.h>
#include <malloc.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
}*start;
typedef struct node NODE;
void reverse(){
    NODE *p=start;
    NODE *q,*rcd;
    if(p->next==NULL)
        return;
    while(p!=NULL){
        q=p->next;
        p->next=p->prev;
        p->prev=q;
        rcd=p;
        p=q;
    }
    start=rcd;
}
void reverseAdj(NODE **start){
    NODE *p,*q,*prev,*s=*start;
    if(*start==NULL || (*start)->next==NULL)
        return;
    while(s!=NULL && (s->next)!=NULL){
        p=s;
        q=s->next;
        s=s->next->next;
        if(s!=NULL)
           q->next->prev=p;
        if(p==*start)
            *start=q;
        else{
            prev->next=q;
            q->prev=prev;
        }
        q->next=p;
        p->prev=q;
        if(s!=NULL)
            s->prev=p;
        p->next=s;
        prev=p;
    }

}

void insert(int x){
    NODE *temp=(NODE *)malloc(sizeof(NODE));
    temp->data=x;
    if(start==NULL){
        temp->prev=temp->next=NULL;
        start=temp;
        return;
    }
    temp->next=start;
    temp->prev=NULL;
    start->prev=temp;
    start=temp;
}
void display(){
    NODE *p=start;
    printf("\n");
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}

int main(void)
{
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insert(60);
    display();
    reverse();
    display();
    reverseAdj(&start);
    display();
    return 0;
}

