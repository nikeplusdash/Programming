public class Q8
{
     public static void main(String[] args) {
        int ar[]={1,2,3,4,5};
        try{
            int a=ar[6];
        }    
        catch(ArrayIndexOutOfBoundsException e)
        {
            System.out.println("Array index out of bounds Exception");

        }

    }
}