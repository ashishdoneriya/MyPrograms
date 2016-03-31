#include<iostream>
#include<string.h>
#include<cctype>
using namespace std;
char** get_combiations(char *str);
void lower_case(char *str);
void upper_case(char *str);
int main()
{
	int i,j;
	char *str;
	str=get_combiations("ashish");
	for(i=0;i<4;i++);
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
	}
}

char** get_combintions( char *str)
{
	char temp[4][30];
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
		temp[i]
		
		strcpy(&(temp[i][0]),str);
		switch (i)
		{
		case 0:
			{
				lower_case(temp[i]);
				break;
			}
		case 1:
			{
				if(islower(temp[i][0]))
					temp[i][0]=toupper(temp[i][0]);
				lower_case(&temp[i][1]);
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
						lower_case((char *)&temp[i][pos[++k]]);
					}
				}
				break;
			}
		case 3:
			{
				upper_case((char *)&temp[i][0]);
				break;
			}
		}
	}
	return (temp);
}
