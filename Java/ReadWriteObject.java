import java.io.*;
import java.util.*;
import static java.lang.System.out;
class Employee implements Serializable{
	private String age;
	private String sal;
	public void setData(){
		Scanner kb=new Scanner(System.in);
		out.println("Enter age and sal");
		age=kb.nextLine();
		sal=kb.nextLine();
	}
	public void showData(){
		out.println(age+"\t"+sal);
	}
	public void writeData() throws Exception{
		FileOutputStream fout=new FileOutputStream("Employee.dat");
		ObjectOutputStream objout=new ObjectOutputStream(fout);
		objout.writeObject(this);
		fout.close();
		objout.close();
	}
}

class ReadWriteObject{
	public static void main(String args[]){
		try{
			Employee E=new Employee();
			E.setData();
			E.writeData();
			FileInputStream fin=new FileInputStream("Employee.dat");
			ObjectInputStream objin=new ObjectInputStream(fin);
			Employee F;
			((Employee)(objin.readObject())).showData();
			fin.close();
			objin.close();
		}
		catch(Exception e){
			out.println(e.getMessage());
//			e.printStackTrace();
		}
	}
}
