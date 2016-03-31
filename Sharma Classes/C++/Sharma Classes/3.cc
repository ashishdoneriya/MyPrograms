#include<iostream>
using namespace std;

class Student{
	int roll;
	char grade;
	float per;
public:
	void get();
	void show();
};

void Student::get(){
	cout<<"Enter roll, grade and per :: ";
	cin>>roll>>grade>>per;
}

void Student::show(){
	cout<<"Roll = \t\t"<<roll<<"\nGrade = \t"<<grade<<"\nPercentage = \t"<<per<<endl;
}

int main(){
	Student S;
	S.get();
	S.show();
	return 0;
}
