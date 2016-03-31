#include<stdio.h>
#include<stdlib.h>
#include "Queue.c"
#define initial 1
#define waiting 2
#define visited 3
#define N 9

int state[N];
int adj[N][N];

void bfTraversal();
void BFS(int v);
void createGraph();

int main(){
	createGraph();
	bfTraversal();
	return 0;
}

void createGraph(){
	int i,j;
	printf("Enter the adj matrix\n");
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			scanf("%d",&adj[i][j]);
		}
	}
}

void bfTraversal(){
	int i,v;
	for(i=0;i<N;i++)
		state[i]=initial;
	printf("Enter the starting vertex for Breadth First Traversal : ");
	scanf("%d",&v);
	BFS(v);
}

void BFS(int v){
	int i;
	insertQueue(v);
	state[v]=waiting;
	while(isEmptyQueue()!=1){
		v=deleteQueue();
		printf("%d ",v);
		state[v]=visited;
		
		for(i=0;i<N;i++){
			if((adj[v][i]==1)&&state[i]==initial){
				insertQueue(i);
				state[i]=waiting;
			}
		}
	}
}


