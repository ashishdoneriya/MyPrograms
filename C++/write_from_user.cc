//Program to write something into the file Entered by the user
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	char str[100];
	ofstream write;
	write.open("ashish.txt");
	printf("Enter the string :\n");
	cin.getline(str,100);
	int i=0;
	while(str[i]!='\0')				//loop to write the string into the file character by character
		write<<str[i++];				
	write.close();
	cout<<"File Saved";
	return 0;
}	
