#include<iostream>
using namespace std;

class Num{
protected:
	int a, b;
public:
	void get(){
		cout<<"Enter 2 numbers : ";
		cin>>a>>b;
	}
	void show(){
		cout<<"a = "<<a<<"\tb = "<<b<<endl;
	}
};

class AddNum:public Num{
protected:
	int c;
public:
	void accept(){
		get();
	}
	void add(){
		c = a + b;
	}
	void display(){
		show();
		cout<<"Their sum is "<<c<<endl;
	}
};

class DiffNum:public AddNum{
	int d;
public:
	void input(){
		accept();
	}
	void diff(){
		d = a - b;
	}
	void print(){
		display();
		cout<<"Difference is "<<d;
	}
};

int main(){
	DiffNum obj;
	obj.input();
	obj.add();
	obj.diff();
	obj.print();
	return 0;
}
