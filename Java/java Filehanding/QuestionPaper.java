//Program to Extract 10 Question out of 100 questions from a file
// Name:- Ashish Doneriya
// Scholar NO. 101112011

import static java.lang.System.out;
import java.util.*;
import java.io.*;

class QuestionPaper{
	public static void main(String args[]){
		Scanner kb=new Scanner(System.in);
		int que=0;
		while(que==0){
			try{
				out.print("Enter the  value between 1 to 91 :: ");
				que=kb.nextInt();
				if(que>91||que<1){
					throw (new InputMismatchException());
				}
			}
			catch(InputMismatchException e){
				out.println("Wrong  Input");
				System.exit(0);
			}
		}
		File f=new File("D:/");
		File qs=new File(f,"questions.txt");
		File ops=new File(f,"options.txt");
		File qp=new File(f,"QuestionPaper.txt");
		
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
			
			i=1;
			
			while(i<11){
				//writing the question in the file
				strq=bq.readLine();
				queno=strq.indexOf("N");
				temp="QN"+i+strq.substring((queno+3),strq.length())+"\n";
				arr=new char[(temp.length())];
			//	temp.getChars(0,str.length(),arr,0);
				fw.write(temp);
				i++;
				
				//writing the options in the file
				stro=bo.readLine();
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

