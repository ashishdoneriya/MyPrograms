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
		cout << "Number is " << a<<endl;
	}
};
class Num2{
protected:
	int b;
public:
	Num2( int j ){
		b = j;
	}
	void show(){
		cout << "Number is " << b<<endl;
	}
};
class AddNum : public Num1, public Num2{
	int c;
public:
	AddNum( int i, int j ) : Num1( i ), Num2( j ){
		c = a + b;
	}
	void show(){
		Num1 :: show();
		Num2 :: show();
		cout << "Sum is " << c;
	}
};

int main(){
	AddNum obj( 10, 20 );
	obj.show();
}
