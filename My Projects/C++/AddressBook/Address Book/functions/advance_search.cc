int AddressBook::check_number(char *str)
{
	int len=strlen(str);
	for(int i=0;i<len;i++)
	{
		if((((int)str[i])<47)||(((int)str[i])>57))
			return 0;
	}
	return 1;
}

void AddressBook::advance_search()
{
	ifstream obj;
	int i=0,flag,len,count;
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
	cin.getline(str,30);
	len=strlen(str);
	if(len==0)
	{
		cout<<"No record found";
		getchar();
		return;
	}
	if(check_number(str)==1&&len<=10)
	{
		for(i=0,count=0;i<total_record()-1;i++)
		{
			obj.read((char *)&T,size());
			if((long)(phone/(pow(10,10-len)))==get_phone(str))
			{
				show();
				count=count+1;
			}
		}
		if(count==0)
			cout<<"No record found"<<endl;
	}
	else
	{
		for(i=0,count=0;i<total_record()-1;i++)
		{
			obj.read((char *)&T,size());
			flag=strcomp(str,name);
			if(flag==1||flag==0)
			{
				show();
				count=count+1;
			}
		}
		if(count==0)
			cout<<"No record found"<<endl;
		else
			cout<<"\n"<<count<<" records found"<<endl;
	}
	//flush();
	getchar();
	obj.close();
}
