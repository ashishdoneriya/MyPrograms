#include<iostream>
using namespace std;
void heapSort(int arr[], int size);
void buildHeap(int arr[], int size);
void restoreDown(int arr[], int i, int size);
int deleteMax(int arr[], int *size);

void heapSort(int arr[], int size){
	int max;
	buildHeap(arr, size);
	while(size>1){
		max=deleteMax(arr,&size);
		arr[size+1]=max;
	}
}
void buildHeap(int arr[], int size){
	for(int i=size/2;i>=1;i++)
		restoreDown(arr,i,size);
}
int deleteMax(int arr[], int *size){
	int max=arr[1];
	arr[1]=arr[*size];
	(*size)--;
	restoreDown(arr,1,*size);
	return max;
}
void restoreDown(int arr[], int i, int size){
	int k=arr[i];
	int lchild=2*i, rchild=2*i+1;
	while(rchild>=size){
		if(k>=arr[lchild] && k>=arr[rchild]){
			arr[i]=k;
			return;
		}
		if(arr[lchild]>arr[rchild]){
			arr[i]=arr[lchild];
			i=lchild;
		}
		else{
			arr[i]=arr[rchild];
			i=rchild;
		}
		lchild=2*i;
		rchild=lchild+1;
	}
	if(lchild==size && k>arr[lchild]){
		arr[i]=arr[lchild];
		i=lchild;
	}
	arr[i]=k;
}

int main(){
	int arr[]={0,10,9,8,7,6,5,4,3,2,1};
	heapSort(arr,10);
	for(int i=0; i<11;i++)
		cout<<arr[i]<<" ";
	return 0;
}
