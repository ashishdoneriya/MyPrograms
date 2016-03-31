#include<iostream>
using namespace std;

class Box{
	int l, b, h;
public:
	void get(){
		cout<<"Enter l, b and h ";
		cin>>l>>b>>h;
	}
	void show(){
		cout<<l<<" "<<b<<" "<<h<<endl;
	}
};

class Carton:public Box{
	char mat[20];
public:
	void set(){
		cout<<"Enter material name : ";
		cin>>mat;
	}
	void display(){
		cout<<"Material is "<<mat<<endl;
	}
};

int main(){
	Carton obj;
	obj.get();
	obj.set();
	obj.show();
	obj.display();
	return 0;
}
