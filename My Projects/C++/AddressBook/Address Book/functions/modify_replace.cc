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
