import static java.lang.System.out;
import java.util.*;
import java.io.*;

class LinkedList{
	public int data;
	public LinkedList next;
	public void append(int num){
		LinkedList temp;
		temp=new LinkedList();
		temp.data=num;
		temp.next=null;
		LinkedList loop=this;
		while (loop.next!=null)
		{
			loop=loop.next;
		}
	loop.next=temp;
	}
	public void display(){
		LinkedList temp=this;
		for(;;){
			if(temp==null){
				out.println("Here");
				break;
			}
			out.println(temp.data);
			temp=temp.next;
		}
	}
}
class	UseLinkedList{
	public static void main(String args[]){
		LinkedList p=new LinkedList();
		p.data=20;
		p.next=null;
		p.append(20);
		p.append(30);
		p.append(40);
		p.append(50);
		p.display();
	}
}
