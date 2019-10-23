import java.util.Scanner;
public class Q9
{
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String name="";
        int ar[]=new int[3];
        int roll;
        System.out.println("Enter name");
        try{
            name=sc.nextLine();
            int i=Integer.parseInt(name);

        }
        catch (NumberFormatException e){
            System.out.println("string->int failure");


        }
        System.out.println("enter roll no.");
        roll=sc.nextInt();
        System.out.println("Enter marks");
        ar[0]=sc.nextInt();
        ar[1]=sc.nextInt();
        ar[2]=sc.nextInt();
        System.out.println("Details");
        System.out.println(name+" "+roll+" "+ar[0]+" "+ar[1]+" "+ar[2]);
    }
}