#include<iostream>
using namespace std;
class Num1{
protected:
	int a;
public:
	Num1( int i ){
		a = i;
	}
	void show(){
		cout << "Number is " << a << endl;
	}
};
class Num2:public Num1{
protected:
	int b;
public:
	Num2( int i, int j ) : Num1( i ){
		b = j;
	}
	void show(){
		Num1::show();
		cout << "Number is " << b << endl;
	}
};
class AddNum:public Num2{
	int c;
public:
	AddNum( int i, int j ) : Num2 ( i, j ){
		c = a + b;
	}
	void show(){
		Num2::show();
		cout << c;
	}
};
int main(){
	AddNum obj( 10, 20 );
	obj.show();
}
