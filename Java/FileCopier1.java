//File Copier Program

import java.io.*;
import java.util.*;
import static java.lang.System.out;

class FileCopier1{
	public static void main(String args[]){
		Date d=new Date();
		out.println(d);
		File f=new File("E:\\Inspire\\PIctures");
		File []fs=f.listFiles();
		FileInputStream fin;//=null;
		File f1=new File("D:/1/");
		File f2;
		FileOutputStream fr;//=null;
		byte arr[]=new byte[1];
		int i=0;
		int j=fs.length,total=0;
		for(i=0;i<fs.length;i++){
			if(fs[i].isFile())
				total++;
			}
		int t=1;
		//out.println(total);
		i=0;
		try{	
			while(i<j){
				if(fs[i].isFile()){
					f2=new File(f1,fs[i].getName());
					fr=new FileOutputStream(f2);
					fin=new FileInputStream(fs[i].getAbsolutePath());
					arr=new byte[(int)(fs[i].length())];
					fin.read(arr);
					fr.write(arr);
					out.println("Total "+((t++)*100/total)+"% Files Copied out of "+100+"% Files");
					
				}
					i++;
			}
		}
		catch(IOException e){
			out.println("File Not Found");
		}
		f=new File("/home/ashish/Desktop");
		fs=f.listFiles();
//		out.println((fs[0].lastModified()-fs[j-1].lastModified())/1000);
	}
}
