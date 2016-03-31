#include<stdio.h>
#define N 4
int main()
{
	int adj[N][N],path[N][N],path1[N][N],p,h,i,j,k,l;
	printf("Enter Adjacency Matrix\n");
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			scanf("%d",&adj[i][j]);
			path1[i][j]=adj[i][j];
	}
	for(h=0;h<N;h++)
	{
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				if((i==h)||(j==h)||(i==j))
				{
					path[i][j]=path1[i][j];
					continue;
				}
				else
				{
					p=adj[i][h]+path1[h][j];
					if(p<path1[i][j])
						path[i][j]=p;
					else
						path[i][j]=path1[i][j];
				}
			}
		}
		for(k=0;k<N;k++)
		{
			for(l=0;l<N;l++)
				path1[k][l]=path[k][l];
		}
	}
	printf("Path matrix is\n");
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			printf("%d\t",path1[i][j]);
		printf("\n");
	}
}
