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
int equal(NODE *list1, NODE *list2){
    while(list1!=NULL && list2!=NULL){
        if(list1->data != list2->data)
            return 0;
        list1=list1->next;
        list2=list2->next;
    }
    if(list1!=NULL || list2!=NULL)
        return 0;
    return 1;
}

int main(void)
{
    NODE *list1=NULL,*list2=NULL;
    insert(&list1,10);
    insert(&list1,20);
    insert(&list1,30);
    insert(&list1,40);
    insert(&list1,50);
    insert(&list1,60);
    insert(&list2,10);
    insert(&list2,20);
    insert(&list2,30);
    insert(&list2,40);
    insert(&list2,50);
    insert(&list2,60);
    if(equal(list1,list2))
        printf("Lists are equal\n");
    else
        printf("Lists are not equal\n");
    return 0;
}

