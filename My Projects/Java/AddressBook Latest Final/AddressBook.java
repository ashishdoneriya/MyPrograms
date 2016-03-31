package Address_book;
import Address_book.Record;
import static Address_book.StringUtils.*;
import static java.lang.System.out;
import java.io.*;

public class AddressBook implements Serializable{
	public Record first;
	public int totalRecords;
	public AddressBook(){
		totalRecords=0;
		first=null;
	}
	
	public boolean isListEmpty(){
		if(first==null)
			return true;
		else
			return false;
	}
	
	public void insertFirst(Record P){
		P.next=first;
		first=P;
	}
	
	public void insertLast(Record P){
		Record temp=first;
		if(isListEmpty()==true){
			first=P;
			return;
		}
		while(temp.next!=null){
			temp=temp.next;
		}
		P.prev=temp;
		temp.next=P;
	}
	
	public Record deleteFirst() throws Exception{
		if (first==null)
			throw (new Exception("List is Empty"));
		Record temp=first;
		first=first.next;
		return temp;
	}
	
	public void insert(Record P){
		Record temp=first;
		if(isListEmpty()==true){
			first=P;
			return;
		}
		while(temp!=null){
			if(Strcmp(temp.name,P.name)==1)
				break;
			temp=temp.next;
		}
		if(temp==null){
			insertLast(P);
			return;
		}
		if(temp.prev==null){
			insertAtFirst(P);
			return;
		}
		P.prev=temp.prev;
		P.next=temp;
		temp.prev.next=P;
		temp.prev=P;
	}
		
	public Record delete(Record P)throws Exception{
		if (first==null)
			throw (new Exception("List is Empty"));
		Record temp=first;
		if(P.equals(first)==true)
			return (deleteFirst());
			
		while(P.equals(temp)==false&&temp!=null)
			temp=temp.next;
			
		if(temp==null)
			throw (new Exception("Record Not Found"));
	
		Record temp1=temp;
		temp.prev.next=temp.next;
		if(temp.next!=null)
			temp.next.prev=temp.prev;
		return temp;
	}
	
	public Record delete(String name) throws Exception{
		if (first==null)
			throw (new Exception("List is Empty"));
		Record temp=first;
		if((temp.name).equalsIgnoreCase(name)==true)
			return (deleteFirst());
			
		while(temp!=null){
			if((temp.name).equalsIgnoreCase(name)==true)
				break;
			temp=temp.next;
		}
		if(temp==null)
			throw (new Exception("Record Not Found"));
		Record temp1=temp;
		if(temp.next==null){
			temp.prev.next=null;
		}
		else{
			temp.prev.next=temp.next;
			if(temp.next!=null)
				temp.next.prev=temp.prev;
		}
		return temp;
	}
	
	public Record delete(long mobile) throws Exception{
		if (first==null)
			throw (new Exception("List is Empty"));
		Record temp=first;
		if(first.mobile==mobile)
			return (deleteFirst());
			
		while(first.mobile!=mobile&&temp!=null)
			temp=temp.next;
			
		if(temp==null)
			throw (new Exception("Record Not Found"));
	
		Record temp1=temp;
		temp.prev.next=temp.next;
		if(temp.next!=null)
			temp.next.prev=temp.prev;
		return temp;
	}
	
	public void display() throws Exception{
		if(first==null)
			throw (new Exception("No record in Database"));
		Record temp=first;
		while(temp!=null){
			temp.display();
			temp=temp.next;
			out.println();
		}
	}
	
	public int getTotalRecords(){
		return totalRecords;
	}
	
	public Record getRecord(String name){
		Record temp=first;
		if(first==null)
			return null;
		while(temp!=null){
			if(((temp.name).toLowerCase()).equals(name.toLowerCase())==true)
				break;
			else
			temp=temp.next;
		}
			return temp;
	}
	
	public Record getRecord(long mobile){
		Record temp=first;
		if(first==null)
			return null;
		while(temp!=null){
			if(temp.mobile==mobile)
				break;
			else
				temp=temp.next;
		}
			return temp;
	}
}
