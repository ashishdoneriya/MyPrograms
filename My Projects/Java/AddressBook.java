import Address_book.StringUtils;
import java.io.*;
import java.util.*;
import static java.lang.System.out;

class AddressBook extends StringUtils{
	private long mobile,landline;
	private String name,email;
	private AddressBook prev,next;
	private static String directory;
	public AddressBook(String S){
		directory=S;
		mobile=landline=0;
		name=email="";
		prev=next=null;
	}
	public AddressBook(AddressBook T){
		this.name=T.name;
		this.email=T.email;
		this.mobile=T.mobile;
		this.landline=T.landline;
		this.prev=T.prev;
		this.next=T.next;
	}
	public AddressBook(){
		initialize();
	}
	public void getCopy(AddressBook T){
		this.name=T.name;
		this.email=T.email;
		this.mobile=T.mobile;
		this.landline=T.landline;
		this.prev=T.prev;
		this.next=T.next;
	}
	public void addAtFirst(AddressBook T) throws Exception{
		AddressBook temp=new AddressBook();
		temp=T;
		temp.prev=null;
		if(this.isEmpty()==true){
			this.getCopy(T);
			this.next=this.prev=null;
		}
		else{
			temp.next=this;
			this.prev=temp;
			this.getCopy(temp);
		}
	}
	public boolean isEmpty(){
		if (this.next==null&&this.prev==null&&this.name.length()==0)
			return true;
		else
			return false;
	}
	public void delAtFirst()throws Exception{
		if(this.isEmpty()==true)
			throw (new Exception("File is Empty"));
		AddressBook temp=new AddressBook();
		if(this.next==null)
			this.initialize();
		else
			this.getCopy(this.next);
			this.prev=null;
	}
	public void delete(String  name)throws Exception{
		if(this.isEmpty()==true)
			throw (new Exception("File is Empty"));
		if ((this.name).equalsIgnoreCase(name)==true){
			delAtFirst();
			return;
		}
		AddressBook temp=this;
		AddressBook prev=temp;
		while((temp.name).equalsIgnoreCase(name)==false&&temp.next!=null){
			temp=temp.next;
		}
		if ((temp.name).equalsIgnoreCase(name)==true){
			if(temp.next==null)
				temp.prev.next=null;
			else
				temp.prev.next=temp.next;
		}
		throw (new Exception("Record Not Found"));
	}
	public void delete(long mobile)throws Exception{
		if(this.isEmpty()==true)
			throw (new Exception("File is Empty"));
		if (this.mobile==mobile){
			delAtFirst();
			return;
		}
		AddressBook temp=this;
		AddressBook prev=temp;
		while(this.mobile==mobile&&temp.next!=null){
			temp=temp.next;
		}
		if (this.mobile==mobile){
			if(temp.next==null)
				temp.prev.next=null;
			else
				temp.prev.next=temp.next;
		}
		throw (new Exception("Record Not Found"));
	}
	
	public void add(AddressBook T)throws Exception{
		if(this.isEmpty()==true){
			addAtFirst(T);
			return;
		}
		AddressBook temp=this;
		AddressBook prev=temp;
		while((Strcmp(T.name,temp.name)!=(-1))&&temp.next!=null){
			temp=temp.next;
		}
		if (Strcmp(T.name,temp.name)==(-1)){
			
			T.prev=temp.prev;
			temp.prev.next=T;
		}
	}

	public void addition(){
		try{
			get();
			AddressBook T=this;
			addRecord(T);
		}
		catch(Exception e){
			out.println(e.getMessage());
		}
	}
	public void display(){
		try{
			AddressBook T=this;
			if(this.isEmpty()==true){
				out.println("No Reord Empty");
				return;
			}
			while(T!=null){
				T.show();
			}
		}
		catch(Exception e){
			out.println(e.getMessage());
		}
	}
	public void modify(){
	}
	public void deletion(){
		out.println("Enter the name or number to be deleted : ");
		String str=(new Scanner(System.in)).next();
		if(str.length()==0)
			return;
		long mobile=0;
		try{
			if(IsValidMobile(str)==true)
				delete(Long.parseLong(str));
			else
				delete(UpperLower(str));
		}
		catch(Exception e){
			out.println(e.getMessage());
		}
	}
	
	public void search(){
		if(this.isEmpty()==true){
			out.println("NO record");
			return;
		}
		out.println("Enter the name or number : ");
		String str=(new Scanner(System.in)).next();
		String ss;
		AddressBook temp=this;
		if(IsValidMobile(str)==true){
			while(temp!=null){
				ss=(valueOf(temp.mobile));
				if(ss.indexOf(str)!=-1){
					temp.show();
				}
			}
		}
	}
	public void createFile(){
	}
	public void initialize(){
		mobile=landline=0;
		name="";
		email="";
		next=prev=null;
	}
	public void get() throws Exception{
		initialize();
		String S;
		Scanner kb=new Scanner(System.in);
		out.print("Enter name : ");
		name=kb.nextLine();
		if(name.length()==0)
			throw (new Exception("Invalid Name"));
		out.print("Enter Mobile No. : ");
		S=kb.nextLine();
		if(S.length()!=0){
			if(IsValidMobile(S)==false)
				throw (new Exception("Invalid Mobile No."));
			else
				mobile=Long.parseLong(S);
		}
		out.print("Enter Landline No. : ");
		S=kb.nextLine();
		if(S.length()!=0){
			if(IsValidNumber(S)==false)
				throw (new Exception("Invalid Landline No."));
			else
				landline=Long.parseLong(S);
		}
		out.print("Enter your email : ");
		email=kb.nextLine();
		if(email.length()!=0&&IsValidEmail(email)==false)
				throw (new Exception("Invalid Email"));
	}
	public void show()throws Exception{
		if(this.isEmpty()==true)
			throw (new Exception("Empty Record"));
		out.println("Name\t"+this.name);
		out.println("Mobile No.\t"+this.mobile);
		out.println("Landline\t"+this.landline);
		out.println("Email\n"+this.email);
	}
	public void menu(){
		String S;
		Scanner kb=new Scanner(System.in);	
		do{
			out.println("::ADDRESS BOOK::\n");
			out.println("A::Add");
			out.println("V::View");
			out.println("S::Search");
			out.println("M::Modify");
			out.println("D::Deletion");
			out.println("R::Remove File");
			out.println("F::Format File");
			out.println("G::Goto Another File");
			out.println("E::Exit");
			out.println("Enter your choice");
			S=kb.next();			
			switch (S.charAt(0)){
				case 'A':
				case 'a':
					addition();
					break;
				case 'V':
				case 'v':
					display();
					break;
				case 'M':
				case 'm':
					modify();
					break;
				case 'D':
				case 'd':
					deletion();
					break;
				case 'F':
				case 'f':{
					/*	ofstream obj;
						obj.open(directory);
						obj.close();
						cout<<"Formatted";
						*/break;
						}
				case 'S':
				case 's':
					search();
				break;
				case 'G':
				case 'g':
					createFile();
					break;
				case 'E':
					System.exit(0);
				case 'r':
				case 'R':
					out.print("Enter the file name : ");
					String temp=kb.nextLine();
					break;
				default:
					out.println("Wrong Choice");
			}
		}while(S.equalsIgnoreCase("e")==false);
	}
}
class UseAddressBook{
	public static void main(String args[]){
		AddressBook a=new AddressBook("ashish");
		a.initialize();
		try{
		}
		catch(Exception e){
			out.println(e);
		}
	}
}
