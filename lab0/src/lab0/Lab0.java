package lab0;
import java.util.Scanner;

public class Lab0 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("\nEnter n (prime nos.):");
        Prime.prime(in.nextInt());
        
        System.out.println("\nEnter n(natural nos.)");
        System.out.println(Natsum.natnum(in.nextInt()));
        
        System.out.println("Enter n(fiboncci nos.)");
        Fibo.fibo(in.nextInt());
        
        System.out.println("\nEnter n(sum of harmonic)");
        System.out.println(Harmonic.sum(in.nextInt()));
        
        MatMul.mul();
        
        StudCred.stud();
        
    }
}
