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

class Carton:protected Box{
	char mat[20];
public:
	void set(){
		get();
		cout<<"Enter material name : ";
		cin>>mat;
	}
	void show(){
		Box::show();
		cout<<"Material is "<<mat<<endl;
	}
};

int main(){
	Carton obj;
	obj.set();
	obj.show();
	return 0;
}
