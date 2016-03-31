//                                    ::HARE KRISHNA::
// 										ADDRESS BOOK
//NAME    :: ASHISH DONERIYA
//COLLEGE ::MANIT
//INSPIRE BHOPAL
#include<iostream>						//for cin and cout
#include<fstream>						//for file handling	
#include<string.h>						//for string manipulation
#include<cctype>
#include<stdlib.h>						//for system("clear")
#include<math.h>						//for math functions
#include "fileutil.cc"
using namespace std;
class AddressBook;
class AddressBook:public fileutil
{
public:
	void createfile();
	void flush();						//It clears the buffer	
	void get();							//It accepts the name and phone no. from user and save it in object of class AddressBook
	void show();						//It shows the data inside 'name' and 'phone' variables of object of class AddressBook
	void advance_search();
	void extreme_search();	
	void addition();					//It is used for adding the record in the file
	void display();						//It displays all the record of the file
	void modify();						//It is used to modify an existing record in the file
	void search();						//It is used to search and display a particular record of file
	void deletion();					//It is used to delete a particular record form the file
	void menu_screen();					//It displays the list of tasks that can be done on a file or it displays the options for address book
	void welcome_screen();				//It displays the welcome screen
};
void AddressBook::createfile()
{
	cout<<"Enter the file name : ";
	cin.getline(directory,30);
	fstream obj;
	obj.open(directory,ios::app);
	obj.close();
}
void AddressBook::extreme_search()
{
	ifstream obj;
	int i=0,j=0,flag,len,count;
	char str[30],**str1;
	obj.open(directory);
	if(!obj)
	{
		cout<<"File can't be opened";
		getchar();
		return;
	}
	system("clear");
	cout<<"Enter name or phone no. : ";
	cin.getline(str,30);
	len=strlen(str);
	if(len==0)
		return;
	if(check_number(str)==1&&len<=10)
	{
		for(i=0,count=0;i<total_record()-1;i++)
		{
			obj.read((char *)this,size());
			if(strcmp_adv(phone,get_phone(str),len)==1)
			{
				show();
				count=count+1;
			}
		}
		if(count==0)
			cout<<"No record found"<<endl;
	}
	else
	{
		for(i=0,count=0;i<total_record()-1;i++)
		{
			obj.read((char *)this,size());
			str1=get_combinations(str);
			for(j=0;j<4;j++)
			{
				if(strcmp_adv(name,str1[j])==1)
				{
					show();
					count=count+1;
				}
			}
		}
		if(count==0)
			cout<<"No record found"<<endl;
		else
			cout<<"\n"<<count<<" records found"<<endl;
	}
	//flush();
	getchar();
	obj.close();
}
void AddressBook::advance_search()
{
	ifstream obj;
	int i=0,flag,len,count;
	char str[30];
	obj.open(directory);
	if(!obj)
	{
		cout<<"File can't be opened";
		getchar();
		return;
	}
	system("clear");
	cout<<"Enter name or phone no. : ";
	cin.getline(str,30);
	len=strlen(str);
	if(len==0)
	{
		cout<<"No record found";
		getchar();
		return;
	}
	if(check_number(str)==1&&len<=10)
	{
		for(i=0,count=0;i<total_record()-1;i++)
		{
			obj.read((char *)this,size());
			if((long)(phone/(pow(10,10-len)))==get_phone(str))
			{
				show();
				count=count+1;
			}
		}
		if(count==0)
			cout<<"No record found"<<endl;
	}
	else
	{
		for(i=0,count=0;i<total_record()-1;i++)
		{
			obj.read((char *)this,size());
			flag=strcomp(str,name);
			if(flag==1||flag==0)
			{
				show();
				count=count+1;
			}
		}
		if(count==0)
			cout<<"No record found"<<endl;
		else
			cout<<"\n"<<count<<" records found"<<endl;
	}
	//flush();
	getchar();
	obj.close();
}
void AddressBook::flush()
{
	scanf ( "%*[^\n]" );
	scanf ( "%*c" );
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
		phone=get_phone(temp);
	cin.get(ch);
	cout<<"ENTER NAME : ";
    cin.getline(name,20);
    strcpy(name,Upper_Lower(name));
}
void AddressBook::show()
{
	cout<<"Name  :: "<<name<<endl;
	cout<<"Phone :: "<<phone<<"\n"<<endl;
}
void AddressBook::addition()
{
	ifstream in;
	ofstream out;
	int rcd=copy_into_temp();
	int i=0;
	long phone1,phone2;
	char name1[30],name2[30];
	if(	rcd==-1)
		return;
	get();
	if(!phone)
	{
		cout<<"Invalid number"<<endl;
		flush();
		getchar();
		return;
	}
	strcpy(name1,name);
	phone1=phone;
	
	in.open("temp");
	out.open(directory);
	if (!in||!out)
	{
		cout<<"Can't add the record"<<endl;
		getchar();
		return;
	}
	int flag=1;
	//while(1)
	for(i=0;i<rcd-1;i++)
	{
		in.read((char*)this,size());
		//if(in.eof()!=0)
			//break;
		if((strcmp(name1,name)<(-1))&&flag==1)
		{	
			strcpy(name2,name);
			phone2=phone;
			strcpy(name,name1);
			phone=phone1;
			out.write((char *)this,size());
			strcpy(name,name2);
			phone=phone2;
			flag=0;
		}
		out.write((char*)this,size());			
	}
	if(flag==1)
	{
		strcpy(name,name1);
		phone=phone1;
		out.write((char *)this,size());
		flag=0;
	}
	
	in.close();
	out.close();
}
void AddressBook::display()
{
	int i=1;
	ifstream obj;
	system("clear");
	obj.open(directory);
	if(!obj)
	{
		cout<<"File can't be opened";
		getchar();
		return;
	}
	while(1)
	{
		obj.read((char *)this,size());
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
	obj.close();
}
void AddressBook::search()
{
	ifstream obj;
	int flag,ch,pos;
	char str[30];
	obj.open(directory);
	if(!obj)
	{
		cout<<"File can't be opened";
		getchar();
		return;
	}
	system("clear");
	cout<<"Enter name or phone no. : ";
	cin.getline(str,30);
	if(strlen(str)==0)
		return;
	if(valid_num(str)==1)
	{
		long ph=get_phone(str);
		pos=get_record_pos(ph);
		if(pos!=0)
		{
			obj.seekg((pos-1)*size(),ios::beg);
			obj.read((char *)this,size());
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
		pos=get_record_pos(str);
		if(pos!=-1)
		{
			obj.seekg((pos-1)*size(),ios::beg);
			obj.read((char *)this,size());
			show();
		}
		else
		{	
			cout<<str<<" is not found in Address Book"<<endl;
			return;
		}
	}
	getchar();
	obj.close();
}
void AddressBook::modify()
{
	char str[30],ch,name1[30];
	int pos;
	long phone1;
	system("clear");
	cout<<"Enter Name or Phone Number : ";
	cin.getline(str,30);
	if(valid_num(str)==1)
		pos=get_record_pos(get_phone(str));
	else
		pos=get_record_pos(str);
	if(pos==0)
	{
		cout<<str<<" is not found in Address Book"<<endl;
	}
	else
	{
		load_record(pos);
		strcpy(name1,name);
		phone1=phone;
		cout<<name<<endl;
		getchar();
		char temp[30];
		cout<<"Enter new name : ";
		cin.getline(temp,30);
		if(strlen(temp)!=0)
			strcpy(name1,temp);
		cout<<phone<<endl;
		cout<<"Enter new phone number : ";
		cin.getline(temp,30);
		if(strlen(temp)!=0)
		{
			if(valid_num(temp)==1)
				phone1=get_phone(temp);
			else
				cout<<"Invalid Phone no."<<endl;	
		}
		replace(pos,name1,phone1);
	}
	getchar();
}
void AddressBook::deletion()
{	
	char str[30];
	int flag;
	cout<<"Enter name or number to be deleted : ";
	cin.getline(str,30);
	if(strlen(str)==0)
		return;
	if(valid_num(str)==1)
		flag=del(get_phone(str));
	else
		flag=del(str);
	if(flag==0)
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
		cout<<"		          :: ADDRESS BOOK::"<<endl;
		cout<<"A::Add"<<endl;
		cout<<"V::View"<<endl;
		cout<<"S::Search"<<endl;
		cout<<"s::Advance Search"<<endl;
		cout<<"e::Extreme Search"<<endl;
		cout<<"M::Modify"<<endl;
		cout<<"D::Delete"<<endl;
		cout<<"F::Format"<<endl;
		cout<<"G::Goto Another file"<<endl;
		cout<<"E::Exit"<<endl;
		cout<<"Enter your choice : "<<endl;
		char str[30];
		cin.getline(str,30);
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
			case 's':
				advance_search();
				break;
			case 'S':
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
					obj.open(directory);
					obj.close();
					cout<<"Formatted";
					//flush();
					getchar();
					break;
			}
			case 'e':
				extreme_search();
				break;
			case 'G':
			case 'g':
				createfile();
				break;
			case 'E':
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
	cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	cout<<"		           ADDRESS BOOK"<<endl;
	cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	cout<<"\n\n\n\nPress any key to continue................";
	getchar();
}
int main()
{
	AddressBook T;
	T.createfile();
	//T.welcome_screen();
	//T.init();
	T.menu_screen();
	return 0;
}
