/* Travelling Salesman Problem
 * Optimal Path
 * Date Created:		10/10/2012
 * Date Modified:	10/10/2012
 * Author :	Ashish Doneriya
 */
#include<iostream>
#include<malloc.h>
using namespace std;

int adj[4][4];
int n;	//n is the number of vertices

void path(int *ver, int *getPath){
	
	//For last Level when only one vertex remaining
	if(getPath[0]==0){
		getPath[0]=adj[ver[0]][0];
		getPath[n]=ver[0];
		return;
	}
	
	int split=getPath[0];
	
	int **ver2D, **getPath2D;
	ver2D = new int *[split];
	getPath2D = new int *[split];
	
	int i, j, k;
	//Allocating rows to ver2D
	for(i=0; i<split; i++)
		ver2D[i]=new int [split];
	
	//Copying values of ver into ver2D in all its Rows
	for(i=0; i<split;i++){
		ver2D[i][0]=i+1;
		for(j=1,k=1; j<=split; j++,k++){
			if(ver2D[i][0]==ver[j]){
				k--;
				continue;
			}
			ver2D[i][k]=ver[j];
		}
	}
	
	//Allocating rows to getPath2D
	for(i=0;i<split;i++)
		getPath2D[i]=new int[n+1];
	
	//Copying values of getPath into getPath2D in all its Rows
	for(i=0;i<split;i++){
		for(j=0;j<=n;j++){
			getPath2D[i][j]=getPath[j];
			getPath2D[i][0]=getPath2D[i][0]-1;
		}
	}
	
	//Recursion
	for(i=0;i<split;i++){
		getPath2D[i][n-split]=i;
		path(ver2D[i],getPath2D[i]);
		getPath2D[0] = getPath2D[0] + adj[ver[0]][ver2D[i][0]];
	}
	
	//Calculating maximum optimal Path
	int max=getPath2D[0][0], index=0;
	for(i=0;i<split;i++){
		if(max<getPath2D[i][0]){
			max=getPath2D[i][0];
			index=i;
		}
	}
	getPath=getPath2D[index];
}

int main(){
	cout<<"here";
	int *ver, *getPath;
	int i,j,temp, optCost;/*
	cout<<"Enter the number of vertices :";
	cin>>n;
	cout<<"Enter the data\n";
	n=4;
	adj=new int*[n];
	for(i=0; i<n; i++){
		adj[i] = new int[n];
	}
	/*Accepting the data from the user
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			cin>>temp;
			adj[i][j]=temp;
		}
	}*/
	n=4;
	adj[0][0]=0;
	adj[0][1]=10;
	adj[0][2]=15;
	adj[0][3]=20;
	adj[1][0]=5;
	adj[1][1]=0;
	adj[1][2]=9;
	adj[1][3]=10;
	adj[2][0]=6;
	adj[2][1]=13;
	adj[2][2]=0;
	adj[2][3]=12;
	adj[3][0]=8;
	adj[3][1]=8;
	adj[3][2]=9;
	adj[3][3]=0;
	ver=new int[n];
	getPath=new int[n+1];
	
	for(i=0; i<n; i++){
		ver[i]=i;
	}
	
	getPath[0]=n-1;
	path(ver,getPath);
	
	optCost=getPath[0];
	
	cout<<"Path is : ";
	for(i=1; i<=n; i++)
		cout<<getPath[i]<<"\t";
	
	cout<<"Optimal Cost is "<<optCost;
	
	return 0;
}
