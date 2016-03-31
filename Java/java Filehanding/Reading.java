// Program for reading the file
import java.io.*;
import java.util.*;
import static java.lang.System.out;
class Reading{
	public static void main(String args[]){
		Scanner kb=new Scanner(System.in);
		out.print("Enter the file name  :: ");
		String s=kb.next();
		File f1=new File("D:/");
		File f2=new File(f1,s);
		FileReader fr=null;
		try{
			fr=new FileReader(f2);
			int ch,count=0;
			while((ch=fr.read())!=-1){
				out.print((char)ch);
				count++;
			}
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
