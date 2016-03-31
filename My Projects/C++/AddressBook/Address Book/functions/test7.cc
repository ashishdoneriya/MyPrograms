#include<iostream>
#include<string.h>
#include<cctype>
#include<stdlib.h>
using namespace std;
char ** get_combinations(const char *str);
char * lower_case(const char *str);
char * upper_case(const char *str);
char * Upper_Lower(const char *str);
int main()
{
	int i,j;
	char **str;
	
	str=get_combinations("ashish doneriya 1fd Dfdfdfdf");
	for(i=0;i<4;i++)
		cout<<str[i]<<endl;
	return 0;
}
char * Upper_Lower(const char *str)
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
	cout<<"in="<<(temp+(pos[k]+1))<<endl;
	for(k=0;k<=j-1;k++)
	{
		temp[pos[k]]=toupper(temp[pos[k]]);
		//strcpy(&(*temp+pos[k]+1),(lower_case((*temp+pos[k]+1))));
		strcpy(temp+(pos[k]+1),lower_case(temp+(pos[k]+1)));
	}
	return temp;
}

char * lower_case(const char *str)
{
	char *temp=new char[strlen(str)];
	for(int j=0;temp[j]!='\0';j++)
	{
		if(isupper(temp[j]))
			temp[j]=tolower(temp[j]);
	}
	return temp;
}


char * upper_case(const char *str)
{
	char *temp=new char[strlen(str)];
	for(int j=0;temp[j]!='\0';j++)
	{
		if(islower(temp[j]))
			temp[j]=toupper(temp[j]);
	}
	return temp;
}

char ** get_combinations(const char *str)
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
	strcpy(temp[0],lower_case(temp[0]));
	
	if(islower(*temp[1]))
		*(temp+1)=lower_case((*(temp+1)+1));
	
	for(k=0;k<=j-1;k++)
	{
	cout<<"IN LOOP"<<endl;
		temp[2][pos[k]]=toupper(temp[2][pos[k]]);
		strcpy((*(temp+2)+pos[k]+1),lower_case((*(temp+2)+pos[k]+1)));
	}
	//strcpy(temp[2],Upper_Lower(temp[2]));
	strcpy(temp[3],upper_case(temp[3]));
	return (temp);
}
