#include<iostream>
using namespace std;
class Student{
	int roll;
	char grade;
	float per;
public:
	Student(int = 0, char = ' ', float = 0.0);
	void get();
	void show();
};
Student::Student(int r, char g, float p){
	roll=r;
	grade=g;
	per=p;
}
void Student::get(){
	cout<<"Enter roll, grade & per : ";
	cin>>roll>>grade>>per;
}
void Student::show(){
	cout<<roll<<" "<<grade<<" "<<per<<endl;
}
int main(){
	Student S(10,'A',65.7);
	Student P;
	P.get();
	P.show();
	S.show();
	return 0;
}
