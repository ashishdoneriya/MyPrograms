void AddressBook::modify()
{
	char str[30],ch,name1[30];
	int pos;
	long phone1;
	system("clear");
	flush();
	cout<<"Enter Name or Phone Number : ";
	cin.getline(str,30);
	if(valid_num(str)==1)
		pos=search(convert(str));
	else
		pos=search(str);
	if(pos==-1)
	{
		cout<<str<<" is not found in Address Book"<<endl;
		flush();
		getchar();
	}
	else
	{
		load_record(rcd);
		strcpy(name1,name);
		phone1=phone;
		cout<<name<<endl;
		getchar();
		cout<<"[Do you want to change [Y/n]] : ";
		cin>>ch;
		if (ch=='Y'||ch=='y')
		{
			cout<<"Enter new name : ";
			cin.getline(name1,30);
		}
		cout<<phone<<endl;
		cout<<"[Do you want to change [Y/n]] : ";
		cin>>ch;
		if (ch=='Y'||ch=='y')
		{
			cout<<"Enter new phone number : ";
			char temp[30];
			cin.getline(temp,30);
			if(check(temp)==1)
				phone1=phone;
			else
				cout<<"Invalid Phone no."<<endl;	
		}
		replace(pos,name1,phone1);
	}
}
