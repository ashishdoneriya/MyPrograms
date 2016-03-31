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
void circular(NODE *start){
    NODE *p, *q;
    int cir_list, i;
    for(p=q=start; (p!=q) && (q!=NULL);){
        p=p->next;
        q=q->next;
        if(q!=NULL)
           q=q->next;
    }
    if(q==NULL){
        printf("\nList is not circular");
        return;
    }
    printf("List is circular");
    for(i=1; q->next!=p; i++, q=q->next);
    cir_list=i;
    printf("\nLength of circle = %d",cir_list);
    for(i=0, q=start; i<cir_list; i++, q=q->next);
    for(p=start; p!=q; p=p->next, q=q->next);
    printf("NODE from which circle starts is %d",p->data);
    for(;q->next!=p;q=q->next);
    q->next=NULL;
}

NODE *getMiddleNode(NODE *start){
    NODE *p=start,*q=start;
    while((q->next!=NULL) && (q!=NULL)){
        q=q->next;
        q=q->next;
        p=p->next;
    }
    return p;
}

int checkPalindrome(NODE *start){
    NODE *p=start, *q=NULL, *temp;
    temp=getMiddleNode(start);
    while( temp!=NULL ){
        insert(&q, temp->data);
        temp=temp->next;
    }
    while((p!=NULL) && (q!=NULL)){
        if(p->data != q->data)
            return 0;
        p=p->next;
        q=q->next;
    }
    return 1;
}

NODE *mix(NODE **list1, NODE **list2){
    NODE *start=NULL, *curr=NULL;
    while((*list1!=NULL) && (*list2!=NULL)){
        if(start==NULL){
            start=curr=*list1;
        }
        else{
            curr->next=*list1;
            curr=curr->next;
        }
        *list1=(*list1)->next;

        curr->next=*list2;
        curr=curr->next;
        *list2=(*list2)->next;
        curr->next=NULL;
    }
    if(*list1!=NULL){
        curr->next=*list1;
        *list1=NULL;
    }
    if(*list2!=NULL){
        curr->next=*list2;
        *list2=NULL;
    }
    return start;
}

NODE *getMergePoint(NODE *p, NODE *q){
    int c1,c2,i;
    NODE *l1=p, *l2=q, *temp;
    for(c1=0, temp=p; temp!=NULL; c1++, temp=temp->next);
    for(c2=0, temp=q; temp!=NULL; c2++, temp=temp->next);
    if(c1>0)
        for(i=0; i<(c1-c2); i++, l1=l1->next);
    else
        for(i=0; i<(c2-c1); i++, l2=l2->next);
    while( (l1!=l2) && (l1!=NULL) && (l2!=NULL) ){
        l1=l1->next;
        l2=l2->next;
    }
    if(l1==NULL || l2==NULL)
        return NULL;
    else
        return l1;
}

int main(void)
{
    NODE *start=NULL,*temp=NULL;
    insert(&start,10);
    insert(&start,20);
    insert(&start,30);
    insert(&start,40);
    insert(&start,30);
    insert(&start,20);
    insert(&start,10);
    insert(&temp,11);
    insert(&temp,12);
    insert(&temp,13);
    insert(&temp,14);
    display(start);
    if(checkPalindrome(start))
        printf("\nPalindrome");
    else
        printf("\n not palindrome");
    return 0;
}

