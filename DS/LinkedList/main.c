#include <stdio.h>
#include <malloc.h>
struct node{
    int data;
    struct node *next;
};

typedef struct node NODE;

int count(NODE *p,int x){
    int n=0;
    while(p!=NULL){
        if(p->data==x)
            n++;
        p=p->next;
    }
    return n;
}
void smallLarge( NODE *p, int *larg, int *sml ){
    if(p==NULL){
        printf("\nList Empty");
        return;
    }
    *larg=*sml=p->data;
    p=p->next;
    while(p!=NULL){
        if( (*larg) < (p->data) ){
            *larg = p->data;
        }
        if( (*sml) > (p->data) ){
            *sml = p->data;
        }
        p=p->next;
    }
}

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
void bubbleSort(NODE *start){
    NODE *p,*q,*end;
    int temp;
    for(end=NULL;end!=start;end=q){
        for(p=start;p->next!=end;p=p->next){
            q=p->next;
            if((p->data)>(q->data)){
                temp=p->data;
                p->data=q->data;
                q->data=temp;
            }
        }
    }
}
void selectionSort(NODE *start){
    NODE *p,*q=NULL;
    int temp;
    for(p=start;(p->next)!=NULL;p=p->next){
        for(q=p;q!=NULL;q=q->next){
            if(p->data > q->data){
                temp=p->data;
                p->data=q->data;
                q->data=temp;
            }
        }
    }
}
NODE *selectionSort1(NODE *start){
    NODE *p,*q,*r,*s,*temp;
    for(r=p=start;p->next!=NULL;r=p,p=p->next){
        for(s=q=p->next;q!=NULL;s=q,q=q->next){
            if(p->data > q->data){
                temp=p->next;
                p->next=q->next;
                q->next=temp;
                if(p!=start)
                    r->next=q;
                s->next=p;
                if(p==start)
                    start=q;
                temp=p;
                p=q;
                q=temp;
            }
        }
    }
    return start;
}

int main(void)
{
    NODE *start=NULL;
    int large,small;
    insert(&start,40);
    insert(&start,50);
    insert(&start,20);
    insert(&start,10);
    insert(&start,70);
    insert(&start,40);
    start=selectionSort1(start);
    display(start);
    printf("\n40 occurs %d times",count(start,40));
    smallLarge(start,&large,&small);
    printf("\nLargest = %d\nSmallest = %d\n",large,small);
    return 0;
}
