//File Copier Program

import java.io.*;
import java.util.*;
import static java.lang.System.out;

class aa{
	public void folder(File []fs,File src,File dest) throws IOException{
			out.println(dest.getPath());
			
		File f2;
		FileOutputStream fr=null;
		FileInputStream fin=null;
		byte arr[]=new byte[1];
		int	j=fs.length;
		int i;
		for(i=0;i<j;i++){
			if(fs[i].isDirectory()){
		//		out.println(fs[i].getPath());
			//	File faa=new File(dest);
			//	out.println(dest.mkdirs());
				aa aaa=new aa();
				aaa.folder(fs[i].listFiles(),fs[i].getPath(),new File(fs[i].Name));
			}
		if(fs[i].isFile()){
			f2=new File(dest,fs[i].getName());
			fr=new FileOutputStream(f2);
			fin=new FileInputStream(fs[i].getAbsolutePath());
			arr=new byte[(int)(fs[i].length())];
			fin.read(arr);
			fr.write(arr);
		}
	}
	}
}


class FileCopier{
	public static void main(String args[]){
		File f4=new File("D:\\3\\2\\1\\1\\1\\");
		f4.mkdirs();
		File f=new File("D:\\3\\");
		File []fs=f.listFiles();
		FileInputStream fin=null;
		File f1=new File("D:\\");
		File f2;
		FileOutputStream fr=null;
		try{	
			aa aaa=new aa();
			out.println(fs[0].getName());
			aaa.folder(f.listFiles(),f,f1);
		}
		catch(IOException e){
			out.println(e.getMessage());
		}
	}
}
