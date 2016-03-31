/*
 * First Come First Serve Technique
 * Name : 		 Ashish Doneriya
 * Scholar No. : 101112011
 */
 import static java.lang.System.out;
 import java.util.*;
 
 class Process{
	 private int ET;
	 private int WT;
	 private int TAT;
	 public int getET(){
		 return ET;
	 }
	 public int getWT(){
		 return WT;
	 }
	 public int getTAT(){
		 return TAT;
	 }
	 public void setET(int ET){
		 this.ET=ET;
	 }
	 public void setWT(int WT){
		 this.WT=WT;
	 }
	 public void setTAT(int TAT){
		 this.TAT=TAT;
	 }
	 
 }
 
class UseProcess{
	 public static void main(String args[]){
		 Scanner kb=new Scanner(System.in);
		 double totalWT=0,totalTAT=0;
		 int i=0,temp1=0,N;
		 out.print("Enter the number of Process :: ");
		 N=kb.nextInt();
		 Process p[]=new Process[N];
		 for(i=0;i<N;i++){
			 out.print("Enter the Execution time for process p"+(i+1)+" :: ");
			 p[i].setET(kb.nextInt());
		 }
		 for(i=0;i<N;i++){
			 p[i].setWT(temp1);
			 temp1=temp1+p[i].getET();
			 p[i].setTAT(temp1);
			 out.println("Process p"+(i+1)+"\tWaiting Time = "+p[i].getWT());
			 out.print("\tTurn Around Time = "+p[i].getTAT());
			 totalWT=totalWT+p[i].getWT();
			 totalTAT=totalTAT+p[i].getTAT();
		}
		out.println("\nAverage Waiting Time ="+totalWT/N);
		out.println("\nAverage Turn Around Time ="+totalTAT/N);
	}
}
