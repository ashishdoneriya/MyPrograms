import java.io.*;
import java.util.*;
import static java.lang.System.out;
class File1{
	public static void main(String args[]){
		try{
		Scanner kb=new Scanner(System.in);
		FileOutputStream f1out=new FileOutputStream("test.dat");
		DataOutputStream dout=new DataOutputStream(f1out);
		
		out.println("Enter your name and age");
		String name=kb.nextLine();
		int age=kb.nextInt();
		dout.writeUTF(name);
		dout.writeInt(age);
		
		dout.close();
		FileInputStream fin=new FileInputStream("test.dat");
		DataInputStream din=new DataInputStream(fin);
		
		out.println("\n\n;;;;;;;;;;;;;;;;;\n");
		out.println("Name = "+din.readUTF()+"\nage = "+din.readInt());
		din.close();
	 }
	catch(Exception e){
		out.println("ERROR");
	}
	}
}
