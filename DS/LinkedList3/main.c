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

void display2(NODE *list1, NODE *list2){
    int count1,count2;
    for(count1=list1->data, count2=1; (list1!=NULL) && (list2!=NULL);count2++){
        if(count1==count2){
            printf("%d ",list2->data);
            list1=list1->next;
            if(list1!=NULL)
                count1=list1->data;
        }
        list2=list2->next;
    }
}
void firstToLast(NODE **start){
    NODE *p,*q;
    for(p=*start;p->next!=NULL;p=p->next);
    q=*start;
    *start=(*start)->next;
    p->next=q;
    q->next=NULL;
}
void lastToFirst(NODE **start){
    NODE *prev,*last;
    for(prev=*start;prev->next->next!=NULL;prev=prev->next);
    last=prev->next;
    prev->next=NULL;
    last->next=*start;
    *start=last;
}
void moveForward(NODE **start, int x){
    NODE *prev,*curr,*temp;
    int count=1;
    if((*start)->next==NULL)
        return;
    for(prev=curr=*start;count!=x && curr!=NULL;count++,prev=curr,curr=curr->next);
    if(curr==NULL){
        printf("\nElement not found");
        return;
    }
    if(curr->next==NULL)
        return;
    if(curr==*start){
        temp=(*start)->next;
        (*start)->next=temp->next;
        temp->next=*start;
        *start=temp;
    }
    else{
        prev->next=curr->next;
        prev=prev->next;
        curr->next=prev->next;
        prev->next=curr;
    }
}

void shiftN(NODE **start, int data, int n){
    NODE *prev1, *curr1, *prev2,*curr2;
    int count;
    for(prev1=curr1=*start;curr1->data!=data;prev1=curr1,curr1=curr1->next);
    for(prev2=curr2=curr1,count=0;count!=n;prev2=curr2,curr2=curr2->next);
    prev1->next=curr1->next;
    prev2->next=curr1;
    curr1->next=curr2;
}

int main(void)
{
    NODE *start=NULL,*co=NULL;
    insert(&start,10);
    insert(&start,20);
    insert(&start,30);
    insert(&start,40);
    insert(&start,50);
    insert(&start,60);
    insert(&co,5);
    insert(&co,3);
    insert(&co,1);
//    display2(co,start);
    firstToLast(&start);
    lastToFirst(&start);
    display(start);
    moveForward(&start,6);
    display(start);
    shiftN(&start,50,3);
    display(start);
    return 0;
}

