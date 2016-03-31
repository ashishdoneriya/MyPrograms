#include<iostream>
using namespace std;
class Shape{
protected:
	int l, b;
public:
	void get(){
		cout << "Enter length and breadth ";
		cin >> l >> b;
	}
	void show(){
		cout << "l = " << l << "\tb = " << b << endl;
	}
};
class PrintData{
public:
	void print( int x ){
		cout << x << endl;
	}
};
class Rectangle:public Shape, public PrintData{
	int area;
public:
	void calculateArea(){
		area = l * b;
		print( area );
	}
};
int main(){
	Rectangle R;
	R.get();
	R.show();
	R.calculateArea();
}
