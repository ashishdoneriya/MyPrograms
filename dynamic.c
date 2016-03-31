#include<stdio.h>
#include<string.h>
//#define input(n) scanf("%d",&n) 
int main(){
	int t,n,i,j,k;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&k);
		int arr[n],brr[k+1];
		memset (brr,0,sizeof(brr));
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);
		brr[0]=1;
		for(i=0;i<n;i++){
			for(j=k;j>=arr[i];j--){
				brr[j]=brr[j-arr[i]]|brr[j];
				printf("%d",brr[j]);
			}
			printf("\n");
		}
		printf("%d\n",brr[k]);
		}
}
