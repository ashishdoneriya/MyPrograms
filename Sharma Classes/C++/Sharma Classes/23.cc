#include<iostream>
#include<string.h>
using namespace std;
class Emp{
	int age;
	char name[30];
	static int count;
public:
	Emp(int a, const char *n){
		age=a;
		strcpy(name,n);
		count++;
	}
	void show(){
		cout<<name<<" "<<age<<endl;
	}
	void showTotalEmp(){
		cout<<"Total Employee currently working is "<<count<<endl;
	}
	~Emp(){
		count--;
	}
};
int Emp::count;

int main(){
	Emp E1(20,"Ashish"), E2(19,"Amit");
	E1.show();
	E2.show();
	E1.showTotalEmp();
	return 0;
}
