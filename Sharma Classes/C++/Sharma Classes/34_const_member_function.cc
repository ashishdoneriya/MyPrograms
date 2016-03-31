#include<iostream>
using namespace std;
class Data{
	const int a;
	const int b;
	mutable int c;
public:
	Data(int i, int j):a(i),b(j){
	}
	void show() const{
		c=a+b;		//c is accessible because c is mutable
		cout<<a<<" "<<b<<" "<<c;
	}
};
int main(){
	Data D(5,10);
	D.show();
	return 0;
}
