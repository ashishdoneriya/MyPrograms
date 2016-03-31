#include<iostream>
using namespace std;

int main(){
	int a=10;
	int b=20;
	int &p=a;
	cout<<a<<" "<<p<<" "<<b<<endl;
	a=b;
	cout<<a<<" "<<p<<" "<<b<<endl;
	p=30;
	cout<<a<<" "<<p<<" "<<b<<endl;
	return 0;
}
