#include<iostream>
using namespace std;
class Emp{
public:
	void show(){
		cout<<"Address of object : "<<(long int)this;
	}
};
int main(){
	Emp E;
	E.show();
	return 0;
}
