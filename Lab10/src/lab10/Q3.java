package lab10;

import java.util.Scanner;
import java.io.*;

public class Q3 {
    public static void p(String args) {
        System.out.print(args);
    }
    public static void main(String[] args) throws IOException{
        Scanner in = new Scanner(System.in);
        p("Enter file location: ");
        File f = new File(in.nextLine());
        Scanner reader = new Scanner(f);
        int lines=0,words=0,characters=0,vowels=0;
        while(reader.hasNextLine()) {
            String s = reader.nextLine();
            String[] k = s.split(" ");
            for(String i:k) {
                characters += i.length();
                String vow = "aeiouAEIOU";
                for(int j=0;j<i.length();j++) if(vow.indexOf(i.charAt(j))!=-1) vowels++;
            }
            lines += 1;
            words += k.length;
            characters += k.length-1;
        }
        p("Lines: "+lines+"\nWords: "+words+"\nChars: "+characters+"\nVowels: "+vowels+"\n");
    }
}
