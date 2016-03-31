#include<iostream>
#include<malloc.h>
#include<string.h>
using namespace std;
class Emp{
	int age;
	char *p;
	float sal;
public:
	Emp();
	Emp(int, const char *, float);
	void show();
	~Emp();
};
Emp::Emp(){
	cout<<"Enter age and salary ";
	cin>>age>>sal;
	char temp[40];
	cout<<"Enter name ";
	cin.ignore();
	cin.getline(temp,40);
	int x=(int)strlen(temp);
	p=new char[x+1];
	strcpy(p,temp);
}
Emp::Emp(int a, const char *q, float s){
	age = a;
	p=new char[strlen(q)+1];
	strcpy(p,q);
	sal=s;
}
void Emp::show(){
	cout<<age<<" "<<p<<" "<<sal<<endl;
}
Emp::~Emp(){
	delete []p;
}
int main(){
	Emp *p1, *p2;
	p1=new Emp;
	p2=new Emp(26,"RAVI",15000);
	p1->show();
	p2->show();
	delete p1;
	delete p2;
	return 0;
}
