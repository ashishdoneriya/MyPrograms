#include "structure.c"
int count(NODE *p,int x){
    int n=0;
    while(p!=NULL){
        if(p->data==x)
            n++;
        p=p->next;
    }
    return n;
}
