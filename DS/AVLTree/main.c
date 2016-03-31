#include <stdio.h>
#include <malloc.h>
#define TRUE 1
#define FALSE 0
struct node{
    struct node *lchild;
    int data;
    struct node *rchild;
    int balance;
};
typedef struct node NODE;
void inorder(NODE *ptr){
    if(ptr==NULL)
        return;
    inorder(ptr->lchild);
    printf("%d ",ptr->data);
    inorder(ptr->rchild);
}
NODE *rotateRight(NODE *pptr){
    NODE *ptr=pptr->lchild;
    pptr->lchild=ptr->rchild;
    ptr->rchild=pptr;
    return ptr;
}
NODE *rotateRight(NODE *pptr){
    NODE *ptr=pptr->rchild;
    pptr->rchild=ptr->lchild;
    ptr->lchild=pptr;
    return ptr;
}

int main(void)
{
    printf("Hello World!\n");
    return 0;
}

