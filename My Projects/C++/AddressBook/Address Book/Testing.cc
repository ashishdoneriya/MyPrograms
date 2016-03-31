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
using namespace std;
class AddressBook;
class util
{
public:
	char * Upper_Lower(const char *str);
	char ** get_combinations(const char *str);
	void lower_case(char *str);
	void upper_case(char *str);	
	int check_number(char *str);
	long get_phone(const char *);		//It accepts the string as argument, covert it into the number and returns the no. ex. phone no.
	int strcomp(const char *str1, const char *str2);
	int valid_num(const char *string);	//It accepts the string as arguent & check whether the string as phone number is correct or not
	int strcmp_adv(long ph1, long ph2,int len_ph2);
	int strcmp_adv(char *name1, char *name2);
	
};
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
class AddressBook:public fileutil
{
public:
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
void util::lower_case(char *temp)
{
	for(int j=0;temp[j]!='\0';j++)
	{
		if(isupper(temp[j]))
			temp[j]=tolower(temp[j]);
	}
}
void util::upper_case(char *temp)
{
	for(int j=0;temp[j]!='\0';j++)
	{
		if(islower(temp[j]))
			temp[j]=toupper(temp[j]);
	}
}
char ** util::get_combinations(const char *str)
{
	char **temp;
	temp=(new char *[4]);
	int i,j,k,l,nos=0,pos[4];
	pos[0]=0;
	for(i=1,j=1;i<strlen(str);i++)
	{
		if(str[i]==32)
			pos[j++]=i+1;
	}
	pos[j]='\0';
	
	for(i=0;i<4;i++)
	{
		temp[i]=new char[strlen(str)];	
		strcpy(temp[i],str);
	}
	
	lower_case(temp[0]);
	
	
	if(islower(*temp[1]))
	temp[1][0]=toupper(*temp[1]);
	lower_case(&temp[1][1]);
	
	
	for(k=0;k<=j-1;k++)
	{
		temp[2][pos[k]]=toupper(temp[2][pos[k]]);
		lower_case(&temp[2][pos[k]+1]);
	}
	//strcpy(temp[2],util::Upper_Lower(temp[2]));
	
	
	upper_case(temp[3]);
	return (temp);
}
int util::check_number(char *str)
{
	int len=strlen(str);
	for(int i=0;i<len;i++)
	{
		if((((int)str[i])<47)||(((int)str[i])>57))
			return 0;
	}
	return 1;
}
int util::strcomp(const char *str1, const char *str2)
{
	for(int i=0;;i++)
	{
		if(str1[i]=='\0'&&str2[i]=='\0')
			return 0;
		if(str1[i]=='\0'&&str2[i]!='\0')
			return -1;
		if(str1[i]!='\0'&&str2[i]=='\0')
			return 1;
		if(str1[i]!=str2[i])
			return -1;
	}
}
int util::valid_num(const char *str)
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
long util::get_phone(const char *str)
{
	int len=strlen(str);
	long num=0;
	for(int i=0;i<len;i++)
	{
		num=num+((int)str[i]-48)*pow(10,len-i-1);
	}
	return num;
}
char * util::Upper_Lower(const char *str)
{
	int i,j,k,l,nos=0,pos[4];
	char *temp;
	temp=new char[strlen(str)];
	strcpy(temp,str);
	pos[0]=0;
	for(i=1,j=1;i<strlen(str);i++)
	{
		if(str[i]==32)
			pos[j++]=i+1;
	}
	pos[j]='\0';
	for(k=0;k<=j-1;k++)
	{
		temp[pos[k]]=toupper(temp[pos[k]]);
		lower_case(&temp[pos[k]+1]);
	}
	return temp;
}
int util::strcmp_adv(long ph1, long ph2,int len_ph2)
{
	int i;
	long temp1,temp2;
	for(i=1;i<10;i++)
	{
		temp1=ph1/pow(10,i-1);
		temp2=temp1%(long)pow(10,len_ph2);
		if(temp2==ph2)
			return 1;
	}
	return 0;
}
int util::strcmp_adv(char *name1, char *name2)
{
	int i,j,flag=0;
	if(strcomp(name1,name2)==1)
		return 1;
	else
	{
		for(i=0,j=0;i<strlen(name1);i++)
		{
			if(name1[i]==32)
			{
				flag=strcomp(&name1[i+1],name2);
				if(flag==0||flag==1)
					return 1;
			}
		}
		return 0;
	}
}

void fileutil::init()
{
	ofstream obj;
	obj.open("directory");
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
	in.open("directory");
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
	obj.open("directory");
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
	obj.open("directory");
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
	obj.open("directory");
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
	obj.open("directory");
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
	out.open("directory");
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
	out.open("directory");
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
	out.open("directory");
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
void AddressBook::extreme_search()
{
	ifstream obj;
	int i=0,j=0,flag,len,count;
	char str[30],**str1;
	obj.open("directory");
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
	obj.open("directory");
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
	out.open("directory");
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
	obj.open("directory");
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
	obj.open("directory");
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
					obj.open("directory");
					obj.close();
					cout<<"Formatted";
					//flush();
					getchar();
					break;
			}
			case 'e':
				extreme_search();
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
	//T.welcome_screen();
	T.init();
	T.menu_screen();
	return 0;
}
