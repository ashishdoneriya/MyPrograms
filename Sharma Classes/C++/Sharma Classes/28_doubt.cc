#include<iostream>
using namespace std;
class Student{
	int roll;
	char grade;
	float per;
public:
	void get(){
		cout<<"Enter roll, grade and per ";
		cin>>roll>>grade>>per;
	}
	void show();
};
inline void Student::show(){
	cout<<roll<<" "<<grade<<" "<<per<<endl;
}
int main(){
	Student E[5];
	int i;
	for(i=0;i<5;i++)
		E[i].get();
	for(i=0;i<5;i++)
		E[i].show();
	return 0;
}
