#include<fstream>						//for file handling	
#include<string.h>						//for string manipulation
#include<cctype>
#include<math.h>
using namespace std;
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
