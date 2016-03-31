int AddressBook::replace(int rcd,char *name1,long phone1)
{
	ifstream in;
	ofstream out;
	in.open("directory");
	out.open("temp");
	if (!in||!out)
		return -1;
	while(in.good());
	{
		in.read((char *)&T,size());
		out.write((char *)&T,size());
	}
	in.close();
	out.close();
	in.open("temp");
	out.open("directory");
	if (!in||!out)
		return -1;
	int i=0;
	while(1)
	{
		if(in.eof()!=0)
			break;
		in.read((char *)&T,size());
		if(i++==rcd-1)
		{	
			strcpy(name,name1);
			phone=phone1;
		}
		out.write((char *)&T,size());			
	}
	in.close();
	out.close();
	return 1;
}	
