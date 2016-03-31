// Program for reading the file
import java.io.*;
import java.util.*;
import static java.lang.System.out;
class Reading1{
	public static void main(String args[]){
		Scanner kb=new Scanner(System.in);
		out.print("Enter the file name  :: ");
		String s=kb.next();
		File f1=new File("D:/");
		FileReader fr=null;
		int count=0;
		try{
			File f2=new File(f1,s);
			if(f2.exists()==false){
				throw (new FileNotFoundException());
			}
			fr=new FileReader(f2);
			char []ch=new char[(int)f2.length()];
			fr.read(ch,0,ch.length);
			String str=new String(ch);
			out.println(str);
			out.println("\nTotal Characters read :: "+count);
		}
		catch(FileNotFoundException e){
			out.println("File Not Available");
		}
		catch(IOException e){
			out.println("String could't read file");
		}
		finally{
			if(fr!=null){
				try{
					fr.close();
				}
				catch(IOException e){
					out.println("Error in closing file");
				}
			}
		}
	}
}
