import static java.lang.System.out;
import java.util.*;
import java.io.*;

class LinkedList implements Serializable{
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
				break;
			}
			out.println(temp.data);
			temp=temp.next;
		}
	}
	public void writeData() throws Exception{
		FileOutputStream fout=new FileOutputStream("LinkedList.dat");
		ObjectOutputStream objout=new ObjectOutputStream(fout);
		objout.writeObject(this);
		fout.close();
		objout.close();
	}
	public static LinkedList read() throws Exception{
		FileInputStream fin=new FileInputStream("LinkedList.dat");
		ObjectInputStream objin=new ObjectInputStream(fin);
		LinkedList F;
		F=((LinkedList)(objin.readObject()));
		fin.close();
		objin.close();
		return F;
	}

}
class testing implements Serializable{
	public String name;
	public LinkedList l;
	public testing(){
		l=new LinkedList();
		l.data=1;
		l.next=null;
		name="ashish";
		l.append(9);
		l.append(2);
	}
	public void display(){
		out.println(name);
		l.display();
	}
	public void writeData() throws Exception{
		FileOutputStream fout=new FileOutputStream("inkedList.dat");
		ObjectOutputStream objout=new ObjectOutputStream(fout);
		objout.writeObject(this);
		fout.close();
		objout.close();
	}
	public static testing read() throws Exception{
		FileInputStream fin=new FileInputStream("inkedList.dat");
		ObjectInputStream objin=new ObjectInputStream(fin);
		testing F;
		F=((testing)(objin.readObject()));
		fin.close();
		objin.close();
		return F;
	}

}
class	UseLinkedList{
	public static void main(String args[]){
		try{
			testing t=new testing();
			t.writeData();
			testing tt=testing.read();
			tt.display();
			
		}
		catch(Exception e){
			out.println(e);
//			e.printStackTrace();
		}
		
		
	}
}
