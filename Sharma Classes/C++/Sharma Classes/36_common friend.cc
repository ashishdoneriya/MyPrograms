#include<iostream>
using namespace std;
class Beta;
class Alpha{
	int a;
public:
	void get(){
		cout<<"Enter a : ";
		cin>>a;
	}
	friend void compare(Alpha, Beta);
};
class Beta{
	int b;
public:
	void set(){
		cout<<"Enter b : ";
		cin>>b;
	}
	friend void compare(Alpha, Beta);
};
void compare(Alpha x, Beta y){
	if(x.a>y.b)
		cout<<"Greater is "<<x.a;
	else if (y.b>x.a)
		cout<<"Greater is "<<y.b;
	else
		cout<<"Both equal";
}
int main(){
	Alpha obj1;
	Beta obj2;
	obj1.get();
	obj2.set();
	compare(obj1,obj2);
}
