#include<iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
int strcmp_adv(long ph1, long ph2,long len_ph2);
int strcmp_adv(const char *name1,const char *name2);
int strcomp(const char *str1, const char *str2);
int strcomp(const char *str1, const char *str2)
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
int main()
{
	cout<<(strcmp_adv("ashish doneriya","don"))<<endl;
	return 0;
}
int strcmp_adv(long ph1, long ph2,long len_ph2)
{
	int i;
	long temp1,temp2;
	for(i=1;i<10;i++)
	{
		temp1=ph1/pow(10,i-1);
		temp2=temp1%(long)pow(10,len_ph2);
		cout<<"ph1="<<ph1<<endl;
		cout<<"temp1="<<temp1<<endl;
		cout<<"temp2="<<temp2<<endl;
		if(temp2==ph2)
		{
			cout<<"phone no. found"<<endl;
			cout<<"temp2="<<temp2<<endl;
			return 1;
		}
	}
	return 0;
}

int strcmp_adv(const char *name1, const char *name2)
{
	int i,j,flag=0,pos[10];
	if(strcomp(name1,name2)==1)
		return 1;
	else
	{
		for(i=0,j++;i<strlen(name1);i++)
		{
			if(name1[i]==32)
				pos[j++]=i+1;
		}
		if(i==strlen(name1))
			return 0;
		else
		{
			flag=strcomp(&name1[i],name2);
			if(flag==0||flag==-1)
			{
				return 1;
			}
			else
				return 0;
		}
	}
}
