// Address Book
#include<fstream.h>
#include<string.h>
#include<conio.h>
class AddressBook
{
	long int phone;
	char name[30];
public:
	void get();
	void show();
	int size();
	int total_record();
	int search(char *);
	int search(long int);
	void display_particular();
	void display_all();
	void addition();
	void deletion();
	void modification();
	void display();
	void menu_screen();
	void welcome_screen();
}T;

void AddressBook::get()
{
	clrscr();
	cout<<"Phone Number : ";
	cin>>phone;
	cout<<"Name : ";
	char a;
	cin>>a;
	cin.getline(name,30);

}

void AddressBook::show()
{
	cout<<"Name  :: "<<name<<endl;
	cout<<"Phone :: "<<phone<<"\n"<<endl;
}

int AddressBook::size()
{
	return sizeof(AddressBook);
}

int AddressBook::total_record()
{
	int i=0;
	ifstream obj;
	obj.open("directory");
	for(i=0;obj.eof()==0;i++)
		obj.read((char *)&T,size());
	return i;
}

int AddressBook::search(char *n)
{
	ifstream obj;
	int pos;
	obj.open("directory");
	while(!obj.eof())
	{
		obj.read((char *)&T,size());
		if(!strcmp(n,name))
		{
			pos=(obj.tellg())/size();
			obj.close();
			return pos;
		}
	}
	obj.close();
	return -1;
}

int AddressBook::search(long int ph)
{
	ifstream obj;
	int pos;
	obj.open("directory");
	while(!obj.eof())
	{
		obj.read((char *)&T,size());
		if(phone==ph)
		{
			pos=(obj.tellg())/size();
			obj.close();
			return pos;
		}
	}
	obj.close();
	return -1;
}

void AddressBook::display_particular()
{
	ifstream obj;
	int ch;
	long int pos;
	obj.open("directory");
	clrscr();
	cout<<"1::Display by name"<<endl;
	cout<<"2::Display by Phone"<<endl;
	cout<<"Enter your choice : ";
	cin>>ch;
	if(ch==1)
	{
		char str[30];
		cout<<"Enter name : ";
		cin.ignore();
		cin.getline(str,30);
		pos=search(str);
		if(pos!=-1)
		{
			obj.seekg((pos-1)*size(),ios::beg);
			obj.read((char *)&T,size());
			show();
		}
		else
			cout<<str<<" is not found in Address Book"<<endl;
	}
	if(ch==2)
	{
		int ph;
		cout<<"Enter phone number : ";
		cin>>ph;
		pos=search(ph);
		if(pos!=-1)
		{
			obj.seekg((pos-1)*size(),ios::beg);
			obj.read((char *)&T,size());
			show();
		}
		else
			cout<<ph<<" is not found in Address Book"<<endl;
	}
	getche();
	obj.close();
}

void AddressBook::display_all()
{
	ifstream obj;
	obj.open("directory");
	clrscr();
	while(!obj.eof())
	{
		obj.read((char *)&T,size());
		show();
	}
	getch();
	obj.close();
}

void AddressBook::addition()
{
	fstream obj;
	char ch;
	//obj.open("directory",ios::in|ios::app|ios::binary);
	obj.open("directory",ios::in|ios::out|ios::binary);
	do
	{
		clrscr();
		get();
		obj.write((char *)&T,size());
		cout<<"Do you want to add more record [y/n] : ";
		cin>>ch;
	}while(ch=='Y'||ch=='y');
	obj.close();
}

void AddressBook::deletion()
{
	ifstream in;
	ofstream out;
	in.open("directory");
	out.open("temp");
	clrscr();
	for(int i=0;i<total_record();i++)
	{
		in.read((char *)&T,size());
		out.write((char *)&T,size());
	}
	in.close();
	out.close();

	in.open("temp");
	out.open("directory");

	char str[30];
	cout<<"Enter name to be deleted : ";
	cin.ignore();
	cin.getline(str,30);
	while(!in.eof())
	{
		in.read((char *)&T,size());
		if (strcmp(str,name)!=0)
			out.write((char *)&T,size());
	}
}

void AddressBook::modification()
{
	fstream obj;
	char str[30],ch;
	int pos;
	clrscr();
	obj.open("directory",ios::out|ios::ate|ios::binary);
	cout<<"Enter name : ";
	cin.ignore();
	cin.getline(str,30);
	pos=search(str);
	if(pos==-1)
		cout<<str<<" is not found in Address Book"<<endl;
	else
	{
		obj.seekg((pos-1)*size(),ios::beg);
		obj.read((char *)&T,size());
		obj.seekg(-1*size(),ios::cur);
		cout<<name<<endl;
		cout<<"[Do you want to change [Y/n]] : ";
		ch=getch();
		if (ch=='Y'||ch=='y')
		{
			cout<<"Enter new name : ";
			cin.ignore();
			cin.getline(name,30);
		}
		cout<<phone<<endl;
		cout<<"[Do you want to change [Y/n]] : ";
		ch=getch();
		if (ch=='Y'||ch=='y')
		{
			cout<<"Enter new phone number : ";
			cin>>phone;
		}
		obj.write((char *)&T,size());
	}
	obj.close();
}

void AddressBook::display()
{
	int ch;
	clrscr();
	cout<<"1.Display all records"<<endl;
	cout<<"2.Display particular record"<<endl;
	cin>>ch;
	if (ch==1)
		display_all();
	else if (ch==2)
		display_particular();
	else
		cout<<"Wrong choice"<<endl;
}

void AddressBook::menu_screen()
{
	int ch;
	do
	{
		clrscr();
		cout<<"1::Addition"<<endl;
		cout<<"2::Deletion"<<endl;
		cout<<"3::Modification"<<endl;
		cout<<"4::Display"<<endl;
		cout<<"5::Exit"<<endl;
		cout<<"Enter your choice : "<<endl;
		cin>>ch;
		switch (ch)
		{
			case 1:
				addition();
				break;
			case 2:
				deletion();
				break;
			case 3:
				modification();
				break;
			case 4:
				display();
				break;
			case 5:
				return;
			default:
				cout<<"Wrong Choice"<<endl;
		}
		getch();
	}while(ch!=5);
}

void AddressBook::welcome_screen()
{
	clrscr();
	cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	cout<<"			ADDRESS BOOK"<<endl;
	cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	cout<<"\n\n\n\nPress any key to continue................";
	getche();
}

int main()
{
	T.welcome_screen();
	T.menu_screen();
	return 0;
}




