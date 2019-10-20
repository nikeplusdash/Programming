/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab9;

import java.util.Scanner;

public class Replace {
    public static void replaceWords(StringBuffer s) {
        Integer x = 0;
        Character c = null;
        Integer o = 0;
        for(;x < s.length();x++){
            Integer o2 = 0;
            Character c2 = s.charAt(x);
            for(Integer i=x;i < s.length();i++) if(s.charAt(i) == c2) o2++;
            if(o2>o) {o=o2;c=c2;}
        }
        for(x=0;x < s.length();x++)s.replace(x,x+1, c.toString());
        System.out.println("String: " + s.toString());
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.next();
        StringBuffer str = new StringBuffer(s);
        replaceWords(str);
        in.close();
    }
}
