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
class B:public A{
public:
	B(){
		cout<<"In constructor of B"<<endl;
	}
	~B(){
		cout<<"In Distructor of B"<<endl;
	}
};

int main(){
	B obj;
}
