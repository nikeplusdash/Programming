
import java.util.Scanner;
class negativeexcep extends Exception{
    negativeexcep()
    {
        super("Negative no. in root");  
    }
}
public class Q12
{
	public static void main(String[] args) {
		Scanner sc=new Scanner (System.in);
		int n=0;
		System.out.println("Enter a no. to find root");
		try{
		    n=sc.nextInt();
		    if(n<0)
		    throw new negativeexcep();
		    
		}
		catch (negativeexcep e)
		{
		    System.out.println(e);
			n=Math.abs(n);
		}
		System.out.println(Math.sqrt(n));
	}
}

		
	