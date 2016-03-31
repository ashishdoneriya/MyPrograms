#include<iostream>
using namespace std;
void show();
int main(){
	show();
	show();
	show();
	return 0;
}
void show(){
	static int a;
	cout<<a<<endl;
	a++;
}
