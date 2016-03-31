#include<iostream>
using namespace std;

class fact
{
	unsigned num;
	unsigned j;
public:
             fact();
	void get();
	void calculate();
	void show();
};

fact::fact()
{
	j=1;
}

void fact::get()
{
	cout<<"Enter a number : ";
	cin>>num;
}

void fact::calculate()
{
	for (int i=1;i<=num;i++)
		j=j*i;
}

void fact::show()
{
	cout<<"No. is "<<num<<endl;
	cout<<"Fatorial is "<<j<<endl;
}

int main()
{
	fact obj;
	obj.get();
	obj.calculate();
	obj.show();
	return 0;
}
