#include<iostream>
#include<malloc.h>
using namespace std;
void display(int *a,int n){
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void Adjust(int a[], int i, int n){
	int j=2*i;
	int item=a[i];
	cout<<"Index of i= "<<i<<endl;
	cout<<"Index of j= "<<j<<endl;
	while(j<=n){
		cout<<"Comparison between 3 numbers "<<a[i]<<" "<<a[j]<<" and "<<a[j+1]<<endl;
		if( (j<=n) && (a[j]<a[j+1]) )
			j=j+1;
		if(item>=a[j])
			break;
		a[j/2]=a[j];
		j=2*j;
	}
	a[j/2]=item;
	cout<<"three numbers are "<<a[i]<<" "<<a[2*i]<<" "<<a[2*i+1]<<endl;
}
void Heapify(int a[], int n){
	for(int i=n/2;i>=0;i--){
		Adjust(a,i,n);
	}
}
void HeapSort(int *a, int n){
	int t;
	Heapify(a,n);
	cout<<"After heapifying elements are ";
	display(a,n);
	for(int i=n;i>1;i--){
		t=a[1];
		a[1]=a[i];
		a[i]=t;
//		cout<<"Largest Element = "<<a[i]<<endl;
		Adjust(a,1,i-1);
	}
}

int main(){
	int *a,n,i;
	cout<<"Enter the number of Elements : ";
	cin>>n;
	a=new int[n+1];
//	cout<<"Enter numbers"<<endl;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	HeapSort(a,n);
	cout<<"After sorting elements are"<<endl;
	display(a,n);
	return 0;
}
