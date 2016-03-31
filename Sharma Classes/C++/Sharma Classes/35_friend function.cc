#include<iostream>
using namespace std;
class Student
{
	int roll;
	char grade;
	float per;
public:
	void get();
	friend void show(Student);
};

void Student::get()
{
	cout<<"Enter your roll, grade and per ";
	cin>>roll>>grade>>per;
}
void show(Student S)
{
	cout<<S.roll<<" "<<S.grade<<" "<<S.per<<endl;
}
int main()
{
	Student P;
	P.get();
	show(P);
	return 0;
}
