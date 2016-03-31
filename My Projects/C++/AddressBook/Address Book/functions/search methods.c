void AddressBook::search()
{
	ifstream obj;
	int flag,ch,pos;
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
	//flush();
	cin.getline(str,30);
	if(strlen(str)==0)
		return;
	if(valid_num(str)==1)
	{
		long ph=convert(str);
		pos=search(ph);
		if(pos!=-1)
		{
			obj.seekg((pos-1)*size(),ios::beg);
			obj.read((char *)&T,size());
			show();
			getchar();
		}
		else
		{
			cout<<ph<<" is not found in Address Book"<<endl;
			char c[1];
			cin.getline(c,1);
			getchar();
			return;
		}
	}
	else
	{
		pos=search(str);
		if(pos!=-1)
		{
			obj.seekg((pos-1)*size(),ios::beg);
			obj.read((char *)&T,size());
			show();
		}
		else
		{	
			cout<<str<<" is not found in Address Book"<<endl;
			return;
		}
	}
	getchar();
	obj.close();
}






void AddressBook::search()
{
	ifstream obj;
	int ch,pos;
	obj.open("directory");
	if(!obj)
	{
		cout<<"File can't be opened";
		getchar();
		return;
	}
	system("clear");
	cout<<"1::Search by name"<<endl;
	cout<<"2::Search by Phone"<<endl;
	cout<<"Enter your choice : ";
	//flush();
	char str[40];
	cin.getline(str,40);
	if(strlen(str)>1)
	{
		cout<<"Wrong Choice";
		flush();
		getchar();
		return;
	}
	else
		ch=convert(str);
	if(ch==1)
	{
		char str[30];
		cout<<"Enter name : ";
		//flush();
		cin.getline(str,30);
		pos=search(str);
		if(pos!=-1)
		{
			obj.seekg((pos-1)*size(),ios::beg);
			obj.read((char *)&T,size());
			show();
		}
		else
		{	
			cout<<str<<" is not found in Address Book"<<endl;
			return;
		}
	}
	if(ch==2)
	{
		long ph;
		cout<<"Enter phone number : ";
		cin>>ph;
		pos=search(ph);
		if(pos!=-1)
		{
			obj.seekg((pos-1)*size(),ios::beg);
			obj.read((char *)&T,size());
			show();
			getchar();
		}
		else
		{
			cout<<ph<<" is not found in Address Book"<<endl;
			char c[1];
			cin.getline(c,1);
			getchar();
			return;
		}
	}
	getchar();
	obj.close();
}
