public class Q7
{
    public static void main(String args[])
    {
        String s="abc";
        try
        {
            int x=Integer.parseInt(s);
            
        }
        catch (NumberFormatException e)
        {
            System.out.println("Number Format Exception");
        }

    }
}