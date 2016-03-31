#include<iostream>
#include<malloc.h>
using namespace std;

class Array{
	int *p;
	int n;
	int sum;
public:
	Array( int = 0 );
	void inputData();
	void calculate();
	void display();
	~Array();
};

Array::Array( int x ){
	if( x == 0 ){
		cout<<"Enter the size of Array : ";
		cin>>n;
	}
	else
		n = x;
	sum = 0;
	p = new int[n];
	if (p == 0 )
		cout<<"Insufficient Memory";
}	

void Array::inputData(){
	cout<<"Enter the elements of array"<<endl;
	for( int i = 0; i<n; i++ )
		cin>>*(p+i);
}
void Array::calculate(){
	for ( int i = 0; i < n; i++ )
		sum = sum + *( p + i );
}
void Array::display(){
	for ( int i = 0; i < n; i++ )
		cout<< *( p + i ) <<"\t";
	cout << "Sum of Elements = " << sum;
}
Array::~Array(){
	delete []p;
}

int main(){
	Array p();
	p.inputData();
	p.calculate();
	p.display();
	return 0;
}
