package lab10;
import java.io.*;
import java.util.Scanner;

public class Q4 {
    public static void p(String args) {
        System.out.print(args);
    }
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        p("Enter File Location: ");
        File f = new File(in.nextLine());
        FileOutputStream fos = new FileOutputStream(f);
        p("Enter String: ");
        String s = in.nextLine();
        char[] y = s.toCharArray();
        for(int i=0;i<s.length();i++) {if(y[i]==' ') continue;else if(y[i]=='z'){y[i]='a';continue;}y[i]+=1;}
        fos.write(new String(y).getBytes());
        fos.close();
        FileInputStream fis = new FileInputStream(f);
        byte[] b = new byte[fis.available()];
        fis.read(b);
        char[] x = new String(b).toCharArray();
        for(int i=0;i<x.length;i++) {if(x[i]==' ') continue;if(x[i]=='a'){x[i]='z';continue;}x[i]-=1;}
        p(new String(x)+"\n");
        fis.close();
    }
}
