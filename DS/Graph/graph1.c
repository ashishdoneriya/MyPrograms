#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct Vertex{
	int info;
	struct Vertex *nextVertex;
	struct Edge * firstEdge;
}*start=NULL;
struct Edge{
	struct Vertex *destVertex;
	struct Edge *nextEdge;
};

struct Vertex *findVertex(int u);
void insertVertex(int u);
void insertEdge(int u, int v);
void deleteVertex(int u);
void deleteEdge(int u, int v);
void deleteIncomingEdged(int u);
void display();


int main(){
	int choice, u, v;
	while(1){
		printf("\n1. Insert a vertex\n");
		printf("2. Insert an Edge\n");
		printf("3. Delete a vertex\n");
		printf("4. Delete an edge\n");
		printf("5. Display\n");
		printf("6. Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
					printf("Enter a vertex to be inserted : ");
					scanf("%d",&u);
					insertVertex(u);
					break;
			case 2:
					printf("Enter the source and destination of vertex : ");
					scanf("%d %d",&u,&v);
					insertEdge(u,v);
					break;
			case 3:
					printf("Enter a vertex to be deleted : ");
					scanf("%d",&u);
					deleteIncomingEdged(u);
					deleteVertex(u);
					break;
			case 4:
					printf("Enter the Edge to be deleted : ");
					scanf("%d %d",&u,&v);
					deleteEdge(u,v);
					break;
			case 5:
					display();
					break;
			case 6:
					exit(0);
			default:
					printf("Wrong choice\n");
		}
	}
}


void insertVertex(int u){
	struct Vertex *temp,*p;
	temp=(struct Vertex *)malloc(sizeof(struct Vertex));
	temp->info=u;
	temp->nextVertex=NULL;
	temp->firstEdge=NULL;
	if(start==NULL){
		start=temp;
		return;
	}
	p=start;
	while(p->nextVertex!=NULL)
		p=p->nextVertex;
	p->nextVertex=temp;
}


void insertEdge(int u, int v){
	struct Vertex *pointerU,*pointerV;
	struct Edge *temp,*p;
	pointerU=findVertex(u);
	pointerV=findVertex(v);
	if(pointerU==NULL){
		printf("Can't find vertex %d.\nEdge%d-%d can't be inserted",u,u,v);
		return;
	}
	if(pointerV==NULL){
		printf("Can't find vertex %d.\nEdge%d-%d can't be inserted",v,u,v);
		return;
	}
	temp=(struct Edge *)malloc(sizeof(struct Edge));
	temp->destVertex=pointerV;
	temp->nextEdge=NULL;
	if(pointerU->firstEdge==NULL){
		pointerU->firstEdge=temp;
		return;
	}
	p=pointerU->firstEdge;
	while(p->nextEdge!=NULL)
		p=p->nextEdge;
	p->nextEdge=temp;
}

struct Vertex *findVertex(int u){
	struct Vertex *temp=start;
	while(temp!=NULL){
		if(temp->info==u)
			return temp;
		else
			temp=temp->nextVertex;
	}
	return NULL;
}

void deleteVertex(int u){
	struct Vertex *temp,*p;
	struct Edge *q,*r;
	if(start==NULL){
		printf("No vertex to be deleted\n");
		return;
	}
	if(start->info==u){
		p=start;
		start=start->nextVertex;
	}
	else{
		temp=start;
		while(temp!=NULL){
			if((temp->nextVertex)->info==u){
				p=temp->nextVertex;
				temp->nextVertex=p->nextVertex;
				break;
			}
			else
				temp=temp->nextVertex;
		}
		if(temp==NULL){
			printf("Edge not found");
			return;
		}
	}
	q=p->firstEdge;
	while(q!=NULL){
		r=q;
		q=q->nextEdge;
		free(r);
	}
	free(p);
}

void deleteEdge(int u, int v){
	struct Vertex *p;
	struct Edge *q,*r;
	p=findVertex(u);
	if(p==NULL){
		printf("Vertex %d not exist",u);
		return;
	}
	if(p->firstEdge==NULL){
	//	printf("Edge %d-%d not exist",u,v);
		return;
	}
	q=p->firstEdge;
	if(q->destVertex->info==v){
		p->firstEdge=q->nextEdge;
		free(q);
		return;
	}
	else{
		while(q!=NULL){
			r=q->nextEdge;
			if(r->destVertex->info==v){
				q->nextEdge=r->nextEdge;
				free(r);
				return;
			}
			else
				q=q->nextEdge;
		}
	}
}

void deleteIncomingEdged(int u){
	struct Vertex *temp, *p,*q;
	struct Edge *r,*s;
	int v;
	if(start==NULL)
		return;
	temp=start;
	while(temp!=NULL){
		deleteEdge(temp->info,u);
		temp=temp->nextVertex;
	}
}

void display(){
	struct Vertex *p=start;
	struct Edge *q;
	if(start==NULL){
		printf("Graph Empty");
		return;
	}
	while(p!=NULL){
		printf("\n%d -->",p->info);
		q=p->firstEdge;
		while(q!=NULL){
			printf(" %d",q->destVertex->info);
			q=q->nextEdge;
		}
		p=p->nextVertex;
	}
}
