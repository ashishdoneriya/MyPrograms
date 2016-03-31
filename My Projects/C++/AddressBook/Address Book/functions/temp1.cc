/*
int AddressBook::replace(int rcd)
{
	ifstream in;
	ofstream out;
	in.open("directory");
	out.open("temp");
	if (!in||!out)
	{
		return -1;
	}
	in.seekg((rcd-1)*size(),ios::beg);
	in.read((char *)&T,size());
	long ph=phone;
	char n[30];
	strcpy(n,name);
	for(int i=0;i<total_record();i++)
	{
		in.read((char *)&T,size());
		out.write((char *)&T,size());
	}
	in.close();
	out.close();
	in.open("temp");
	out.open("directory");
	if (!in||!out)
	{
		return -1;
	}
	for(int i=0;i<total_record()-1;i++)
	{
	
		in.read((char *)&T,size());
		if(i==rcd-1)
		{	
			strcpy(name,n);
			phone=ph;
		}
		out.write((char *)&T,size());			
	}
	return 1;
}	

void AddressBook::modify()
{
//	fstream obj;
	char str[30],ch,temp;
	int pos;
	system("clear");
	/*obj.open("directory",ios::in|ios::app);
	if(!obj)
	{
		cout<<"File can't be opened";
		getchar();
		return;
	}
	flush();
	cout<<"Enter Name or Phone Number: ";
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
*/
