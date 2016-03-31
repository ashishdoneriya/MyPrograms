#include<iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
long convert(const char *);
int check_num(char *);
int main()
{
	char ch[10];
	cout<<"Enter num : ";
	cin>>ch;
	if (check_num(ch)==0)
	{
		cout<<"invalid";
	}
	//long num=convert(ch);
	//cout<<num;
	return 0;
}

long convert(const char *str)
{
	int len=strlen(str);
	long num=0;
	for(int i=0;i<len;i++)
	{
		num=num+((int)str[i]-48)*pow(10,len-i-1);
	}
	return num;
}

int valid_num(char *str)
{
	for(int i=0;i<strlen(str);i++)
	{
		if((((int)str[i])<47)||(((int)str[i])>57))
			return 0;
	}
	return 1;
}


/*void AddressBook::search()
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
			return;
		}
	}
	getchar();
	obj.close();
}



*/


