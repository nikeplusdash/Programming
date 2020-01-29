package lab10;
import java.awt.Color;
import java.io.*;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;

public class Lab10 {
    public static void p(String args) {
        System.out.print(args);
    }
    public static void p(char args) {
        System.out.print(args);
    }
    public static void Write(File f) throws FileNotFoundException, IOException {
        Scanner in = new Scanner(System.in);
        FileOutputStream fos = new FileOutputStream(f);
        p("Enter string: ");
        String s = in.nextLine();
        for(int i=0;i<s.length();i++) fos.write((byte)s.charAt(i));
        fos.close();
    }
    public static void Read(File f) throws IOException {
        FileInputStream fis;
        try {
            fis = new FileInputStream(f);
        }
        catch(FileNotFoundException e) {
            return;
        }
        String s = "";
        byte buffer[] = new byte[fis.available()];
        int c;
        while((c = fis.read(buffer))!=-1) {s += "   "+new String(buffer);}
        p("File Data:\n" + s + "\n");
        fis.close();
    }
    public static void Copy(File f) throws IOException {
        Scanner in = new Scanner(System.in);
        FileInputStream fis;
        try {
            fis = new FileInputStream(f);
        }
        catch(FileNotFoundException e) {
            return;
        }
        p("Enter Directory to copy to: ");
        String str = in.nextLine();
        p("Enter File name: ");
        String strf = in.nextLine();
        File fcopy;
        fcopy = new File(str,strf);
        FileOutputStream fos = new FileOutputStream(fcopy);
        String s = "";
        byte buffer[] = new byte[fis.available()];
        int c;
        while((c = fis.read(buffer))!=-1) {s +=new String(buffer);}
        for(int i=0;i<s.length();i++) fos.write((byte)s.charAt(i));
        fos.close();
        fis.close();
    }
    public static void main(String[] args) throws FileNotFoundException, IOException{
        Scanner in = new Scanner(System.in);
        p("1:Write\n2:Read\n3:Copy\n");
        p("Enter Directory: ");
        String str = in.nextLine();
        p("Enter File: ");
        String strf = in.nextLine();
        File f;
        try {
            f = new File(str,strf);
        }
        catch (Exception e) {     
            p("Error Occured: "+e);
            return;
        }
        int ip;
        while (true) {
            p("Enter: ");
            ip = in.nextInt();
            in.nextLine();
            switch(ip) {
                case 1:
                    Write(f);
                    break;
                case 2:
                    Read(f);
                    break;
                case 3:
                    Copy(f);
                    break;
                default:
                    return;
            }
        }
    }
}
