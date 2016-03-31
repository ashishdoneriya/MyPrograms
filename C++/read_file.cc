//Program to read the file
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	char ch;
	ifstream read;
	read.open("ashish.txt");
	//while (read.get(ch))
		//cout<<ch;
	while (1)
	{
	//	ch=read.get();		//read.get() is used to read the character from the file
		if(read.eof()!=0)
			break;
		cout<<*(&((read.get(ch))));
	}
	read.close();
	return 0;
}
