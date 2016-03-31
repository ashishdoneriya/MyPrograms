#include<stdio.h>
void selectionSort(int arr[], int n){
	int i,j,min,temp;
	for(i=0; i<n-1; i++){
		min=i;
		for(j=i+1; j<n; j++){
			if(arr[min]>arr[j])
				min=j;
		}
		if(min!=i){
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}
void bubbleSort(int arr[], int n){
	int i,j,temp;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(arr[j] > arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
} } } }

void insertionSort(int arr[], int n){
	int i,j,temp;
	for(i=1;i<n;i++){
		temp=arr[i];
		for(j=i-1; j>=0 && temp<arr[j]; j--)
			arr[j+1]=arr[j];
		arr[j+1]=temp;
	}
}
void merge(int arr[],int low, int mid, int high){
	int brr[50];
	int i=low, j=mid+1,k=0;
	while( i <=mid && j <=high ){
		if(arr[i] < arr[j]){
			brr[k]=arr[i];
			i++;
		}
		else{
			brr[k]=arr[j];
			j++;
		}
		k++;
	}
	if(j>high){
		while(i<=mid){
			brr[k]=arr[i];
			k++;
			i++;
		}
	}
	if(i>mid){
		while(j<=high){
			brr[k]=arr[j];
			k++;
			j++;
		}
	}
	for(i=low, j=0 ; i<=high ; i++, j++)
		arr[i]=brr[j];
}

void mergeSort(int arr[], int low, int high){
	if(low<high){
		int mid=(low+high)/2;
		mergeSort(arr,low,mid);
		mergeSort(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
}

int partition(int arr[], int low, int high){
	int first=arr[low];
	int i=low,j=high;
	int temp;
	do{
		while(first>arr[i])
			i++;
		while(first<arr[j])
			j--;
		if(i<j){
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}while(i<j);
	return j;
}
void quickSort(int arr[], int low, int high){
	if(low<high){
		int j=partition(arr,low,high);
		quickSort(arr,low,j);
		quickSort(arr,j+1,high);
	}
}
void restoreDown(int arr[],int i, int size){
	int k=arr[i];
	int lchild=2*i, rchild=2*i+1;
	while(rchild<=size){
		if(k>=arr[lchild] && k>=arr[rchild]){
			arr[i]=k;
			return;
		}
		else if(arr[lchild]>arr[rchild]){
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
	if(lchild==size && k<arr[lchild]){
		arr[i]=arr[lchild];
		i=lchild;
	}
	arr[i]=k;
}
		
void buildHeap(int arr[],int size){
	for(int i=size/2; i>=1; i--)
		restoreDown(arr,i,size);
}

int deleteMax(int arr[], int *size){
	int k=arr[1];
	arr[1]=arr[*size];
	(*size)--;
	restoreDown(arr,1,*size);
	return k;
}
	
void heapSort(int arr[], int size){
	buildHeap(arr,size);
	while(size>1){
		int max=deleteMax(arr,&size);
		arr[size+1]=max;
	}
}
	
int main(){
	int arr[]={0,6,7,3,8,9,2,4,10,5,1};
	quickSort(arr,0,10);
	for(int i=0;i<11;i++)
		printf("%d ",arr[i]);
	return 0;
}
