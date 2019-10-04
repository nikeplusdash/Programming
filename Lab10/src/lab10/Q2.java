package lab10;

import java.util.Scanner;
import java.io.*;

public class Q2 {
    public static void p(String args) {
        System.out.print(args);
    }
    public static void Read (RandomAccessFile f) throws IOException {
        Scanner in = new Scanner(System.in);
        byte [] data = new byte[(int)f.length()];
        f.read(data);
        String s = new String(data);
        p(s+"\n");
    }
    public static void Write (RandomAccessFile f) throws IOException {
        Scanner in = new Scanner(System.in);
        p("Enter string: ");
        String s = in.nextLine();
        f.seek(f.length());
        f.write(s.getBytes());
    }
    public static void main(String[] args) throws FileNotFoundException, IOException {
        Scanner in = new Scanner(System.in);
        p("1:Write\n2:Read\n");
        p("Enter Directory: ");
        String str = in.nextLine();
        p("Enter File: ");
        String strf = in.nextLine();
        RandomAccessFile f;
        int ip;
        while (true) {
            p("Enter: ");
            ip = in.nextInt();
            in.nextLine(); 
            switch(ip) {
                case 1:
                    f = new RandomAccessFile(str+"\\"+strf,"rw");
                    Write(f);
                    break;
                case 2:
                    f = new RandomAccessFile(str+"\\"+strf,"r");
                    Read(f);
                    break;
                default:
                    return;
            }
        }
    }
}
