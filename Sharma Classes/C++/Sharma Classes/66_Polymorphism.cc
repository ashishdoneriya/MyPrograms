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

void getParameter(Shape &S){
	S.getParameter();
}
void calculateArea(Shape &S){
	S.calculateArea();
}

int main(){
	Rectangle r1;
	Circle r2;
	Square r3;
	Shape *s;
	getParameter(r1);
	getParameter(r2);
	getParameter(r3);
	calculateArea(r1);
	calculateArea(r2);
	calculateArea(r3);
	s=&r1;
	s->show();
	s=&r2;
	s->show();
	s=&r3;
	s->show();
	return 0;
}
