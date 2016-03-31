#include<iostream>
using namespace std;
class Data{
	int a;
	int &p;
public:
	Data();
	void show();
};
Data::Data():p(a){
	a=10;
}
void Data::show(){
	cout<<a<<" "<<p;
}
int main(){
	Data D;
	D.show();
	return 0;
}
