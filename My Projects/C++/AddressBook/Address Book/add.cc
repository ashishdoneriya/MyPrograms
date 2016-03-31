#include<fstream>
#include<iostream>
#include<getch.h>
#include<ctype.h>
//#include<process.h>
#include<iomanip>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
char ashish[50];
void welcome_screen();
void welcome_screen()
     {
	cout<<" 	****************** W E L C O M E  ***********************\n";
	cout<<"	\n	 T E L E P H O N E  M A N A G E M E N T  S O F T W A R E  \n";
	cout<<"	\n\n\n D O N E  B Y :  \n";
	cout<<"		\n\n\nA S H I S H  D O N E R I Y A\n\n";
	cout<<"\nPRESS ANY KEY TO CONTINUE...............";
	getchar();
	return;
     }
class directory
     {
       public:
	       int record;
	       long pn1;
	       char pn2[50];
	       int age;
	       char address1[50];
	       char address2[50];
	       char occupation[50];
	       char name[50];
	       char emailadd[50];
	       char internetadd[50];
	       void modification();
	       void addition();
	       void deleate();
	       int menu();
	       void search();
	       void view1();
	       void init();
	       void display();
	       void view();
	       char check(const char *);
	       int test();
	    }obj;
void directory::addition()  //ADDING  INFORMATION
    {
      ofstream fout;
      fout.open("ashish",ios::out|ios::app);
      init();
      fout.write((char*)&obj,sizeof(obj));
      fout.close();
    }
int directory::test()    //FIND NO. OF RECORDS
    {
      ifstream fin;
      fin.open("ashish");
      fin.seekg(0,ios::end);
      int n;
      n=fin.tellg()/sizeof(obj);
      cout<<" \n NUMBER OF RECORDS = "<<n ;
      return n ;
    }
void directory::search()  //SEARCHING FOR A PARTICULAR NUMBER
    {
      ifstream fin;
      fin.open("ashish");
      if(fin.fail())
	{
	  cout<<" \n FILE NOT FOUND ";
	  getch();
	  return;
	}
     system("clear");
       cout<<"************SEARCHING**************";
      cout<<" \n ENTER PHONE NUMBER TO BE SEARCHED : ";
      long pn;
      cin>>pn;
      int n;
      n=test();
      for(int i=0;i<n;i++)
	{
	  fin.read((char*)&obj,sizeof(obj));
	  if(pn==pn1)
	    {
	      view1();
	      return;
	    }
	}
      if(fin.eof())
	{
	  cout<<" \n RECORD NOT FOUND ";
	}
    }
void directory::init()  // ENTERING THE DETAILS
    {

      char ch;
      system("clear");
      cout<<"***********ADDITION************** ";
      cout<<" \n ENTER HOUSE PHONE NUMBER : ";
      cin>>pn1;
      cout<<" \n ENTER OFFICE PHONE NUMBER : ";
      cin>>pn2;
      // ch=cin.get();
      cin.get(ch);
      cout<<" \n ENTER NAME : ";
      cin.getline(name,20,'\n');
      cout<<" \n ENTER THE OCCUPATION : ";
      cin.getline(occupation,20,'\n');
      cout<<" \n ENTER HOUSE ADDRESS : ";
      cin.getline(address1,50,'\n');
      cout<<" \n ENTER OFFICE ADDRESS : ";
      cin.getline(address2,50,'\n');
      cout<<" \n ENTER EMAIL ADDRESS : ";
      cin.getline(emailadd,25,'\n');
      cout<<" \n ENTER INTERNET ADDRESS : ";
      cin.getline(internetadd,25,'\n');
    }

void directory::view1() //TO DISPLAY ALL THE RECORDS
    {
      cout<<"\n";
      cout<<" PHONE NUMBER1 : "<<obj.pn1<<"\n";
      cout<<" PHONE NUMBER2 : "<<obj.pn2<<"\n";
      cout<<" NAME : "<<obj.name<<"\n";
      cout<<" HOUSE ADDRESS : "<<obj.address1<<"\n";
      cout<<" OCCUPATION : "<<obj.occupation<<"\n";
      cout<<" OFFICE ADDRESS : "<<obj.address2<<"\n";
      cout<<" EMAIL ADDRESS : "<<obj.emailadd<<"\n";
      cout<<" INTERNET ADDRESS : "<<obj.internetadd<<"\n";
      getch();
    }
void directory::modification() //TO MODIFY ANY DATA IN  THE RECORD IF NECESSARY
   {
     system("clear");
       cout<<"************MODIFICATION**************";
     long pn;
     int n,i;
     ifstream fin;
     ofstream fout;
     fin.open("ashish");
     if(fin.fail())
       {
	 cout<<"\n FILE NOT FOUND !";
	 fout.close();
	 return;
       }
    fout.open("new");
    n=test();
    if(n==0)
      {
	cout<<"\n FILE IS EMPTY ! ";
	getch();
	return;
      }
   while(fin.good())
      {
	fin.read((char*)&obj,sizeof(obj));
	fout.write((char*)&obj,sizeof(obj));
      }
   fin.close();
   fout.close();
   fout.open("ashish",ios::trunc);
   fin.open("new");
   if(fin.fail())
     {
      cout<<"\n FILE NOT FOUND !";
      return;
     }
   char ch;
   cout<<"\n ENTER PHONE NUMBER :";
   cin>>pn;
   ch=cin.get();
//   cin.get(ch);
   for(i=0;i<n;i++)
	{
	   fin.read((char*)&obj,sizeof(obj));
	   char d;
	   if(pn==pn1)
	      {
		view1();
		d=check("HOUSE PHONE NUMBER ");
		if((d=='y') || (d=='Y'))
		  {
		    cout<<"\n ENTER NEW PHONE NUMBER :";
		    cin.ignore();
		    cin>>pn1;
		    ch=cin.get();
		  //  cin.get(ch);
		  }
		if(check("OFFICE PHONE NUMBER ")=='Y')
		  {
		    cout<<"\n ENTER NEW PHONE NUMBER :";
		    cin.ignore();
		    cin>>pn2;
		   ch=cin.get();
		 // cin.get(ch);
		  }
		if(check("NAME")=='y')
		  {
		    cout<<"\n ENTER NEW NAME : ";
		  cin.ignore();
		    cin.getline(name,20,'\n');
		  }
		if(check("HOME ADDRESS")=='y')
		  {
		    cout<<"\n ENTER NEW ADDRESS :";
		   cin.ignore();
		    cin.getline(address1,50,'\n');
		  }
		if(check("OFFICE ADDRESS")=='y')
		  {
		    cout<<"\n ENTER NEW ADDRESS :";
		    cin.ignore();
		    cin.getline(address2,50,'\n');
		  }
		if(check("EMAIL ADDRESS:")=='y')
		  {
		    cout<<"\n ENTER NEW MAIL ADDRESS :";
		  cin.ignore();
		    cin.getline(emailadd,25,'\n');
		  }
		if(check("INTERNET ADDRESS")=='y')
		  {
		    cout<<"\n ENTER NEW INTERNET ADDRESS :";
		  cin.ignore();
		    cin.getline(internetadd,25,'\n');
		  }
	      }
	   fout.write((char*)&obj,sizeof(obj));
	}
   fout.close();
   fin.close();
    }
char  directory::check(const char *s)
    {
       cout<<"\n MODIFY \t "<<s<<"\t"<<"Y/N :";
       char ch;
       cin>>ch;
      //cin.get(ch);
      if((ch=='y')||(ch=='Y'))
	return 'y';
       else
	return 'n';
    }
void  directory::deleate()
    {
       system("clear");
       cout<<"************DELETION**************";
       long pn;
       int n,i;
       ifstream fin;
       ofstream fout;
       fin.open("ashish");
       if(fin.fail())
	{
	  cout<<"\n FILE NOT FOUND ! ";
	  getch();
	  return;
	}
       fout.open("new");
       n=test();
       if(n==0)
	{
	  cout<<"\n FILE IS EMPTY ! ";
	  getch();
	  return;
	}
      for(i=0;i<n;i++)
	{
	  fin.read((char*)&obj,sizeof(obj));
	  fout.write((char*)&obj,sizeof(obj));
	}
      fin.close();
      fout.close();
      fout.open("meera",ios::trunc);
      fin.open("new");
      if(fin.fail())
	{
	  cout<<"\n FILE NOT FOUND ! ";
	  getch();
	  return;
	}
     cout<<"\n ENTER PHONE NUMBER :";
     cin>>pn;
     for(i=0;i<n;i++)
       {
	 fin.read((char*)&obj,sizeof(obj));
	 if(pn!=pn1)
	    fout.write((char*)&obj,sizeof(obj));
       }
     fout.close();
     fin.close();

    }
 void directory::view()
   {
     ifstream fin;
     int n,j;
     fin.open("ashish");
     if(fin.fail()||fin.bad())
       {
	  cout<<"\n FILE NOT FOUND ! ";
	  getch();
	  return;
       }
     int i=0;
     n=test();
     for(j=0;j<n;j++)
       {
		system("clear");
	 cout<<"\n RECORD "<<i+1<<"\n";
	 fin.read((char*)&obj,sizeof(obj));
	 cout<<"\n PHONE NUMBER1 :"<<obj.pn1<<"\n";
	 cout<<"\n PHONE NUMBER2 :"<<obj.pn2<<"\n";
	 cout<<"\n NAME :"<<obj.name<<"\n";
	 cout<<"\n HOUSE ADDRESS :"<<obj.address1<<"\n";
	 cout<<"\n OCCUPATION :"<<obj.occupation<<"\n";
	 cout<<"\n OFFICE ADDRESS :"<<obj.address2<<"\n";
	 cout<<"\n INTERNET ADDRESS :"<<obj.internetadd<<"\n";
	 cout<<"\n EMAIL ADDRESS : "<<obj.emailadd<<"\n";
	getch();
	 i+=1;
	 system("clear");
       }
      fin.close();
      getchar();

   }

int  directory::menu()
    {
       char ch;
       system("clear");
       cout<<" A:ADDITION\n";
       cout<<" D: DELETION \n";
       cout<<" M:MODIFICATION \n";
       cout<<" V:VIEW \n";
       cout<<" S:SEARCH \n";
       cout<<" E:EXIT \n";
       cout<<" Enter your choice : ";
       cin>>ch;

      switch(ch)
	   {
	     case 'a':
	     case 'A':
		addition();
		break;
	     case 'd' :
		 case 'D' :
		deleate();
		break;
	     case 'm':
	     case 'M':
		modification();
		break;
	     case 'v':
	     case 'V':
		view();
		break;
	     case 's':
	     case 'S':
		search();
		break;
		case 'e':
		case 'E':
			{
			cout<<"*******************G O O D  B Y E  A S H I S H*******************\n\n";
			getch();
			return -1;
		}
	}
		
	return 1; 
}
int main()
    {
	  system("clear");
      welcome_screen();
		for(int i=1;i==1;)
		{
			i=obj.menu();
		}
      return 0;
   }
