#include<iostream>
using namespace std;

class volume
{
	int l,b,h;
public:
	volume();
	volume(int);
	volume(int, int, int);
	volume(volume &p);
	void show();
};

volume::volume()
{
	cout<<"Enter l, b & h"<<endl;
	cin>>l>>b>>h;
}

volume::volume(int s)
{
	l=b=h=s;
}

volume::volume(int i, int j, int k)
{
	l=i;
	b=j;
	h=k;
}

volume::volume(volume &p)
{
	l=p.l;
	b=p.b;
	h=p.h;
}

void volume::show()
{
	cout<<"\n"<<l<<" "<<b<<" "<<h<<endl;
}

int main()
{
	volume v1;
	volume v2(10);
	volume v3(5,6,7);
	volume v4(v3);
	volume v5=v1;
	v1.show();
	v2.show();
	v3.show();
	v4.show();
	v5.show();
	return 0;
}
