package lab10;

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
		int[][] a={{1,2,3},{4,5,6},{7,8}};
		try{
		    int rows = a.length;
                    for(int[] i:a){
                        int cols=i.length;
                        if(rows!=cols)throw new invmatrix();
                    }
		}
		catch(invmatrix e)
		{
		    System.out.println(e);
		}
		System.out.println("valid ");
		
	}
}
