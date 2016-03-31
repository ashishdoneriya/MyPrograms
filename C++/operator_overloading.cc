#include<stdio.h>
#include<iostream>
using namespace std;
class counter
{
	int count;
	public:
				counter()
				{
						count=0;
				}
				counter(int c)
				{
					count=c;
				}
				void show()
				{
					cout<<count<<endl;
				}
				void operator ++();
};

void counter::operator ++()
{
	++count;
}

int main()
{
	counter c1(10);
	c1.show();
	++c1;
	c1.show();
	return 0;
}
