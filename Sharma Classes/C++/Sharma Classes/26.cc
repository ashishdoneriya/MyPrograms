#include<iostream>
#include<string.h>
using namespace std;
class Emp{
	int age;
	int sal;
	char name[30];
	static long int totalSal;
	static int count;
public:
	Emp(int a, const char *n, int s){
		age=a;
		strcpy(name,n);
		sal=s;
		totalSal=totalSal+sal;
		count++;
	}
	void show(){
		cout<<age<<" "<<name<<" "<<sal<<endl;
	}
	static void showTotalEmp(){
		cout<<"Total Employee currently working is "<<count<<endl;
	}
	static void showAvgSal(){
		cout<<"Average salary of company is "<<(totalSal/count)<<endl;
	}
	~Emp(){
		totalSal=totalSal-sal;
		count--;
	}
};
int Emp::count;
long int Emp::totalSal;

int main(){
	Emp E1(20,"Ashish",2000), E2(19,"Amit",1000), E3(21,"Harish",1200);
	Emp::showAvgSal();
	{
		Emp X(21,"Sameer",1500), Y(22,"Rahul",1900);
		X.show();
		Y.show();
		Emp::showTotalEmp();
		Emp::showAvgSal();
	}
	Emp::showTotalEmp();
	Emp::showAvgSal();
	return 0;
}
