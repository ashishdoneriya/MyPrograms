void AddressBook::addition()
{
	ifstream in;
	ofstream out;
	int rcd=copy_into_temp();
	int i=0;
	long phone1;phone2;
	char name1[30];,name2[30];
	if(	rcd==-1)
		return;
	get();
	if(!phone)
	{
		cout<<"Invalid number"<<endl;
		getchar();
		return;
	}
	strcpy(name1,name);
	phone1=phone;
	
	in.open("temp");
	out.open("directory");
	if (!in||!out)
		return 0;
	while(1)
	{
		in.read((char*)&T,size());
		if(in.eof()!=0)
			break;
		if(strcmp(name1,name)<(-1))
		{	
			strcpy(name2,name);
			phone2=phone;
			strcpy(name,name1);
			phone=phone1;
			out.write((char *)&T,size());
			strcpy(name,name2);
			phone=phone2;
		}
		out.write((char*)&T,size());			
	}
	in.close();
	out.close();
	return 1;
}	
