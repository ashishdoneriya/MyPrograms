//Program to accept two integers from the user add them and display the result

#include<iostream>
using namespace std;

class Num{
	int a,b,c;
public:
	void get();
	void add();
	void show();
};
void Num::get(){
	cout<<"Enter two numbers :: ";
	cin>>a>>b;
}
void Num::add(){
	c=a+b;
}
void Num::show(){
	cout<<"Sum is "<<c;
}
int main(){
	Num obj;
	obj.get();
	obj.add();
	obj.show();
	return 0;
}
