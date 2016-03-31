//Overloading postincrement operator using friend function
#include<iostream>
using namespace std;
class Counter{
	int count;
public:
	Counter(){
		count=0;
	}
	Counter(int c){
		count=c;
	}
	void show(){
		cout<<count<<endl;
	}
	friend void operator++(Counter &, int);
};
void operator ++(Counter &P, int){
	P.count++;
}

int main(){
	Counter C1(10);
	C1.show();
	C1++;
	C1.show();
	return 0;
}
