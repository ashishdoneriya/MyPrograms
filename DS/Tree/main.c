#include <stdio.h>
#include <malloc.h>

struct node{
    struct node *lchild;
    int data;
    struct node *rchild;
};
typedef struct node NODE;
struct special{
    struct node *n;
    struct special *next;
};
typedef struct special STACK;
struct list{
    int data;
    struct list *next;
};
typedef struct list LIST;
void push(STACK **start, NODE *p){
    STACK *temp=(STACK *)malloc(sizeof(STACK));
    temp->n=p;
    temp->next=*start;
    *start=temp;
}
NODE *pop(STACK **start){
    STACK *temp;
    NODE *p;
    if(*start==NULL)
        return NULL;
    temp=*start;
    *start=(*start)->next;
    p=temp->n;
    free(temp);
    return p;
}
int isEmptyStack(STACK *start){
    if(start==NULL)
        return 1;
    else
        return 0;
}
typedef struct special QUEUE;
void insertQueue(QUEUE **front, QUEUE **rear, NODE *p){
    QUEUE *temp,*q;
    temp=(QUEUE *)malloc(sizeof(QUEUE));
    temp->n=p;
    temp->next=NULL;
    if(*front==NULL && *rear==NULL){
        *front=*rear=temp;
        return;
    }
    if(*front==*rear)
        (*front)->next=temp;
    else{
        for(q=*front; q->next!=*rear; q=q->next);
        q->next=temp;
    }
    *rear=temp;
}
NODE *removeQueue(QUEUE **front, QUEUE **rear){
    NODE *temp;
    QUEUE *p;
    p=*front;
    temp=p->n;
    if(*front==*rear)
        front=rear=NULL;
    else
        *front=(*front)->next;
    free(p);
    return temp;
}
void levelOrder(NODE *start){
    QUEUE *front=NULL,*rear=NULL;
    NODE *ptr;
    if(start==NULL){
        printf("\nTree is Empty");
        return;
    }
    ptr=start;
    insertQueue(&front,&rear,ptr);
    printf("\n");
    while(1){
        ptr=removeQueue(&front,&rear);
        if(ptr==NULL)
            return;
        printf("%d ",ptr->data);
        if(ptr->lchild!=NULL)
            insertQueue(&front,&rear,ptr->lchild);
        if(ptr->rchild!=NULL)
            insertQueue(&front,&rear,ptr->rchild);
    }
}
void preorder(NODE *start){
    STACK *stk=NULL;
    NODE *temp;
    if(start==NULL){
        printf("\nTree is Empty");
        return;
    }
    push(&stk,start);
    printf("\n");
    while(!isEmptyStack(stk)){
        temp=pop(&stk);
        printf("%d ",temp->data);
        if(temp->rchild!=NULL)
            push(&stk, temp->rchild);
        if(temp->lchild!=NULL)
			push(&stk, temp->lchild);
	}
}
void inorder_nrec(NODE *start){
	STACK *stk=NULL;
	NODE *temp=start;
	if(start==NULL){
		printf("\nTree is Empty");
		return;
	}
	printf("\n");
	while(1){
		while(temp!=NULL){
			push(&stk,temp);
			temp=temp->lchild;
		}
		temp=pop(&stk);
		if(temp==NULL)
				break;
		printf("%d ",temp->data);
		temp=temp->rchild;
	}
}
void inorder(NODE *ptr){
	if(ptr==NULL)
		return;
	inorder(ptr->lchild);
	printf("%d ",ptr->data);
	inorder(ptr->rchild);
}
void postorder_nrec(NODE *start){
    STACK *stk=NULL;
    NODE *ptr=start,*q=start;
    if(ptr==NULL){
        printf("\nTree is Empty");
        return;
    }
    while(1){
        while(ptr->lchild!=NULL){
            push(&stk,ptr);
            ptr=ptr->lchild;
        }
        while(ptr->rchild==NULL || ptr->rchild==q){
            printf("%d ",ptr->data);
            if(isEmptyStack(stk))
                return;
            ptr=pop(&stk);
        }
        push(&stk,ptr);
        ptr=ptr->rchild;
    }
}
void postorder(NODE *ptr){
    if(ptr==NULL)
        return;
    postorder(ptr->lchild);
    postorder(ptr->rchild);
    printf("%d ",ptr->data);
}
int getHeight(NODE *ptr){
    int left, right;
    if(ptr==NULL)
        return 0;
    left=getHeight(ptr->lchild);
    right=getHeight(ptr->rchild);
    if(left>right)
        return (1 + left);
    else
        return (1 + right);
}
NODE *constructPre(LIST *inptr, LIST *preptr, int x){
    NODE *temp;
    LIST *q;
    int i,j;
    if(x==0)
        return NULL;
    temp=(NODE *)malloc(sizeof(NODE));
    temp->data=preptr->data;
    temp->lchild=temp->rchild=NULL;
    if(x==1)
        return temp;
    q=inptr;
    for(i=0; q->data != preptr->data; q=q->next, i++);
    temp->lchild=constructPre(inptr, preptr->next,i);
    for(j=1; j<=i+1; j++)
        preptr=preptr->next;
    temp->rchild=constructPre(q->next, preptr, x-i-1);
    return temp;
}
NODE *constructPost(LIST *inptr, LIST *postptr, int x){
    NODE *temp;
    LIST *q, *ptr;
    int i,j;
    if(x==0)
        return NULL;
    for(i=0, ptr=postptr; i<x; i++, ptr=ptr->next);
    temp=(NODE *)malloc(sizeof(NODE));
    temp->data=ptr->data;
    temp->lchild=temp->rchild=NULL;
    if(x==1)
        return temp;
    for(i=0, q=inptr; q->data!=ptr->data; q=q->next, i++);
    temp->lchild=constructPost(q->next, postptr, i);
    for(j=1; j<=i; j++, postptr=postptr->next);
    temp->rchild=constructPost(q->next, postptr, x-i-1);
    return temp;
}
NODE *search_nrec(NODE *ptr, int x){
    while(ptr!=NULL){
        if(x < ptr->data)
            ptr=ptr->lchild;
        else if(x > ptr->data)
            ptr=ptr->rchild;
        else
            return ptr;
    }
    return NULL;
}
NODE *search(NODE *ptr, int x){
    if(ptr==NULL)
        return NULL;
    else if(ptr->data > x)
        return search(ptr->lchild, x);
    else if(ptr->data <x)
        return search(ptr->rchild, x);
    else
        return ptr;
}
NODE *min_nrec(NODE *ptr){
    if(ptr==NULL)
        return NULL;
    while(ptr->lchild!=NULL)
        ptr=ptr->lchild;
    return ptr;
}
NODE *min(NODE *ptr){
    if(ptr==NULL)
        return NULL;
    else if(ptr->lchild==NULL)
        return ptr;
    else
        return min(ptr->lchild);
}
NODE *max_nrec(NODE *ptr){
    if(ptr==NULL)
        return NULL;
    while(ptr->rchild!=NULL)
        ptr=ptr->rchild;
    return ptr;
}
NODE *max(NODE *ptr){
    if(ptr==NULL)
        return NULL;
    else if(ptr->rchild==NULL)
        return ptr;
    else
        return max(ptr->rchild);
}
NODE *insert_nrec(NODE *root, int x){
    NODE *temp,*par, *ptr;
    par=NULL;
    ptr=root;
    while(ptr!=NULL){
        par=ptr;
        if(x < ptr->data)
            ptr=ptr->lchild;
        else if(x > ptr->data)
            ptr=ptr->rchild;
        else
            return root;
    }
    temp=(NODE *)malloc(sizeof(NODE));
    temp->data=x;
    temp->lchild=temp->rchild=NULL;
    if(par==NULL){
        par=temp;
        return par;
    }
    else if(par->data > x)
        par->lchild=temp;
    else
        par->rchild=temp;
    return root;
}
NODE *insert(NODE *ptr, int x){
    if(ptr==NULL){
        ptr=(NODE *)malloc(sizeof(NODE));
        ptr->lchild=ptr->rchild=NULL;
        ptr->data=x;
    }
    else if( x < ptr->data)
        ptr->lchild=insert(ptr->lchild, x);
    else if (x > ptr->data)
            ptr->rchild=insert(ptr->rchild, x);
    else
        printf("\nDuplicate");
    return ptr;
}
NODE *case_a(NODE *root, NODE *par, NODE *ptr){
    if(par==NULL)
        root=NULL;
    else if(par->lchild==ptr)
        par->lchild=NULL;
    else if(par->rchild==ptr)
        par->rchild=NULL;
    free(ptr);
    return root;
}
NODE *case_b(NODE *root, NODE *par, NODE *ptr){
    NODE *child;
    if(ptr->lchild!=NULL)
        child=ptr->lchild;
    else
        child=ptr->rchild;
    if(par==NULL)
        root=child;
    else if(par->lchild==ptr)
        par->lchild=child;
    else
        par->rchild=child;
    free(ptr);
    return root;
}

NODE *case_c(NODE *root, NODE *ptr){
    NODE *presucc=ptr, *succ;
    for(succ=ptr->rchild; succ->lchild!=NULL; presucc=succ, succ=succ->lchild);
    ptr->data=succ->data;
    if(succ->lchild==NULL && succ->rchild==NULL)
        root=case_a(root, presucc, succ);
    else
        root=case_b(root, presucc, succ);
    return root;
}
NODE *del_nrec(NODE *root, int key){
    NODE *ptr=root, *par=NULL;
    while(ptr!=NULL){
        if( key == ptr->data)
            break;
        par=ptr;
        if(key < ptr->data)
            ptr=ptr->lchild;
        else
            ptr=ptr->rchild;
    }
    if(ptr==NULL)
        printf("Key not found");
    else if(ptr->lchild !=NULL && ptr->rchild!=NULL)
        root=case_c(root, ptr);
    else if(ptr->lchild!=NULL || ptr->rchild!=NULL)
        root=case_b(root, par, ptr);
    else
        root=case_a(root, par, ptr);
    return root;
}
NODE *del_nrec1(NODE *root, int key){
    NODE *par, *ptr, *child, *succ, *parsucc;
    ptr=root;
    par=NULL;
    while(ptr!=NULL){
        if (ptr->data==key)
            break;
        par=ptr;
        if(ptr->data >key)
            ptr=ptr->lchild;
        else if (ptr->data < key)
            ptr=ptr->rchild;
    }
    if(ptr==NULL){
        printf("\nKey not Found");
        return root;
    }
    if( (ptr->lchild!=NULL) && (ptr->rchild!=NULL) ){
        parsucc=ptr;
        succ=ptr->rchild;
        while(succ->lchild!=NULL){
            parsucc=ptr;
            succ=succ->lchild;
        }
        ptr->data=succ->data;
        ptr=succ;
        par=parsucc;
    }
    if(ptr->lchild!=NULL)
        child=ptr->lchild;
    else
        child=ptr->rchild;
    if(par==NULL)
        root=child;
    else if(par->lchild==ptr)
        par->lchild=child;
    else
        par->rchild=child;
    free(ptr);
    return root;
}
int getKthsmall(NODE *start, int k){
    STACK *stk=NULL;
    NODE *temp=start;
    int x=1;
    if(start==NULL){
        printf("\nTree is Empty");
        return;
    }
    printf("\n");
    while(1){
        while(temp!=NULL){
            push(&stk,temp);
            temp=temp->lchild;
        }
		temp=pop(&stk);
        if(temp==NULL)
				break;
		if (x==k)
			return temp->data;
		x++;
        temp=temp->rchild;
     }
}
int getInorderSuccessor(NODE *root, int k){
	STACK *stk=NULL;
    NODE *temp=root, *prev=NULL;
    if(root==NULL){
        printf("\nTree is Empty");
        return;
    }
    printf("\n");
    while(1){
        while(temp!=NULL){
            push(&stk,temp);
            temp=temp->lchild;
        }
		temp=pop(&stk);
        if(temp==NULL)
				break;
        if(prev!=NULL && prev->data==k)
			return  temp->data;
		prev=temp;
	}
}
/*
void inorderArr(int arr[], int size, int k){
    if(k>size)
        return;
    inorderArr(arr,size,2k+1);
    printf("%d ",arr[k]);
    inorderArr(arr,size,2k+2);
}
*/
int isPathExist(NODE *start, int k){
	int l,r,d;
	if(k<0) return 0;
	else if(start==NULL){
		if(k==0)
			return 1;
		else return 0;
	}
	else{
		d=k - start->data;
		return isPathExist(start->lchild,d)||isPathExist(start->rchild,d);
	}
}

void createDouble(NODE *start){
	NODE *temp;
	if(start==NULL)
		return;
	temp=(NODE *)malloc(sizeof(NODE));
	temp->lchild=start->lchild;
	temp->rchild=NULL;
	temp->data=start->data;
	start->lchild=temp;
	createDouble(temp->lchild);
	createDouble(start->rchild);
}
int getMax(int *count,int h){
	int max=*count, i=0;
	for(i=0; i<h; i++){
		if(max < *(count+i))
			max=*(count+i);
	}
	return max;
}
int setLevel(NODE *root,int *count, int level){
	if(root==NULL)
		return;
	(*(count+level))++;
	setLevel(root->lchild,count,level+1);
	setLevel(root->rchild,count,level+1);
}
int getMaxWidth(NODE *root){
	int temp;
	int h=getHeight(root);
	int *count=(int *)malloc(sizeof(int)*h);
	setLevel(root,count,0);
	temp=getMax(count,h);
	free(count);
	return temp;
}
void printRange(NODE *root, int low, int high){
	int d;
	if(root==NULL)
		return;
	d=root->data;
	printRange(root->lchild,low,high);
	if(d>=low && d<=high)
		printf("%d ",d);
	printRange(root->rchild,low,high);
}
int isSumTree_rec(NODE *root){
	int l,r;
	if(root==NULL)
		return 0;
	l=isSumTree_rec(root->lchild);
	r=isSumTree_rec(root->rchild);
	if(l==-1 || r==-1)
		return -1;
	if(root->data==l+r)
		return root->data;
	else
		return -1;
}

int isSumTree(NODE *root){
	if(root==NULL)
		return 1;
	else if(root->data==0 && (isSumTree_rec(root->lchild)+isSumTree_rec(root->rchild))==0)
		return 1;
	else if(isSumTree_rec(root)>0)
		return 1;
	else
		return 0;
}

NODE *getNODE(NODE *tree, int data){
	NODE *lch,*rch;
	if(tree==NULL)
		return NULL;
	if(tree->data==data)
		return tree;
	lch=getNODE(tree->lchild,data);
	if(lch!=NULL)
		return lch;
	rch=getNODE(tree->rchild,data);
	if(rch!=NULL)
		return rch;
	else return NULL;
}

int isTreeEqual(NODE *tree1,NODE *tree2){
	int cur,lc,rc;
	if (tree1==NULL && tree2==NULL)
			return 1;
	else if(tree1!=NULL && tree2==NULL)
		return 0;
	else if(tree1==NULL && tree2!=NULL)
		return 0;
	else if(tree1->data != tree2->data)
		return 0;
	else
		return ( isTreeEqual(tree1->lchild, tree2->lchild) && isTreeEqual(tree1->rchild, tree2->rchild) );
}

int isSubTree(NODE *tree, NODE *subtree){
	return isTreeEqual( getNODE(tree,subtree->data), subtree);
}

void getMaxSizeBST_rec(NODE *tree,int *flag, int *size){
	int lflag=1, rflag=1, lsize, rsize;
	if(tree==NULL){
		*size=0;
		return;
	}
	getMaxSizeBST_rec(tree->lchild, &lflag, &lsize);
	getMaxSizeBST_rec(tree->rchild, &rflag, &rsize);
	if(lflag==0 || rflag==0)
		*flag==0;
	else if( tree->lchild!=NULL && (tree->lchild->data)>tree->data)
		*flag=0;
	else if( tree->rchild!=NULL && (tree->rchild->data)< tree->data)
		*flag=0;
	if(*flag==0)
			*size=lsize>rsize?lsize:rsize;
	else
			*size=1+lsize+rsize;
}

int getMaxSizeBST(NODE *tree){
	int flag,size;
	getMaxSizeBST_rec(tree,&flag,&size);
	return size;
}
int getSize(NODE *tree){
	if(tree==NULL)
		return  0;
	else return (1 + getSize(tree->lchild) + getSize(tree->rchild));
}

/*
int isCompleteBT_rec(NODE *tree, int cur, int size){
	int l=1,r=1;
	if(cur>=size)
		return 0;
	if (tree->rchild!=NULL)
		 r =isCompleteBT_rec(tree->rchild, (2*cur+2), size);
	if (tree->lchild!=NULL)
		 l = isCompleteBT_rec(tree->lchild, (2*cur+1), size);
	return l&&r;
}*/

int isCompleteBT_rec(NODE *tree, int cur, int size){
	if(tree==NULL)
		return 1;
	else if (cur>=size)
		return 0;
	else return (isCompleteBT_rec(tree->lchild, (2*cur+1), size)) && (isCompleteBT_rec(tree->rchild, (2*cur+2), size));
}
int isCompleteBT(NODE *root){
	return isCompleteBT_rec(root, 0, getSize(root));
}
int main(void){
    NODE *root=NULL;
    root=insert_nrec(root,50);
    root=insert_nrec(root,25);
    root=insert_nrec(root,75);
    root=insert_nrec(root,11);
    root=insert_nrec(root,35);
    root=insert_nrec(root,65);
    root=insert_nrec(root,85);
    root=insert_nrec(root,1);
   // root=insert_nrec(root,49);
    //root=insert_nrec(root,89);
    
 //   inorder(root);
   //createDouble(root);
    printf("\n%d",isCompleteBT(root));
    return 0;
}
