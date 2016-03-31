void directory::modification() //TO MODIFY ANY DATA IN  THE RECORD IF NECESSARY
{
	 cout<<" [ MODIFICATION ] ";
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
				cin>>pn1;
				ch=cin.get();
				//  cin.get(ch);
		   }
		    if(check("OFFICE PHONE NUMBER ")=='Y')
		   {
				cout<<"\n ENTER NEW PHONE NUMBER :";
				cin>>pn2;
				ch=cin.get();
				// cin.get(ch);
		   }
		   
	  }
	 fout.write((char*)&obj,sizeof(obj));
	}
   fout.close();
   fin.close();
    }
c
