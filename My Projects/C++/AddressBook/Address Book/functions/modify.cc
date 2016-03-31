void AddressBook::modify()
{
	char str[30],ch,temp;
	int pos;
	system("clear");
	/*obj.open("directory",ios::in|ios::app);
	if(!obj)
	{
		cout<<"File can't be opened";
		getchar();
		return;
	}*/
	flush();
	cout<<"Enter name : ";
	cin.getline(str,30);
	pos=search(str);
	if(pos==-1)
	{
		cout<<str<<" is not found in Address Book"<<endl;
		flush();
		getchar();
	}
	else
	{
		obj.seekg((pos-1)*size(),ios::beg);
		obj.read((char *)&T,size());
		//obj.seekg((-1*size()),ios::cur);
		cout<<name<<endl;
		getchar();
		cout<<"[Do you want to change [Y/n]] : ";
		cin>>ch;
		if (ch=='Y'||ch=='y')
		{
			cout<<"Enter new name : ";
			cin>>temp;
			cin.getline(name,30);
		}
		cout<<phone<<endl;
		cout<<"[Do you want to change [Y/n]] : ";
		cin>>ch;
		if (ch=='Y'||ch=='y')
		{
			cout<<"Enter new phone number : ";
			cin>>phone;
		}
		//obj.write((char *)&T,size());
		replace(pos);
	}
	obj.close();
}
