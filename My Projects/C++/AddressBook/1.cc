//Testing
#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
class AddressBook
{
	long phone;
	char name[30];
public:
	int valid_num(const char *);
	void flush();
	void init();
	void get();
	void show();
	int size();
	long convert(const char *);
	int total_record();
	int search(char *);
	int search(long);
	void addition();
	int del(const char *);
	int del(long);
	void deletion();
	int replace(int);
	void modify();
	void search();
	void display();
	void menu_screen();
	void welcome_screen();
}T;

void AddressBook::init()
{
	fstream obj;
	obj.open("directory",ios::in|ios::out);
	strcpy(name,"a");
	phone=9301124836;
	obj.write((char *)&T,size());
	strcpy(name,"s");
	phone=9301376952;
	obj.write((char *)&T,size());
	strcpy(name,"d");
	phone=7898330674;
	obj.write((char *)&T,size());
	obj.close();
}
void AddressBook::flush()
{
	scanf ( "%*[^\n]" );
	scanf ( "%*c" );
}

int AddressBook::valid_num(const char *str)
{
	int len=strlen(str);
	if(len!=10)
		return 0;
	for(int i=0;i<len;i++)
	{
		if((((int)str[i])<47)||(((int)str[i])>57))
			return 0;
	}
	return 1;
}


void AddressBook::get()
{
	char ch,temp[10];
	cout<<"Phone Number : ";
	cin>>temp;
	if(!valid_num(temp))
	{
		phone=0;
		return;
	}
	else
		phone=convert(temp);
	cin.get(ch);
	cout<<"ENTER NAME : ";
    cin.getline(name,20);
}

void AddressBook::show()
{
	cout<<"Name  :: "<<name<<endl;
	cout<<"Phone :: "<<phone<<"\n"<<endl;
}

long AddressBook::convert(const char *str)
{
	int len=strlen(str);
	long num=0;
	for(int i=0;i<len;i++)
	{
		num=num+((int)str[i]-48)*pow(10,len-i-1);
	}
	return num;
}

int AddressBook::size()
{
	return sizeof(AddressBook);
}

int AddressBook::total_record()
{
	int i=0;
	ifstream obj;
	obj.open("directory");
	if(!obj)
	{
		cout<<"File can't be opened";
		getchar();
		return -1;
	}
	for(i=0;obj.eof()==0;i++)
		obj.read((char *)&T,size());
	return i;
}

void AddressBook::addition()
{
	ofstream obj;
	obj.open("directory",ios::app|ios::binary);
	//obj.open("directory",ios::out);
	if(!obj)
	{
		cout<<"File can't be opened";
		getchar();
		return;
	}
	get();
	if(!phone==0)	
		obj.write((char *)&T,size());
	else
		cout<<"Invalid number"<<endl;
	flush();
	getchar();
	obj.close();
}

void AddressBook::display()
{
	int i=1;
	ifstream obj;
	system("clear");
	obj.open("directory");
	if(!obj)
	{
		cout<<"File can't be opened";
		getchar();
		return;
	}
	while(1)
	{
		obj.read((char *)&T,size());
		if(obj.eof()!=0)
			break;
		show();
		if((i++)%5==0)
		{
			getchar();
			system("clear");
		}
	}
	flush();
	//getchar();
	obj.close();
}

int AddressBook::search(char *n)
{
	ifstream obj;
	int pos;
	obj.open("directory");
	if(!obj)
	{
		cout<<"File can't be opened";
		getchar();
		return -1;
	}
	while(!obj.eof())
	{
		obj.read((char *)&T,size());
		if(!strcmp(n,name))
		{
			pos=(obj.tellg())/size();
			obj.close();
			return pos;
		}
	}
	obj.close();
	return -1;
}

int AddressBook::search(long ph)
{
	ifstream obj;
	int pos;
	obj.open("directory");
	if(!obj)
	{
		cout<<"File can't be opened";
		getchar();
		return -1;
	}
	while(!obj.eof())
	{
		obj.read((char *)&T,size());
		if(phone==ph)
		{
			pos=(obj.tellg())/size();
			obj.close();
			return pos;
		}
	}
	obj.close();
	return -1;
}

void AddressBook::search()
{
	ifstream obj;
	int flag,ch,pos;
	char str[30];
	obj.open("directory");
	if(!obj)
	{
		cout<<"File can't be opened";
		getchar();
		return;
	}
	system("clear");
	cout<<"Enter name or phone no. : ";
	//flush();
	cin.getline(str,30);
	if(strlen(str)==0)
		return;
	if(valid_num(str)==1)
	{
		long ph=convert(str);
		pos=search(ph);
		if(pos!=-1)
		{
			obj.seekg((pos-1)*size(),ios::beg);
			obj.read((char *)&T,size());
			show();
			getchar();
		}
		else
		{
			cout<<ph<<" is not found in Address Book"<<endl;
			char c[1];
			cin.getline(c,1);
			getchar();
			return;
		}
	}
	else
	{
		pos=search(str);
		if(pos!=-1)
		{
			obj.seekg((pos-1)*size(),ios::beg);
			obj.read((char *)&T,size());
			show();
		}
		else
		{	
			cout<<str<<" is not found in Address Book"<<endl;
			getchar();
			return;
		}
	}
	getchar();
	obj.close();
}

int AddressBook::replace(int rcd)
{
	ifstream in;
	ofstream out;
	in.open("directory");
	out.open("temp");
	if (!in||!out)
	{
		return -1;
	}
	in.seekg((rcd-1)*size(),ios::beg);
	in.read((char *)&T,size());
	long ph=phone;
	char n[30];
	strcpy(n,name);
	for(int i=0;i<total_record();i++)
	{
		in.read((char *)&T,size());
		out.write((char *)&T,size());
	}
	in.close();
	out.close();
	in.open("temp");
	out.open("directory");
	if (!in||!out)
	{
		return -1;
	}
	for(int i=0;i<total_record()-1;i++)
	{
	
		in.read((char *)&T,size());
		if(i==rcd-1)
		{	
			strcpy(name,n);
			phone=ph;
		}
		out.write((char *)&T,size());			
	}
	return 1;
}	

void AddressBook::modify()
{
	fstream obj;
	char str[30],ch,temp;
	int pos;
	system("clear");
	obj.open("directory",ios::in|ios::app);
	if(!obj)
	{
		cout<<"File can't be opened";
		getchar();
		return;
	}
	flush();
	cout<<"Enter name : ";
	cin.getline(str,30);
	pos=search(str);
	if(pos==-1)
	{
		cout<<str<<" is not found in Address Book"<<endl;
		flush();
		getchar();
	}
	else
	{
		obj.seekg((pos-1)*size(),ios::beg);
		obj.read((char *)&T,size());
		//obj.seekg((-1*size()),ios::cur);
		cout<<name<<endl;
		getchar();
		cout<<"[Do you want to change [Y/n]] : ";
		cin>>ch;
		if (ch=='Y'||ch=='y')
		{
			cout<<"Enter new name : ";
			cin>>temp;
			cin.getline(name,30);
		}
		cout<<phone<<endl;
		cout<<"[Do you want to change [Y/n]] : ";
		cin>>ch;
		if (ch=='Y'||ch=='y')
		{
			cout<<"Enter new phone number : ";
			cin>>phone;
		}
		//obj.write((char *)&T,size());
		replace(pos);
	}
	obj.close();
}

int AddressBook::del(long p)
{
	ifstream in;
	ofstream out;
	int rcd=total_record();
	in.open("directory");
	out.open("temp");
	if (!in||!out)
	{
		return -1;
	}
	for(int i=0;i<rcd;i++)
	{
		in.read((char *)&T,size());
		out.write((char *)&T,size());
	}
	in.close();
	out.close();
	in.open("temp");
	out.open("directory");
	if (!in||!out)
		return -1;
	for(int i=0;i<rcd-1;i++)
	{
		in.read((char *)&T,size());
		if (phone!=p)
			out.write((char *)&T,size());
	}
	return 1;
}

int AddressBook::del(const char *str)
{
	ifstream in;
	ofstream out;
	int rcd=total_record();
	in.open("directory");
	out.open("temp");
	if (!in||!out)
	{
		return -1;
	}
	for(int i=0;i<rcd;i++)
	{
		in.read((char *)&T,size());
		out.write((char *)&T,size());
	}
	in.close();
	out.close();
	in.open("temp");
	out.open("directory");
	if (!in||!out)
	{
		return -1;
	}
	for(int i=0;i<rcd-1;i++)
	{
		in.read((char *)&T,size());
		if (strcmp(str,name)!=0)
			out.write((char *)&T,size());
	}
	return 1;
}

void AddressBook::deletion()
{	
	char str[30];
	int flag;
	cout<<"Enter name or number to be deleted : ";
	//flush();
	cin.getline(str,30);
	if(strlen(str)==0)
		return;
	if(valid_num(str)==1)
		flag=del(convert(str));
	else
		flag=del(str);
	if(flag==-1)
		cout<<str<<" Can't be deleted"<<endl;
	//else
		//cout<<str<<" deleted"<<endl;
	flush();
}
void AddressBook::menu_screen()
{
	char ch;
	do
	{
		system("clear");
		cout<<"A::Add"<<endl;
		cout<<"V::View"<<endl;
		cout<<"S::Search"<<endl;
		cout<<"M::Modify"<<endl;
		cout<<"D::Delete"<<endl;
		cout<<"F::Format"<<endl;
		cout<<"E::Exit"<<endl;
		cout<<"Enter your choice : "<<endl;
		//flush();
		char str[40];
		cin.getline(str,40);
	    if(strlen(str)>1)
			continue;
		else
		ch=str[0];
		switch (ch)
		{
			case 'A':
			case 'a':
				addition();
				break;
			case 'V':
			case 'v':
				display();
				break;
			case 'S':
			case 's':
				search();
				break;
			case 'M':
			case 'm':
				modify();
				break;
			case 'D':
			case 'd':
				deletion();
				break;
			case 'F':
			case 'f':
			{
					ofstream obj;
					obj.open("directory");
					obj.close();
					break;
			}
			case 'E':
			case 'e':
				return;
			default:
			{
						cout<<"Wrong Choice"<<endl;
			}
		}
	}while(ch!='E'||ch!='e');
}

void AddressBook::welcome_screen()
{
	system("clear");
	cout<<"+++++++++++++q++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	cout<<"		           ADDRESS BOOK"<<endl;
	cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	cout<<"\n\n\n\nPress any key to continue................";
	getchar();
}

int main()
{
	//T.welcome_screen();
	T.init();
	T.menu_screen();
	return 0;
}
