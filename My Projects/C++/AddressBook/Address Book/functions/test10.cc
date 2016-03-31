#include<iostream>
#include<string.h>
using namespace std;
int strcomp(const char *str1, const char *str2);
char ** get_combinations(const char *str);
void upper_case(char *temp);
void lower_case(char *temp);
void lower_case(char *temp)
{
	for(int j=0;temp[j]!='\0';j++)
	{
		if(isupper(temp[j]))
			temp[j]=tolower(temp[j]);
	}
}
void upper_case(char *temp)
{
	for(int j=0;temp[j]!='\0';j++)
	{
		if(islower(temp[j]))
			temp[j]=toupper(temp[j]);
	}
}
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
		if((toupper(str2[i])!=toupper(str1[i]))&&(toupper(str2[i])!=tolower(str1[i]))&&(tolower(str2[i])!=toupper(str1[i]))&&(tolower(str2[i])!=tolower(str1[i])))
			return -1;
	}
}
int main()
{
	int flag=strcomp("ashish","ashish doneriya");
	//int flag1=strcomp("ashish doneriya","ashish");
	cout<<flag<<endl;
	//cout<<flag1;
	return 0;
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
