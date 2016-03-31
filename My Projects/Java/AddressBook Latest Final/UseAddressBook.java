package Address_book;
import Address_book.Record;
import Address_book.AddressBook;
import static Address_book.StringUtils.*;
import static java.lang.System.out;
import java.util.*;
import java.io.*;

public class UseAddressBook implements Serializable{
	
	public AddressBook start;
	public String directory;
	public UseAddressBook(){
		start=new AddressBook();
		getFileName();
		readFromFile();
	}
	
	public UseAddressBook(String directory){
		start=new AddressBook();
		this.directory=directory;
		readFromFile();
	}
	
	public void writeOnFile(){
		try{
			FileOutputStream fout=new FileOutputStream(directory);
			ObjectOutputStream objout=new ObjectOutputStream(fout);
			objout.writeObject(start);
			fout.close();
			objout.close();
		}
		catch(IOException e){
			out.println(e);
		}
	}
	public void readFromFile(){
		try{
			FileInputStream fin=new FileInputStream(directory);
			ObjectInputStream objin=new ObjectInputStream(fin);
			start=((AddressBook)(objin.readObject()));
			fin.close();
			objin.close();
		}
		catch(Exception e){
			out.println("New File Created");
			writeOnFile();
		}
	}
	public void getFileName(){
		out.print("Enter the file name : ");
		String directory=(new Scanner(System.in)).next();
		this.directory=directory;
	}
	
	public void menu(){
		char ch;
		Scanner kb=new Scanner(System.in);	
		do{
			out.println("======================================");
			out.println("\n::ADDRESS BOOK::\n");
			out.print("A::Add\t");
			out.print("V::View\t");
			out.print("S::Search\t");
			out.println("M::Modify");
			out.print("D::Deletion\t");
			out.print("F::Format\t");
			out.println("E::Exit");
			out.println("Enter your choice");
			ch=(kb.next()).charAt(0);
			out.println("======================================");
			switch (ch){
				case 'A':
				case 'a':
					add();
			//		writeOnFile();
					break;
				case 'V':
				case 'v':
					display();
					break;
				case 'M':
				case 'm':
					modify();
			//		writeOnFile();
					break;
				case 'D':
				case 'd':
					delete();
			//		writeOnFile();
					break;
				case 'S':
				case 's':
					search();
				break;
				case 'e':
				case 'E':
					writeOnFile();
					System.exit(0);
				case 'f':
				case 'F':
					start.first=null;
					break;
				default:
					out.println("Wrong Choice");
			}
		}while(ch!='e'||ch!='E');
	}
	public void add(){
		try{
			start.insert(this.get());
		}
		catch(Exception e){
			out.println(e.getMessage());
		}
	}
	
	public Record get() throws Exception{
		Record P=new Record();
		String S;
		Scanner kb=new Scanner(System.in);
		out.print("Enter name : ");
		P.name=kb.nextLine();
		if((P.name).length()==0)
			throw (new Exception("Invalid Name"));
		P.name=UpperLower(P.name);
		if(start.getRecord(P.name)!=null)
			throw (new Exception("Name already exist"));
		out.print("Enter Mobile No. : ");
		S=kb.nextLine();
		if(S.length()!=0){
			if(IsValidMobile(S)==false)
				throw (new Exception("Invalid Mobile No."));
			else
				P.mobile=Long.parseLong(S);
		}
		out.print("Enter Landline No. : ");
		S=kb.nextLine();
		if(S.length()!=0){
			if(IsValidNumber(S)==false)
				throw (new Exception("Invalid Landline No."));
			else
				P.landline=Long.parseLong(S);
		}
		out.print("Enter your email : ");
		P.email=kb.nextLine();
		if((P.email).length()!=0&&IsValidEmail(P.email)==false)
				throw (new Exception("Invalid Email"));
		return P;
	}
		public Record getModified() throws Exception{
		Record P=new Record();
		String S;
		Scanner kb=new Scanner(System.in);
		boolean repeat=true;
		do
		{
			out.print("Enter name : ");
			P.name=kb.nextLine();
			P.name=UpperLower(P.name);
			repeat=false;
			if(start.getRecord(P.name)!=null){
				out.println("Name already Exist");
				repeat=true;
			}
		}while(repeat==true);
		out.print("Enter Mobile No. : ");
		S=kb.nextLine();
		if(S.length()!=0){
			if(IsValidMobile(S)==false)
				throw (new Exception("Invalid Mobile No."));
			else
				P.mobile=Long.parseLong(S);
		}
		out.print("Enter Landline No. : ");
		S=kb.nextLine();
		if(S.length()!=0){
			if(IsValidNumber(S)==false)
				throw (new Exception("Invalid Landline No."));
			else
				P.landline=Long.parseLong(S);
		}
		out.print("Enter your email : ");
		P.email=kb.nextLine();
		if((P.email).length()!=0&&IsValidEmail(P.email)==false)
				throw (new Exception("Invalid Email"));
		return P;
	}
	
	public void display(){
		try{
			start.display();
		}
		catch(Exception e){
			out.println(e.getMessage());
		}
	}
	
	public void modify(){
		String str;
		Record rcd=null,p=null;
		out.println("Enter name or mobile number");
		str=(new Scanner(System.in)).nextLine();
		try{
			if(IsValidMobile(str)==true)
				p=start.getRecord(Long.parseLong(str));
			else
				p=start.getRecord(str);
			if(p==null)
				throw (new Exception("No record found"));
			rcd=new Record(p);
			rcd.displayRecord();
			Record rcd1=getModified();
			if((rcd1.name).length()!=0)
				rcd.name=rcd1.name;
			if(rcd1.mobile!=0)
				rcd.mobile=rcd1.mobile;
			if(rcd1.landline!=0)
				rcd.landline=rcd1.landline;
			if(rcd1.email.length()!=0)
				rcd.email=rcd1.email;
			start.delete(p);
			start.insert(rcd);
		}
		
		catch(Exception e){
			out.println(e.getMessage());
			return;
		}
	}
	
	public void search(){
		Scanner kb=new Scanner(System.in);
		String str;
		Record temp=start.first;
		int count=0;
		if(start.isListEmpty()==true){
			out.println("No record in the database");
			return;
		}
		out.println("Enter name or mobile number");
		str=kb.nextLine();
		if(str.length()==0)
			return;
		if(IsValidMobile(str)==true){
			while(temp!=null){
				if(StrcmpAdv(temp.mobile,Long.getLong(str))==true){
					temp.displayRecord();
					count++;
				}
				temp=temp.next;
			}
		}
		else{
			while(temp!=null){
				if(StrcmpAdv(temp.name,str)==true){
					temp.displayRecord();
					count++;
				}
				temp=temp.next;
			}
		}
		if(count==0)
			out.println(str+" not found in the database");
		else
			out.println(count+" records found.");
	}
	
	public void delete(){
		out.println("Enter the name or number to be deleted : ");
		String str=(new Scanner(System.in)).next();
		if(str.length()==0)
			return;
		try{
			Record rcd=null;
			if(IsValidMobile(str)==true)
				rcd=start.delete(Long.parseLong(str));
			else
				rcd=start.delete(UpperLower(str));
			out.println("Record Deleted = "+rcd.name);
		}
		catch(Exception e){
			out.println(e.getMessage());
		}
	}
}
