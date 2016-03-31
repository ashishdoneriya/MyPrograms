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

void removeDuplicatesSorted(NODE *start){
    NODE *p,*q;
    if(start->next==NULL)
        return;
    for(p=start; (p!=NULL) && (p->next!=NULL);){
        q=p->next;
        if(q->data==p->data){
            p->next=q->next;
            free(q);
            continue;
        }
        p=p->next;
    }
}

void removeDuplicatesUnsorted(NODE *start){
    NODE *p,*q,*prev;
    for(p=start; (p!=NULL) && (p->next!=NULL);){
        for(prev=p,q=p->next;q!=NULL;){
            if(q->data==p->data){
                prev->next=q->next;
                free(q);
                q=prev->next;
                continue;
            }
            prev=q;
            q=q->next;
        }
        p=p->next;
    }
}
int isAvailable(NODE *p, int x){
    while(p!=NULL){
        if(p->data==x)
            return 1;
        p=p->next;
    }
    return 0;
}
void insertAtEnd(NODE **start, int x){
    NODE *p,*temp;
    temp=(NODE *)malloc(sizeof(NODE));
    temp->data=x;
    temp->next=NULL;
    if(*start==NULL){
        *start=temp;
        return;
    }
    for(p=*start; p->next!=NULL; p=p->next);
    p->next=temp;
}

NODE *getIntersection(NODE *list1, NODE *list2){
    NODE *start=NULL;
    while(list1!=NULL){
        if(isAvailable(list2,list1->data))
            insertAtEnd(&start,list1->data);
        list1=list1->next;
    }
    return start;
}
NODE *getUnion(NODE *list1, NODE *list2){
    NODE *start=NULL;
    while(list1!=NULL){
        if(!isAvailable(start,list1->data))
            insertAtEnd(&start,list1->data);
        list1=list1->next;
    }
    while(list2!=NULL){
        if(!isAvailable(start,list2->data))
            insertAtEnd(&start,list2->data);
        list2=list2->next;
    }
    return start;
}
void separate(NODE **list1, NODE **list2, NODE **list3){
    NODE *l2=NULL,*l3=NULL;
    while((*list1)!=NULL){
        if( ((*list1)->data) >=0){
            if(*list2==NULL)
                l2=*list2=*list1;
            else{
                l2->next=*list1;
                l2=l2->next;
            }
            *list1=(*list1)->next;
            l2->next=NULL;
        }
        else{
            if(*list3==NULL)
                l3=*list3=*list1;
            else{
                l3->next=*list1;
                l3=l3->next;
            }
            *list1=(*list1)->next;
            l3->next=NULL;
        }
    }
}


int main(void)
{
    NODE *start=NULL,*l1=NULL,*l2=NULL;
    insert(&start,10);
    insert(&start,-60);
    insert(&start,20);
    insert(&start,-30);
    insert(&start,40);
    insert(&start,-10);
    insert(&start,40);
    insert(&start,-50);
    insert(&start,60);
    separate(&start,&l1,&l2);
    display(start);
    display(l1);
    display(l2);
    return 0;
}

