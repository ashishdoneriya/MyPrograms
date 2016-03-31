import java.util.*;
import static java.lang.System.out;
class InvalidNumeratorException extends Exception{
	public InvalidNumeratorException(String msg){
		super(msg);
	}
}

class DivideNos{
	public static void main(String args[]){
		Scanner kb=new Scanner(System.in);
		try{
			System.out.println("Enter two integers : ");
			int a=kb.nextInt();
			int b=kb.nextInt();
			if (a<=0){
				throw new InvalidNumeratorException("Numerator should be positive");
			}
			int c=a/b;
			System.out.println("Division is "+c);
		}
		catch(InputMismatchException e){
			System.out.println("Please input integer digits only");
		}
		catch(ArithmeticException e){
			System.out.println(e.getmessage());
		}
		catch(InvalidNumeratorException e){
			System.out.println(e.getmessage());
		}
	}
}
