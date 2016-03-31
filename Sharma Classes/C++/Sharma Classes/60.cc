#include<iostream>
using namespace std;
class Num{
protected:
	int a, b;
public:
	Num(int i, int j){
		a = i;
		b = j;
	}
	void show(){
		cout<<"Numbers are "<<a<<" and "<<b<<endl;
	}
};
class AddNum:public Num{
	int c;
public:
	AddNum( int x = 10, int y = 20 ) : Num( x, y ){
		c = a + b;
	}
	void show(){
		Num :: show();
		cout << "Sum is " << c << endl;
	}
};
int main(){
	AddNum obj;
	obj.show();
	
	AddNum obj1( 20, 30 );
	obj1.show();
}
