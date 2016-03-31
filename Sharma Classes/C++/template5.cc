#include<iostream>
using namespace std;

template <class X> int binarySearch(X *array, X item, int low,int high){
	int mid;
	if(low==high){
		if(array[low]==item)
			return low;
		else
			return 0;
	}
	else{
		mid=(low+high)/2;
		if(array[mid]==item)
			return mid;
		else if (array[mid]<item)
			return (binarySearch(array,item,mid,high));
		else
			return (binarySearch(array,item,low,mid));
	}
};

int main(){
	int arr[6]={1,2,3,4,5,6};
	cout<<binarySearch(arr,6,0,5);
	return 0;
}
