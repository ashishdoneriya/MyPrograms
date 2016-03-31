//Factorial
#include<iostream>
using namespace std;

class Factorial{
	int num;
	int fact;
public:
	Factorial();
	void get();
	void calculate();
	void show();
};
Factorial::Factorial(){
	fact=1;
}
void Factorial::get(){
	cout<<"Enter number :: ";
	cin>>num;
}
void Factorial::calculate(){
	for(int i=1;i<=num;i++)
		fact=fact*i;
}
void Factorial::show(){
	cout<<"Number is "<<num<<endl;
	cout<<"Factorial is "<<fact<<endl;
}

int main(){
	Factorial f;
	f.get();
	f.calculate();
	f.show();
	return 0;
}
