//Program to Extract 10 Question (random questions) out of 100 questions from a file
// Name:- Ashish Doneriya
// Scholar NO. 101112011

import static java.lang.System.out;
import java.util.*;
import java.io.*;

class QuestionPaper{
	public static void main(String args[]){
		Scanner kb=new Scanner(System.in);
		int que=0;
		try{
				out.print("Enter the  value :: ");
				que=kb.nextInt();
		}
		catch(InputMismatchException e){
			out.println("Wrong  Input");
			System.exit(0);
		}
		File f=new File("");
		File qs=new File("questions.txt");
		File ops=new File("options.txt");
		File qp=new File("QuestionPaper.txt");
		
		FileReader frq=null,fro=null;
		FileWriter fw=null;
		try{
			frq=new FileReader(qs);
			BufferedReader bq=new BufferedReader(frq);
			
			fro=new FileReader(ops);
			BufferedReader bo=new BufferedReader(fro);
			
			fw=new FileWriter(qp);
			
			char []arr;
			String strq,stro,temp;
			int queno,i;
			
			//Skipping the file pointer to the question no. given by user
			for(i=1;i<que;i++){
				bq.readLine();
				bo.readLine();
			}
			
			i=que;
			int j=1;
			while(j<11){
				//writing the question in the file
				do{
				strq=bq.readLine();
				stro=bo.readLine();
				while(
				queno=strq.indexOf("N");
				temp="QN"+j+strq.substring((queno+3),strq.length())+"\n";
				arr=new char[(temp.length())];
				fw.write(temp);
				j++;
				i=(i+4);
				//writing the options in the file
				arr=new char[stro.length()];
				stro.getChars(0,stro.length(),arr,0);
				temp=new String(arr);
				temp=temp+"\n";
				fw.write(temp);
			}
		}
		catch(FileNotFoundException e){
			out.println("File Not Available");
		}
		catch(IOException e){
			out.println("String could't read file");
		}
		finally{
			if((frq!=null)||(fro!=null)||(fw!=null)){
				try{
					frq.close();
					fro.close();
					fw.close();
				}
				catch(IOException e){
					out.println("Error in closing file");
				}
			}
		}
	}
}

