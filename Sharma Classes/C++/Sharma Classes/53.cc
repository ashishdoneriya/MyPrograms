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
	int i, n;
	Emp *p;
	cout<<"Enter size : ";
	cin>>n;
	p=new Emp[n];
	if(p==0){
		cout<<"Memory Insufficient";
		return 0;
	}
	for(i=0;i<n;i++)
		(p+i)->get();
	for(i=0;i<n;i++)
		(p+i)->show();
	delete []p;
}
