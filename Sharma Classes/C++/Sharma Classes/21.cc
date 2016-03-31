#include<iostream>
#include<string.h>
#include<malloc.h>
using namespace std;
class Emp{
	int age;
	char *name;
	float sal;
public:
	Emp();
	void show();
	~Emp();
};
Emp::Emp(){
	cout<<"Enter age and salary ";
	cin>>age>>sal;
	
	char temp[20];
	cout<<"Enter your name : ";
	cin.ignore();
	cin.getline(temp,20);
	int x=(int)strlen(temp);
	name=(char *)malloc((x+1)*sizeof(char));
	strcpy(name,temp);
}
void Emp::show(){
	cout<<age<<" "<<name<<" "<<sal<<endl;
}
Emp::~Emp(){
	free(name);
	cout<<"Object destroyed"<<endl;
}
int main(){
	Emp E;
	E.show();
	return 0;
}
