#include<iostream>
using namespace std;
class A{
public:
	A(){
		cout<<"In constructor of A"<<endl;
	}
	~A(){
		cout<<"In Distructor of A"<<endl;
	}
};
class B{
public:
	B(){
		cout<<"In constructor of B"<<endl;
	}
	~B(){
		cout<<"In Distructor of B"<<endl;
	}
};
class C:public B, public A{
public:
	C(){
		cout<<"In constructor of C"<<endl;
	}
	~C(){
		cout<<"In Distructor of C"<<endl;
	}
};

int main(){
	C obj;
}
