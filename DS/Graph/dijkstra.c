#include<stdio.h>
#define N 8
#define NIL -1
#define PERM 1
#define TEMP 0
#define infinity 99999

int adj[N][N];
int predecessor[N];
int pathLength[N];
int status[N];

void createGraph();
void Dijkstra(int s);
int minTemp();
void display();
int main(){
	int s;
	createGraph();
	printf("Enter source vertex : ");
	scanf("%d",&s);
	Dijkstra(s);
	display();
	return 0;
}

void Dijkstra(int s){
	int i,current,m;
	for(i=0;i<N;i++){
		pathLength[i]=infinity;
		predecessor[i]=NIL;
		status[i]=TEMP;
	}
	pathLength[s]=0;
	while(1){
		current=minTemp();
		if(current==NIL)
			return;
		status[current]=PERM;
		for(i=0;i<N;i++){
			if(adj[current][i]!=0 && status[i]==TEMP){
				m=pathLength[current]+adj[current][i];
				if(pathLength[i]>m){
					predecessor[i]=current;
					pathLength[i]=m;
				}
				
			}
		}
	}
}

int minTemp(){
	int min=infinity,v=NIL,i;
	for(i=0;i<N;i++){
		if(status[i]==TEMP){
			if(min>pathLength[i]){
				min=pathLength[i];
				v=i;
			}
		}
	}
	return v;
}

void display(){
	int i;
	printf("Vertex\tPath Length\tPredecessor\n");
	for(i=0;i<N;i++)
		printf("%d\t%d\t\t%d\n",i,pathLength[i],predecessor[i]);
}

void createGraph(){
	int i,j,x=(N*(N+1))/2;
	int u,v,cost;
	printf("Enter:\n");
	for(i=0;i<x;i++){
		scanf("%d %d %d",&u,&v,&cost);
		if(u==-1&&v==-1)
			return;
		else
			adj[u][v]=cost;
	}
}
/*
void adjMatrix(){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%d ",adj[i][j]);
		}
		printf("\n");
	}
}
*/


/*
INPUT : -
0 2 2
0 3 7
0 1 8
1 5 16
2 3 4
2 6 3
2 0 5
3 4 9
4 0 4
4 5 5
4 7 8
6 2 6
6 3 3
6 4 4
7 6 5
7 5 2
-1 -1 0
0

OUTPUT:-

Vertex	Path Length	Predecessor
0	
* 
* 0		-1
1	8		0
2	2		0
3	6		2
4	9		6
5	14		4
6	5		2
7	17		4
*/
