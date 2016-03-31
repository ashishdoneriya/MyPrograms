//Constructor overloading using copy constructor

#include<iostream>
using namespace std;

class Box{
	int l,b,h;
public:
	Box();
	Box(int);
	Box(int, int, int);
	Box(Box &);
	void show();
};
Box::Box(){
	cout<<"Enter l, b and h : ";
	cin>>l>>b>>h;
}
Box::Box(int s){
	l=b=h=s;
}
Box::Box(int i, int j, int k){
	l=i;
	b=j;
	h=k;
}
Box::Box(Box &p){
	l=p.l;
	b=p.b;
	h=p.h;
}
void Box::show(){
	cout<<"l = "<<l<<"\tb = "<<b<<"\th = "<<h<<endl;
}

int main(){
	Box B1;
	Box B2(10);
	Box B3(5,7,11);
	Box B4(B1);			//or Box B4=B1
	B1.show();
	B2.show();
	B3.show();
	B4.show();
	return 0;
}
