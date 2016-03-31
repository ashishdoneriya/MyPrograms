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
	void operator ++(){
		++count;
	}
};
int main(){
	Counter C1(10);
	C1.show();
	++C1;
	C1.show();
	return 0;
}
