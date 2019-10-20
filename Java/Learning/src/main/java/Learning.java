
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FilenameFilter;
import java.io.IOException;
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author nikep
 */
class stuff implements FilenameFilter {
    public String ext;
    public stuff(String s){
        ext = s;
    }
    @Override
    public boolean accept(File f,String name){
        return name.endsWith("."+ext);
    }
}
public class Learning {
    public static void main(String[] args) throws IOException{
        Scanner in = new Scanner(System.in);
        char a[] = {'j','a','v','a'};
        int x=6,y=32,z=40;
        String l = String.join(":",x+"",y+"",z+"");
//        int asc[] = {65,66,67,68,69};
//        byte ascii[] = {65,66,67,68,69};
        String s = new String(a);
        s = "geeksforgeeks";
        int count[] = new int[256];
//        for(int i=0;i<s.length();i++){
//            count[s.charAt(i)]++;
//        }
//        for(int i=0;i<count.length;i++){
//            if(count[i]>0&&i!=32) System.out.println((char)i+"("+i+"): "+count[i]);
//        }
//        System.out.println(s.strip());
//        System.out.println(l);
        FileReader f1 = new FileReader("C:\\Users\\nikep\\Desktop");
        File f = new File("C:\\Users\\nikep\\Desktop");
        FilenameFilter ff = new stuff("pdf");
//        FileInputStream fis = new FileInputStream(f);
        File[] p = f.listFiles(ff);
        for(File q:p){
            System.out.println(q.getName());
        }
//        System.out.println("Enter string: ");
//        String s="";
//        while(in.hasNextLine()){
//            String k =in.nextLine();
//            if(k.contains("..")) break;
//            else k+="\n";
//            s+=k;
//        }
//        String s=new String(fis.readAllBytes());
//        String[] k = s.split("a");
//        System.out.println(s.replaceAll(s.charAt(0)+"",""));
    }
}
