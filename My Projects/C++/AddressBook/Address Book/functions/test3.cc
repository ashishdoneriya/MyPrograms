#include<iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
int strcmp_adv(long ph1, long ph2,long len_ph2);
int strcmp_adv(const char *name1,const char *name2);
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
	int i,j,flag=0;
	for(i=0;i<(strlen(name1)-strlen(name2));i++)
	{
		cout<<"i="<<i<<endl;
		for(j=i;j<strlen(name2);j++)
		{
			cout<<"j="<<j<<endl;
			if(name1[i]==name2[i])
			{	
				cout<<name1[i]<<endl;
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

