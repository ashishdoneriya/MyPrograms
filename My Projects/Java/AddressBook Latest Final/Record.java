package Address_book;
import java.io.*;

public class Record implements Serializable{
	
	public long mobile,landline;
	public String name,email;
	public Record prev,next;
	public Record (Record P){
		this.name=P.name;
		this.email=P.email;
		this.mobile=P.mobile;
		this.landline=P.landline;
		this.next=this.prev=null;
	}
	public Record(){
		name="";
		mobile=0;
		email="";
		landline=0;
		prev=next=null;
	}
	
	public Record(String name, long mobile, long landline, String email){
		this.name=name;
		this.mobile=mobile;
		this.landline=landline;
		this.email=email;
		this.prev=this.next=null;
	}
	
	public void displayRecord(){
		System.out.println("Name\t\t:: "+name);
		System.out.println("Mobile No.\t:: "+mobile);
		System.out.println("Landline No.\t:: "+landline);
		System.out.println("Email id. \t:: "+email);
	}
	public void display(){
		System.out.println("Name\t\t:: "+name);
		if(mobile!=0)
			System.out.println("Mobile No.\t:: "+mobile);
		if(landline!=0)
			System.out.println("Landline No.\t:: "+landline);
		if(email.length()!=0)
			System.out.println("Email id. \t:: "+email);
	}
}
