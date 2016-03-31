// Program for reading the file
import java.io.*;
import java.util.*;
import static java.lang.System.out;
class Writing{
	public static void main(String args[]){
		Scanner kb=new Scanner(System.in);
		out.print("Enter the file name  :: ");
		String s=kb.next();
		File f1=new File("D:/");
		File f2=new File(f1,s);
		FileWriter fw=null;
		try{
			fw=new FileWriter(f2,false);
			out.println("Enter the text :: ");
			String strtemp=kb.nextLine();
			String str=kb.nextLine();
			char []arr=new char[(str.length())];
			str.getChars(0,str.length(),arr,0);
			fw.write(arr);
		}
		catch(FileNotFoundException e){
			out.println("File Not Available");
		}
		catch(IOException e){
			out.println("String could't read file");
		}
		finally{
			if(fw!=null){
				try{
					fw.close();
				}
				catch(IOException e){
					out.println("Error in closing file");
				}
			}
		}
	}
}
