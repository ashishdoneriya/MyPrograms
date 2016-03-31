int AddressBook::load_record(int rcd)
{
	istream obj;
	obj.open("directory");
	if(!obj)
		return -1;
	int i=0;
	while(1)
	{
		if(obj.eof()!=0)
			break;
		obj.read((char *)&T,size());
		if(i++==rcd-1)
			return 1;
	}
	return -1;
}
