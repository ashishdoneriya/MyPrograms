//Overloading preincrement operator using friend function
#include<iostream>
using namespace std;
class Counter{
	int count;
public:
	Counter(){
		count=0;
	}
	Counter(int count){
		this->count=count;
	}
	void show(){
		cout<<count<<endl;
	}
	friend void operator++(Counter &);
};
void operator ++(Counter &P){
	++P.count;
}

int main(){
	Counter C1(10);
	C1.show();
	++C1;
	C1.show();
	return 0;
}
