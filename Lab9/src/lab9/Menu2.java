package lab9;

import java.util.Scanner;

public class Menu2 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String str = in.next();
        System.out.println("1:Compare\t2:Flip");
        while(true) {
            Integer x = in.nextInt();
            switch(x) {
                case 1:
                    break;
                case 2:
                    str = flip(str);
                    break;
                default:
                    break;
            }
        }
    }
}
