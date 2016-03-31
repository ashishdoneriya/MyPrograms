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
void firstLastReverse(NODE **start){
    NODE *temp=*start,*prev;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    prev->next=*start;
    temp->next=(*start)->next;
    (*start)->next=NULL;
    *start=temp;
}

void largestLast(NODE **start){
    NODE *p,*q,*r;
    for(p=*start;p->next!=NULL;r=p,p=p->next){
        q=p->next;
        if(p->data > q->data){
            if(p==*start)
               *start=q;
            else
                r->next=q;
            p->next=q->next;
            q->next=p;
            p=q;
        }
    }
}
void smallestFirst(NODE **start){
    NODE *p,*q,*prev;
    int temp=(*start)->data;
    //Finding the smallest element
    for(p=q=*start;p!=NULL;p=p->next){
        if(p->data < temp){
            q=p;
            temp=p->data;
        }
    }
    if(q==*start)
        return;
    //Getting the pointer which points to the smallest element node
    for(p=*start;p!=NULL;p=p->next){
        if(p->next==q)
            prev=p;
    }
    prev->next=q->next;
    q->next=*start;
    *start=q;
}

void deleteNode(NODE **start,int x){
    NODE *temp,*prev;
    for(temp=prev=*start;temp!=NULL;){
        if(temp->data == x){
            if(temp==*start){
                *start=(*start)->next;
                free(temp);
                temp=prev=*start;
            }
            else{
                prev->next=temp->next;
                free(temp);
                temp=prev->next;
            }
            continue;
        }
        prev=temp;
        temp=temp->next;
    }
}

int main(void)
{
    NODE *start=NULL;
    insert(&start,10);
    insert(&start,20);
    insert(&start,30);
    insert(&start,40);
    insert(&start,50);
    insert(&start,60);
    display(start);
 //   firstLastReverse(&start);
    largestLast(&start);
    smallestFirst(&start);
    deleteNode(&start,40);
    display(start);
    return 0;
}

