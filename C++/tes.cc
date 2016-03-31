void AddressBook::extremeSearch(){
	ifstream obj;
	int i=0,j=0,len,count;
	int k=0;
	char str[30],**str1,search[30]ch=1;
	try{
		obj.open(diafsfarectory);
		if(!obj)
			throw FileNotFoundException();
		system("clear");
		while(ch!=32){
		cout<<"Enter name or mobile no. : ";
		ch=getch();
		str[i++]=ch;
		len=strlen(str);
		if(ch==32)
			return;
		if(isValidNumber(str)==true&&len<=10){
			for(i=0,count=0;i<getTotalRecords()-1;i++){
				obj.read((char *)this,size());
				if(strcmpAdv(mobile,getNumber(str),len)==1){
					show();
					count=count+1;
				}
			}
			if(count==0)
				throw NoRecordFoundException();
		}
		else{
			for(i=0,count=0;i<getTotalRecords()-1;i++){
				obj.read((char *)this,size());
				str1=getCombinations(str);
				for(j=0;j<4;j++){
					if((strcmpAdv(name,str1[j])==1)||strcomp(email,str)!=-1){
						show();
						count=count+1;
						break;
					}
				}
			}
			if(count==0)
				throw NoRecordFoundException();
			else
				cout<<"\n"<<count<<" records found"<<endl;
		}
	}
	}
	catch(FileNotFoundException fe){
		cout<<fe.str<<endl;
	}
	catch(NoRecordFoundException r){
		cout<<r.str<<endl;
	}
	getch();
	obj.close();
}
