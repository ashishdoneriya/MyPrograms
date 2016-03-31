#include<iostream>
using namespace std;
template <class X>
void swaparg(X &a, X &b){
	X temp;
	temp=a;
	a=b;
	b=temp;
}
int main(){
	char a='p',b='q';
	swaparg(a, b);
	cout<<a<<" "<<b;
	return 0;
}
