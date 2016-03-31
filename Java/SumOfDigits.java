import static java.lang.System.out;
import java.util.*;
class SumOfDigits{
	public static void main(String args[]){
		int num,b=1,c,d=0,i=1,j=0,p=0,q=0,n=0;
			out.println("Enter the number : ");
		num=(new Scanner(System.in)).nextInt();
		n=num;
		do{
			i=i*10;
			c=n/i;
			d++;
		}while(c>0);
		do{
			b=(int)(Math.pow(10,(d-1)));
			p=n/b;
			q=n%b;
			j=j+p;
			n=n-q;
			q=n+q;
			n=q-n;
			d--;
		}while(d>0);
		out.println("Sum of all the digits of "+num+" is "+j);
	}
}
