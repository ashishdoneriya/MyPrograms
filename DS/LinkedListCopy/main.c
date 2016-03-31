#include <stdio.h>
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
NODE *getCopy(NODE *p){
    NODE *q=NULL,*temp,*prev;
    if(p==NULL)
        return NULL;
    q=(NODE *)malloc(sizeof(NODE));
    q->data=p->data;
    prev=q;
    p=p->next;
    while(p!=NULL){
        temp=(NODE *)malloc(sizeof(NODE));
        temp->data=p->data;
        prev->next=temp;
        prev=temp;
        p=p->next;
    }
    prev->next=NULL;
    return q;
}
void reverseAdj(NODE **start){
    NODE *p,*q,*prev,*s=*start;
    if(*start==NULL || (*start)->next==NULL)
        return;
    while(s!=NULL && (s->next)!=NULL){
        p=s;
        q=s->next;
        s=s->next->next;
        if(p==*start){
            *start=q;
            p->next=q->next;
            q->next=p;
        }
        else{
            prev->next=q;
            p->next=q->next;
            q->next=p;
        }
        prev=p;
    }

}
void reverseAdjData(NODE *start){
    NODE *p,*q,*s=start;
    int temp;
    if(start==NULL || (start)->next==NULL)
        return;
    while(s!=NULL && (s->next)!=NULL){
        p=s;
        q=s->next;
        s=s->next->next;
        temp=p->data;
        p->data=q->data;
        q->data=temp;
    }

}

void display(NODE *p){
    printf("\n");
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}


int main(void)
{
    NODE *list1=NULL,*list2=NULL;
    insert(&list1,10);
    insert(&list1,20);
    insert(&list1,30);
    insert(&list1,40);
    insert(&list1,50);
    list2=getCopy(list1);
    printf("List 1 = ");
    display(list1);
    printf("\nReverse ADJ = ");
    reverseAdj(&list2);
    display(list2);
    return 0;
}

