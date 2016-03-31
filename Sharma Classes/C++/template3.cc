#include<iostream>
using namespace std;
template <class X> void print(X a){
	cout<<a<<endl;
}
template <class X,class Y> void print(X a, Y b){
	cout<<a<<" "<<b<<endl;
}
template <class X,class Y,class Z> void print(X a, Y b, Z c){
	cout<<a<<" "<<b<<" "<<c<<endl;
}
int main(){
	print(10);
	print("ashish");
	print("ashish","doneriya");
	print('c',1);
	print(101112011,"ashish",'b');
	print(12.1,10,'a');
	print(100,200.10);
	return 0;
}
