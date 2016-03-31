#include<iostream>
using namespace std;
inline int square(int n){
	return (n*n);
}
int main(){
	int a=10,b=20,c;
	c=square(a);
	cout<<"No. is "<<a<<" Square is "<<c<<endl;
	c=square(b);
	cout<<"No. is "<<b<<" Square is "<<c<<endl;
	return 0;
}
