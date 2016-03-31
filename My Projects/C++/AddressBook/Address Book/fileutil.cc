//class AddressBook;
//class util;
#include<iostream>	
#include<fstream>						//for file handling	
#include<string.h>						//for string manipulation
#include<cctype>
#include<stdlib.h>						//for system("clear")
#include<math.h>
#include "util.cc"

using namespace std;
char directory[30];
class fileutil:public util
{
public:
	long phone;
	char name[30];
	int load_record(int record_number);	//This function accepts the record number as argument and loads the  data of the record into the object		
	int copy_into_temp();				//It copies all the record of file named as 'directory' in 'temp' and returns total records if error the 0
	int total_record();					//It returns the total no. of records in file
	int get_record_pos(char *name);	//It accepts the name and returns the position of the record of file. If record not found then returns -1
	int get_record_pos(long phone);	//It accepts the phone no. and returns the position of the record of file. If record not found then returns -1
	int del(const char *name);			//It accepts the name as argument and delete that record from the file
	int del(long phone);				//It accepts the phone no. as argument and delete that record from the file
	int replace(int pos,char *name1,long phone1);
	//This function accets 3 arguments- first is position of the record in the file of which we want to replace the data
	//second is the name and 3rd is phone.
	//It replace the previous values of 'name' and 'phone' in file with 'name1' and phone1 respectively
	//if unable to replace then return -1
	
	void init();						//It formats the file and put some records into it
		inline int size()					//It returns the size of the object of class AddressBook
	{
		return sizeof(fileutil);
	}
};	
void fileutil::init()
{
	ofstream obj;
	obj.open(directory);
	strcpy(name,"Ashish Doneriya");
	phone=9301124836;
	obj.write((char *)this,size());
	strcpy(name,"My Old Phone");
	phone=7898330674;
	obj.write((char *)this,size());
	strcpy(name,"My Home Phone");
	phone=9301376952;
	obj.write((char *)this,size());
	obj.close();
}
int fileutil::copy_into_temp()
{
	ifstream in;
	ofstream out;
	int rcd=total_record();
	in.open(directory);
	out.open("temp");
	if (!in||!out)
	{
		return 0;
	}
	for(int i=0;i<rcd;i++)
	{
		in.read((char *)this,size());
		out.write((char *)this,size());
	}
	in.close();
	out.close();
	return rcd;
}
int fileutil::total_record()
{
	int i=0;
	ifstream obj;
	obj.open(directory);
	if(!obj)
	{
		cout<<"File can't be opened";
		getchar();
		return 0;
	}
	for(i=0;obj.eof()==0;i++)
		obj.read((char *)this,size());
	return i;
}
int fileutil::get_record_pos(char *n)
{
	ifstream obj;
	int pos;
	obj.open(directory);
	if(!obj)
	{
		cout<<"File can't be opened";
		getchar();
		return 0;
	}
	while(!obj.eof())
	{
		obj.read((char *)this,size());
		if(!strcmp(n,name))
		{
			pos=(obj.tellg())/size();
			obj.close();
			return pos;
		}
	}
	obj.close();
	return 0;
}
int fileutil::get_record_pos(long ph)
{
	ifstream obj;
	int pos;
	obj.open(directory);
	if(!obj)
	{
		cout<<"File can't be opened";
		getchar();
		return 0;
	}
	while(!obj.eof())
	{
		obj.read((char *)this,size());
		if(phone==ph)
		{
			pos=(obj.tellg())/size();
			obj.close();
			return pos;
		}
	}
	obj.close();
	return 0;
}
int fileutil::load_record(int rcd)
{
	ifstream obj;
	obj.open(directory);
	if(!obj)
		return 0;
	int i=0;
	while(1)
	{
		if(obj.eof()!=0)
			break;
		obj.read((char *)this,size());
		if(i++==rcd-1)
			return 1;
	}
	return 0;
}
int fileutil::replace(int rcd,char *name1,long phone1)
{
	ifstream in;
	ofstream out;
	int total_rcd=copy_into_temp();
	if(total_rcd==0)
		return 0;
	in.open("temp");
	out.open(directory);
	if (!in||!out)
		return 0;
	int i=0;
	for(int i=0;i<total_rcd-1;i++)
	{
		in.read((char*)this,size());
		if(i==rcd-1)
		{	
			strcpy(name,name1);
			phone=phone1;
		}
		out.write((char*)this,size());		
	}
	in.close();
	out.close();
	return 1;
}
int fileutil::del(long p)
{
	ifstream in;
	ofstream out;
	int rcd=copy_into_temp();
	if(	rcd==-1)
		return 0;
	in.open("temp");
	out.open(directory);
	if (!in||!out)
		return 0;
	for(int i=0;i<rcd-1;i++)
	{
		in.read((char *)this,size());
		if (phone!=p)
			out.write((char *)this,size());
	}
	return 1;
}
int fileutil::del(const char *str)
{
	ifstream in;
	ofstream out;
	int rcd=copy_into_temp();
	if(	rcd==-1)
		return 0;
	in.open("temp");
	out.open(directory);
	if (!in||!out)
	{
		return 0;
	}
	for(int i=0;i<rcd-1;i++)
	{
		in.read((char *)this,size());
		if (strcmp(str,name)!=0)
			out.write((char *)this,size());
	}
	return 1;
}
