// Program to display a particular no. of record
#include<fstream>
#include<iostream>
#include "objects_in_binary_mode.cc"
using namespace std;
int main()
{
	ifstream read;
	Student T;
	int pos,x;
	read.open("ashish.dat");
	if (!read)
	{
		cout<<"File can't be opened";
		return 0;
	}
	cout<<"Enter the particualar no. of Record : ";
	cin>>pos;
	read.seekg(0,ios::end);
	x=(read.tellg())/sizeof(Student);
	if (pos>x||pos<1)
	{
		cout<<pos<<" record no. doesnot exit"<<endl;
		return 0;
	}
	else
	{
		read.seekg((pos-1)*sizeof(Student),ios::beg);
		read.read((char *)&T,sizeof(Student));
		T.show();
	}
	return 0;
}
