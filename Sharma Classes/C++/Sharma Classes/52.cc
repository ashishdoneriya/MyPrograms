#include<iostream>
#include<malloc.h>
using namespace std;
class Emp{
	int age;
	char name[20];
	float sal;
public:
	void get(){
		cout<<"Enter age, name and salary ";
		cin>>age>>name>>sal;
	}
	void show(){
		cout<<age<<" "<<name<<" "<<sal<<endl;
	}
};

int main(){
	Emp &p = *( new Emp );
	p.get();
	p.show();
	delete &p;
}s
