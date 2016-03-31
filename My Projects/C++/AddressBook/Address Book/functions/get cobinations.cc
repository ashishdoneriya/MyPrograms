char ** AddressBook::get_combinations(const char *str)
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
		switch (i)
		{
		case 0:
			{
				lower_case(temp[i]);
				break;
			}
		case 1:
			{
				if(islower(*temp[i]))
					temp[i][0]=toupper(*temp[i]);
				lower_case(&temp[i][1]);
				break;
			}
		case 2:
			{
				for(k=0;k<=j-1;k++)
				{
					temp[i][pos[k]]=toupper(temp[2][pos[k]]);
					lower_case(&temp[2][pos[k]+1]);
				}
				break;
			}
		case 3:
			{
				upper_case(&temp[i][0]);
				break;
			}
		}
	}
	return (temp);
}
