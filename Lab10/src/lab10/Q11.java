import java.util.Scanner;
class invmatrix extends Exception
{
    invmatrix ()
    {
        super("not a square matrix");
    }
}
public class Q11
{
	public static void main(String[] args) {
	    Scanner sc=new Scanner(System.in);
		System.out.println("Enter mXn");
		int m,n;
		m=sc.nextInt();
		n=sc.nextInt();
		if(m!=n)
		try{
		    throw new invmatrix();
		}
		catch(invmatrix e)
		{
		    System.out.println(e);
		}
		else
		System.out.println("valid ");
		
	}
}
