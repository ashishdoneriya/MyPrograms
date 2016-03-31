#include<iostream>
#include<cctype>
//#include<cstring>
using namespace std;
int main()
{
	cout<<islower('a')<<endl;
	cout<<isdigit('1')<<endl;
	char ch=tolower('B');
	cout<<ch;
	cout<<(char)toupper('A')<<endl;
	return 0;
}
#include<iostream>
#include<string.h>
#include<cctype>
using namespace std;
char** get_combiations(const char *str);
void lower_case(char *str);
void upper_case(char *str);
int main()
{
	int i,j;
	char **str;
	str=get_combiations("ashish");
	for(i=0;str[i][0]!='\0';i++);
		cout<<(&str[i]);
	return 0;
}

void lower_case(char *temp)
{
	int j;
	for(j=0;temp[j]!='\0';j++)
	{
		if(isupper(temp[j]))
			temp[j]=tolower(temp[j]);
	}
}

void upper_case(char *temp)
{
	int j;
	for(j=0;temp[j]!='\0';j++)
	{
		if(islower(temp[j]))
			temp[j]=toupper(temp[j]);
	}se
}

char** get_combintions(const char *str)
{
	char **temp[6][30];
	int i,j,k,nos=0,pos[4];
	pos[0]=0;
	for(i=0,j=1;i<strlen(str);i++)
	{
		if(str[i]==32)
			pos[j++]=i+1;
	}
	nos=j;
	for(i=0;i<4;i++)
	{
		strcpy(&temp[i],str);
		switch (i)
		{
		case 0:
			{
				if(isupper(temp[i][0]))
					temp[i][0]=(char)tolower(temp[i][0]);
				for(j=0;temp[i][j]!='\0';j++)
				{
					if(isupper(temp[i][j])
						temp[i][j]=islower(temp[i][j]);
				}
				break;
			}
		case 1:
			{
				if(isupper(temp[i][0]))
					temp[i][0]=toupper(temp[i][0]);
				for(j=0;temp[i][j]!='\0';j++)
				{
					if(isupper(temp[i][j]))
						temp[i][j]=islower(temp[i][j]);
				}
				break;
			}
		case 2:
			{
				if(isupper(temp[i][0]))
					temp[i][0]=toupper(temp[i][0]);
				for(j=0;temp[i][j]!='\0';j++)
				{
					for(k=0;pos[k]!='\0';k++)
					{
						temp[i][k]=toupper(temp[i][k]);
						lower_case(&temp[i][pos[++k]]);
					}
				}
				break;
			}
		case 3:
			{
				upper_case(temp[i]);
				break;
			}
		}
	}
	return (temp);
}
