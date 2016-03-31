//Creating Parameterised functions within a class

#include<iostream>
#include<string.h>
using namespace std;

class Emp{
	int age;
	char name[20];
	float sal;
public:
	void set(int, const char *, float);
	void show();
};

void Emp::set(int a, const char *n, float s){
	age=a;
	strcpy(name,n);
	sal=s;
}

void Emp :: show(){
	cout<<"Age = "<<age<<"\nName = "<<name<<"\nSalary = "<<sal<<endl;
}

int main(){
	Emp E,F;
	E.set(20,"Ashish",15000);
	F.set(25,"Ravi",20000);
	E.show();
	F.show();
}
