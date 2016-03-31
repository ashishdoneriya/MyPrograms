void AddressBook::addition()
{
	ofstream obj;
	obj.open("directory",ios::app|ios::binary);
	if(!obj)
	{
		cout<<"File can't be opened";
		getchar();
		return;
	}
	get();
	if(!phone==0)	
		obj.write((char *)&T,size());
	else
		cout<<"Invalid number"<<endl;
	flush();
	getchar();
	obj.close();
}
