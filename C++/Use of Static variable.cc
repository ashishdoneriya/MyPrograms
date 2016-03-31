
#include<iostream>
#include<string.h>
using namespace std;

class Emp
{
	int age;
	char name[30];
	static int count;
public:
	Emp(int,char*);
	void show();
	static void show_total_emp();
	~Emp();
};
int Emp::count;

Emp::Emp(int a, char *p)
{
	age=a;
	strcpy(name,p);
	count++;
}
void Emp::show()
{
	cout<<age<<" "<<name<<endl;
}

void Emp::show_total_emp()
{
	cout<<count<<endl;
}

Emp::~Emp()
{
	--count;
}

int main()
{
	int c;
	Emp E1(20,"ashish"),E2(12,"ashish");
	E1.show();
	E2.show();
	cout<<"Total no. of employees = ";
	Emp::show_total_emp();
	return 0;
}
	
