import java.io.*;
//import java.util.*;
import static java.lang.System.out;

class file1{
	public static void main (String args[]) {
		File f=new File("D:/ashish.txt");
		out.println(f.isFile());
		out.println(f.isDirectory());
		out.println(f.isHidden());
		out.println(f.isAbsolute());
		out.println(f.canRead());
		out.println(f.canWrite());
		out.println(f.getName());
		out.println(f.getPath());
		out.println(f.getAbsolutePath());
		out.println(f.length());
		out.println(f.lastModified());
	}
}

