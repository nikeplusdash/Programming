package lab11;

import java.io.*;
import java.util.Scanner;

public class Lab11 {
    public static void main(String[] args) throws IOException{
        int ip;
        Scanner in = new Scanner(System.in);
        File f = new File("C:\\Users\\nikep\\Downloads\\unsplash.jpg");
        FileInputStream fis = new FileInputStream(f);
        byte[] b = new byte[fis.available()];
        fis.read(b);
        String s="";
        int i=0;
//        for(byte c:b) s+= c+" "+(++i%10==0?"\n":"");
        System.out.println(s);
    }
}
