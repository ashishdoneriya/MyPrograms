#include<iostream>
using namespace std;
void change(int &);
void change(int &p){
	p++;
}
int main(){
	int a=10;
	change(a);
	cout<<a;
	return 0;
}
