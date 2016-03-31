int AddressBook::copy_into_temp()
{
	ifstream in;
	ofstream out;
	int rcd=total_record();
	in.open("directory");
	out.open("temp");
	if (!in||!out)
	{
		return 0;
	}
	for(int i=0;i<rcd;i++)
	{
		in.read((char *)&T,size());
		out.write((char *)&T,size());
	}
	in.close();
	out.close();
	return rcd;
}
