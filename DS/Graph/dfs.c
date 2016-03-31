#include<stdio.h>
#include<stdlib.h>
#include "stack.c"
#define initial 1
#define visited 2
#define N 9

int state[N];
int adj[N][N];

void DFSTraversal();
void DFS(int v);
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

void DFSTraversal(){
	int i,v;
	for(i=0;i<N;i++)
		state[i]=initial;
	printf("Enter the starting vertex for Breadth First Traversal : ");
	scanf("%d",&v);
	DFS(v);
}

void DFS(int v){
	int i;
	push(v);
	while(isEmptyStack()!=1){
		v=pop();
		printf("%d ",v);
		state[v]=visited;
		for(i=N-1;i>=0;i--){
			if((adj[v][i]==1)&&state[i]==initial){
				push(i);
			}+-
		}
	}
}


