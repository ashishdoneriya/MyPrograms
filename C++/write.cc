/*write.cc*/
#include<fstream>
using namespace std;
int main()
{
	ofstream write;				//making the object of ofstream class which has functions to write
	write.open("ashish.txt");	//opening the file
	write<<"Hi Mr. Ashish Doneriya";	//writing the text into the file
	write.close();						//closing the file
	return 0;
}
