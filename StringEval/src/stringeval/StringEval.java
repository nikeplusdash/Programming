package stringeval;
import java.util.Scanner;

public class StringEval {
    public static void p (String arg) {
        System.out.print(arg);
    }
    public static void replace(String s) {
        p(s.replace('e','a')+"\n");        
    }
    public static String substr(String s) {
        return s.substring(2,7);        
    }
    public static void capital(String s) {
        String arr[] = s.split("\\s");
        for(int i=0;i<arr.length;i++) {
            p(Character.toUpperCase(arr[i].charAt(0))+ arr[i].substring(1)+" ");
        }
        p("\n");
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        p("Input String: ");
        String s = in.nextLine();
        replace(s);
        p(substr(s)+"\n");
        capital(s);
    }
}
