#include<iostream>
using namespace std;
void swap(int &, int &);

int main(){
	int a,b;
	cout<<"Enter a and b : ";
	cin>>a>>b;
	swap(a,b);
	cout<<"a = "<<a<<"\tb = "<<b;
	return 0;
}
void swap(int &p, int &q){
	int temp;
	temp=p;
	p=q;
	q=temp;
}
