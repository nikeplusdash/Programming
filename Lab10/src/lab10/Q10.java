package lab10;

class cException extends Exception
{
    public cException(String s)
    {
        super(s);
        
    }
}

public class Q10
{
	public static void main(String[] args) {
	try{
	    throw new cException("Custom exception");
	}
	catch (cException e)
	{
	   System.out.println("Exception:"+e);
	}
	}
}
