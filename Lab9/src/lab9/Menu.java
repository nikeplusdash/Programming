package lab9;
import java.util.Scanner;

public class Menu {
    public  static Boolean checkPalindrome(String s){
        StringBuffer str = new StringBuffer(s);
        StringBuffer rev = new StringBuffer(str.reverse());
        String r = rev.toString();
        return r.equals(s);
    }
    public static void toAlphabetical(String s) {
        StringBuffer str = new StringBuffer(s);
        for(Integer i=0;i<str.length()-1;i++) {
            for(Integer j=i+1;j<str.length();j++) {
                if(str.charAt(i) > str.charAt(j)) {
                    Character c1 = str.charAt(j);
                    Character c2 = str.charAt(i);
                    str.replace(j, j+1,c2.toString());
                    str.replace(i, i+1,c1.toString());
                }
            }
        }
        System.out.println("Alphabetical Order: " + str.toString());
    }
    public static void reverse(String s){
        StringBuffer str = new StringBuffer(s);
        System.out.println("Reverse Order: " + str.reverse().toString());
    }
    public static String concatReverse(String s){
        StringBuffer str = new StringBuffer(s);
        String rets = str.toString() + str.reverse().toString();
        System.out.println("Concat String: " + rets);
        return rets;
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String str = in.next();
        System.out.println("1:Check Palidrome\t2:Alphabetical Order\t3:Reverse\t4:Concat Reverse");
        while(true) {
            Integer x = in.nextInt();
            switch(x) {
                case 1:
                    if(checkPalindrome(str)) System.out.println(str + " - is a Palindrome");
                    else System.out.println(str + " - is not a Palindrome");
                    break;
                case 2:
                    toAlphabetical(str);
                    break;
                case 3:
                    reverse(str);
                    break;
                case 4:
                    str = concatReverse(str);
                    break;
                default:
                    break;
            }
        }
    }
}
