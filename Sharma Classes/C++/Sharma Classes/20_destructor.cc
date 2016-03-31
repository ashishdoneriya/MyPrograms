#include<iostream>
using namespace std;
class Emp{
	int age;
	char name[20];
	float sal;
public:
	Emp();
	void show();
	~Emp();
};
Emp::Emp(){
	cout<<"Enter name, age and salary ";
	cin>>name>>age>>sal;
}
void Emp::show(){
	cout<<age<<" "<<name<<" "<<sal<<endl;
}
Emp::~Emp(){
	cout<<"Object destroyed "<<name<<endl;
}
int main(){
	Emp E,F;
	E.show();
	F.show();
	return 0;
}
