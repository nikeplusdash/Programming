public class Q7
{
    public static void main(String args[])
    {
        String s="What's up";
        try
        {
            int x=Integer.parseInt(s);
            
        }
        catch (NumberFormatException e)
        {
            System.out.println("You messed up");
        }

    }
}