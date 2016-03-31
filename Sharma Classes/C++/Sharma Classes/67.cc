#include<iostream>
using namespace std;
class Shape{
protected:
	float area;
public:
	virtual void getParameter() = 0;
	virtual void calculateArea() = 0;
	void show(){
		cout<<"Area is "<<area<<endl;
	}
};

class Rectangle:public Shape{
public:
	int l,b;
	void getParameter(){
		cout<<"Enter length and breadth ";
		cin>>l>>b;
	}
	void calculateArea(){
		area = l * b;
	}
};
class Square:public Shape{
public:
	int s;
	void getParameter(){
		cout<<"Enter side of square ";
		cin>>s;
	}
	void calculateArea(){
		area = s * s;
	}
};
class Circle:public Shape{
public:
	const float pi;
	int r;
	Circle():pi(3.14){}
	void getParameter(){
		cout<<"Enter radius of circle ";
		cin>>r;
	}
	void calculateArea(){
		area=pi*r*r;
	}
};

void getAndCal(Shape &S){
	S.getParameter();
	S.calculateArea();
}
void show(Shape &S){
	S.show();
}

int main(){
	Rectangle r1;
	Circle r2;
	Square r3;
	Shape *s;
	getAndCal(r1);
	getAndCal(r2);
	getAndCal(r3);
	show(r1);
	show(r2);
	show(r3);
	return 0;
}
