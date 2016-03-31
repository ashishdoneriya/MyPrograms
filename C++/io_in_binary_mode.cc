//Read and write variable in file in binary mode
#include<fstream>
#include<iostream>
using namespace std;
int main()
{
	//Creating the object of fstream class
	fstream binary;
	binary.open("ashish.dat",ios::out|ios::trunc|ios::in);
	
	int a=100000,x;
	float b=20.123456,y;
	char c='A',z;
	
	//Writing the data into the file
	binary.write((char *)&a,sizeof(int));
	binary.write((char *)&b,sizeof(float));
	binary.write(&c,sizeof(char));
	
	//Move the file pointer to beginning of file
	binary.seekg(0);
	
	//Reading the data from the file
	binary.read((char *)&x,sizeof(int));
	binary.read((char *)&y,sizeof(float));
	binary.read(&z,sizeof(char));
	
	//Printing variables
	cout<<x<<endl;
	cout<<y<<endl;
	cout<<z<<endl;
	
	//closing the file
	binary.close();
	
	cout<<"File Saved";
	return 0;
}
