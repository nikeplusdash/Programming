package lab1;
import java.util.Scanner;

public class Lab1 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Rectangle.rectangle(in.nextInt(),in.nextInt());
        Numbers.numbers();
        Odd.generate();
    }
    
}
