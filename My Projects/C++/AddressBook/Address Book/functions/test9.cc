#include<iostream>						//for cin and cout
#include<fstream>						//for file handling	
#include<string.h>						//for string manipulation
#include<cctype>
#include<stdlib.h>						//for system("clear")
#include<math.h>						//for math functions
#include "fileutil.cc"
using namespace std;
void enter(char *directory);
int main()
{
	char filec[30];
	cout<<"Enter the file name : ";
	cin>>filec;
	enter(filec);
	return 0;
}
void enter(char *p)
{
	ofstream obj;
	obj.open(p);
	obj<<"ashish";
	obj.close();
}
