#include<iostream>
using namespace std;
class Emp{
	int age;
	char name[20];
	float sal;
public:
	void get(){
		cout<<"Enter name, age and salary ";
		cin>>this->name>>this->age>>this->sal;
	}
	void show(){
		cout<<this->age<<" "<<this->name<<" "<<this->sal<<endl;
	}
};
int main(){
	Emp E,F;
	E.get();
	F.get();
	E.show();
	F.show();
	return 0;
}
