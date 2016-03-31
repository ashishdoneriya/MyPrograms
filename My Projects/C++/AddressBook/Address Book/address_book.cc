// Address Book
#include<fstream>
#include<iostream>
#include<string.h>
using namespace std;
class AddressBook
{
private:
	char name[40];
	int number;
public:
	int add()
	{
		cout<<"Enter number:";
		cin>>number;
		cout<<"Enter name :";
		cin.ignore();
		cin.getline(name,30);
		if (strlen(name)==0)
			return -1;
		else
			return 1;
	}
	void show()
	{
		cout<<"Name = "<<name;
		cout<<"\t\tNumber = "<<number;
	}
	void addition(fstream &);
	void deletion(fstream &);
	void modification(fstream &);
	void searching(fstream &);
	void menu(fstream &);
	void display(fstream &);
	int search(char *, fstream &);
	int search(int , fstream &);
	
}T;

void AddressBook::menu(fstream &obj)
{
	int choice;
	do
	{
		cout<<"1::Addition"<<endl;
		cout<<"2::Deletion"<<endl;
		cout<<"3::Modification"<<endl;
		cout<<"4::Searchng"<<endl;
		cout<<"5::Display"<<endl;
		cout<<"6::Exit"<<endl;
		cout<<"Enter your choice : "<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				addition(obj);
				break;
			case 2:
				deletion(obj);
				break;
			case 3:
				modification(obj);
				break;
			case 4:
				searching(obj);
				break;
			case 5:
				display(obj);
				break;
			case 6:
				return;
			default:
				cout<<"Wrong Choice\n";
		}
	}while(choice!=6);
}

void AddressBook::addition(fstream &obj)
{
	int len;
	do
	{
		len=add();
		if (len==-1)
			break;
		else
		{
			obj.write((char *)&T,sizeof(AddressBook));
			
		}
	}while(len==1);
	cout<<"Student record written"<<endl;
}

void AddressBook::deletion(fstream &obj)
{
	
}

int AddressBook::search(char *n, fstream &obj)
{
	int flag,i;
	for(i=0;obj.eof()==0;i++)
	{
		obj.read((char *)this,sizeof(AddressBook));
		flag=strcmp(name,n);
		if (flag==0)
			return i;;
	}
			return -1;
}
int AddressBook::search(int n, fstream &obj)
{
	int flag,i;
	for(i=0;obj.eof()==0;i++)
	{
		obj.read((char *)this,sizeof(AddressBook));
		if (number==n)
			return i;
	}
	return -1;
}	
void AddressBook::searching(fstream &obj)
{
	cout<<"1::Search by name"<<endl;
	cout<<"2::Search by number"<<endl;
	cout<<"3.Search Particular Record"<<endl;
	cout<<"Enter your choice : ";
	int ch,rcd;
	char r;
	cin>>ch;
	char n[30];
	switch(ch)
	{
		case 1:
			
			cout<<"Enter the name : ";
			cin>>n;
			rcd=search(n,obj);
			break;
		case 2:
			cout<<"Enter phone number : ";
			int n;
			cin>>n;
			rcd=search(n,obj);
			break;
		case 3:
			cout<<"Enter the record number : ";
			cin>>rcd;
			break;
		default:
			cout<<"Wrong Choice"<<endl;
	}
	obj.seekg(0,ios::beg);
	int max_rcd=(obj.tellg())/sizeof(AddressBook);
	if(rcd>max_rcd||rcd<0)
	{
		cout<<"Record doesnot exist"<<endl;
		return;
	}
	else
	{
		obj.seekg(rcd-1,ios::beg);
		obj.read((char *)this,sizeof(AddressBook));
		show();
	}
}

void AddressBook::display(fstream &obj)
{
	
	while(1)
	{
		obj.read((char *)&T,sizeof(AddressBook));
		if (obj.eof()==1)
			break;
		show();
		cout<<"\n";
	}
}
void AddressBook::modification(fstream &obj)
{
	
}

int main()
{
	fstream obj;
	char ch;
	obj.open("AddressBook.txt",ios::out|ios::trunc|ios::binary|::ios::in);
	//obj.open("AddressBook.txt",ios::out|ios::ate|ios::in);
	T.menu(obj);
	obj.close();
	return 0;
}
