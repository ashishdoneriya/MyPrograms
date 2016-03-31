#include<stdio.h>
#include<malloc.h>

struct queue{
	int data;
	struct queue *next;
}*front=NULL,*rear=NULL;


void insertQueue(int x){
	struct queue *temp;
	temp=(struct queue *)malloc(sizeof(struct queue));
	temp->data=x;
	temp->next=NULL;
	if(front==NULL)
		front=temp;
	else
		rear->next=temp;
	rear=temp;
}


int deleteQueue(){
	struct queue *temp;
	int x;
	if(front==NULL)
		return -1;
	temp=front;
	x=temp->data;
	front=front->next;
	free(temp);
	return (x);
}


int isEmptyQueue(){
	if(front==NULL)
		return 1;
	else
		return 0;
}

/*
int main(){
	insertQueue(10);
	printf("Front data = %d\n",front->data);
	printf("%d\t",deleteQueue());
	printf("\nisEmptyQueue() = %d\n",isEmptyQueue());
	insertQueue(2);
	insertQueue(3);
	insertQueue(4);
	insertQueue(5);
	insertQueue(6);
	insertQueue(7);
	insertQueue(8);
	insertQueue(9);
	insertQueue(11);
	insertQueue(100);
	printf("%d\t",deleteQueue());
	printf("%d\t",deleteQueue());
	printf("%d\t",deleteQueue());
	printf("%d\t",deleteQueue());
	printf("%d\t",deleteQueue());
	printf("%d\t",deleteQueue());
	printf("%d\t",deleteQueue());
	printf("%d\t",deleteQueue());
	printf("%d\t",deleteQueue());
	printf("%d\t",deleteQueue());
	printf("%d\t",deleteQueue());
	printf("%d\t",deleteQueue());
	printf("%d\t",deleteQueue());
	printf("%d\t",deleteQueue());
	printf("\nisEmptyQueue() = %d\n",isEmptyQueue());
	return 0;
}
*/
