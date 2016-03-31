//Creating Constructor in a class

#include<iostream>
#include<string.h>
using namespace std;

class Emp{
	int age;
	char name[20];
	float sal;
public:
	Emp(int, const char *, float);
	void show();
};

Emp::Emp(int a, const char *n, float s){
	age=a;
	strcpy(name,n);
	sal=s;
}

void Emp :: show(){
	cout<<"Age = "<<age<<"\nName = "<<name<<"\nSalary = "<<sal<<endl;
}

int main(){
	Emp E(20,"Ashish",15000);
	Emp F(25,"Ravi",20000);
	E.show();
	F.show();
}
