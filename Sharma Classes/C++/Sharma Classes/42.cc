//Overloading preincrement operator
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
	Counter operator ++(){
		++count;
		return (*this);
	}
};
int main(){
	Counter C1(10);
	Counter C2;
	C1.show();
	C2.show();
	C2=++C1;
	C1.show();
	C2.show();
	return 0;
}
