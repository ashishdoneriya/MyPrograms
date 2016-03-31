#include<iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
int strcomp(const char *str1, const char *str2);
int main()
{
	//char str1="ASHISH";
	//char str2="ASHISH DONERIYA";
	cout<<strcmp("lisT","lish0");
	return 0;
}

int AddressBook::strcomp(const char *str1, const char *str2)
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
int AddressBook::strcmp_adv(long ph1, long ph2,len_ph2)
{
	int i;
	long temp1,temp2;
	for(i=1,i<10,i++)
	{
		temp=ph1/pow(10,i);
		temp2=temp1/pow(10,len_ph2);
		if(temp2==ph2)
			return 1;
	}
	return 1;
}

int AddressBook::strcmp_adv(char *name1, char *name2)
{
	int i,j,flag=0;
	for(i=0;i<(strlen(name1)-strlen(name2));i++)
	{
		for(j=i;j<strlen(name2);j++)
		{
			if(name1[i]==name2[i])
			{	
				flag=1;
				continue;
			}
			else
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
			return 1;
		else
			continue;
	}
	return 0;
}
