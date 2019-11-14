package lab10;

import java.util.Stack;
import jdk.jfr.StackTrace;

class cException extends Exception
{
    String s;
    public cException(String s)
    {
    }
    @Override
    public String toString(){
        StackTraceElement[] n = this.getStackTrace();
        s="";
        for(StackTraceElement o:n) s+= "1]"+o;
        return "Exception occured at: "+cException.class.getSimpleName()+" -> "+this.getMessage()+
                "\nTracing Cause: "+ this.getStackTrace()[0];
    }
}

public class Q10
{
	public static void main(String[] args) throws cException{
//	try{
	    throw new cException("Custom exception");
//	}
//	catch (cException e)
//	{
//	   System.out.println("Exception: "+e);
//	}
	}
}
