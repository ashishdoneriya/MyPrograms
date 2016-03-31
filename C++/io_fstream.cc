// Use of fstream class for reading and writing of a file
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	fstream file;
	char line[100],bk=8;
	file.open("ashish.txt",ios::out|ios::app|ios::in);
	cout<<"TYPE YOUR TEXT HERE\n\n";
	cin.getline(line,99);
	int i=0;
	while(line[i]!='\0')
		file<<line[i++];
	cout<<"File Saved\n";
	file.seekg(0);
	char ch;
	while(file.get(ch))
		cout<<ch;
	file.close();
	return 0;
}
