// Program for reading and writing objects in binary mode
#include<fstream>
#include<iostream>
#include<string.h>
using namespace std;
class Student
{
private:
	char name[30];
	int age;
public:
	int get()
	{
		cout<<"Enter name :";
		cin.getline(name,30);
		if (strlen(name)==0)
			return -1;
		cout<<"Enter age:";
		cin>>age;
		return 1;
	}
	void show()
	{
		cout<<"Name = "<<name;
		cout<<"\t\tAge = "<<age;
	}
};

int main()
{
	Student T;
	fstream obj;
	char ch;
	int len;
	obj.open("Temp.dat",ios::out|ios::trunc|ios::in);
	//obj.open("Temp.dat",ios::out|ios::app|ios::in);
	do
	{
		len=T.get();
		if (len==-1)
			break;
		else
		{
			obj.write((char *)&T,sizeof(Student));
			cin.ignore();
		}
	}while(len==1);
	cout<<"Student record written"<<endl;
	obj.seekg(0);
	while(1)
	{
		obj.read((char *)&T,sizeof(Student));
		if (obj.eof()!=0)
			break;
		T.show();
		cout<<"\n";
	}
	obj.close();
	return 0;
}
