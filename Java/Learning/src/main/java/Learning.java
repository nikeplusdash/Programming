import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FilenameFilter;
import java.io.IOException;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

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
    public static void main(String[] args) throws ArrayIndexOutOfBoundsException{
        Scanner in = new Scanner(System.in);
//        char a[] = {'j','a','v','a'};
//        int x=6,y=32,z=40;
//        try {
//            System.out.println("Inside try1");
//            try {
//                System.out.println("Inside try2");
//                return;
//                
//            }
//            catch(NumberFormatException e){
//                System.out.println("e: "+e);
//                System.out.println("Exiting catch2");
//            }
//            finally {
//                System.out.println("Exiting finally2");
//                throw new ArithmeticException();
//            }
//            //System.out.println("Exiting try1");
//        }
//        catch(ArithmeticException e){
//            System.out.println("e: "+e);
//            return;
//        }
//        finally {
//            System.out.println("Exiting finally1");
//        }
//        String l = String.join(":",x+"",y+"",z+"");
//        int asc[] = {65,66,67,68,69};
//        byte ascii[] = {65,66,67,68,69};
//        String s = new String(a);
//        s = "geeksforgeeks";
//        int count[] = new int[256];
//        for(int i=0;i<s.length();i++){
//            count[s.charAt(i)]++;
//        }
//        for(int i=0;i<count.length;i++){
//            if(count[i]>0&&i!=32) System.out.println((char)i+"("+i+"): "+count[i]);
//        }
//        System.out.println(s.strip());
//        System.out.println(l);
//        FileReader f1 = new FileReader("C:\\Users\\nikep\\Desktop");
//        File f = new File("C:\\Users\\nikep\\Desktop");
//        FilenameFilter ff = new stuff("pdf");
//        FileInputStream fis = new FileInputStream(f);
//        File[] p = f.listFiles(ff);
//        for(File q:p){
//            System.out.println(q.getName());
//        }
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
        String[] ok = {"hi","hello","okay","hi","hello","hello"};
        ArrayList<String> list = new ArrayList<String>();
        ArrayList<Integer> count = new ArrayList<Integer>();
        for(String s:ok){
            if(!list.contains(s)) {list.add(s);count.add(1);}
            else {int i=list.indexOf(s);count.set(i,count.get(i)+1);
//            System.out.println("---"+count.get(i)+"---"+s);
            }
        }
        for(String s:list){
            System.out.println(s+":"+count.get(list.indexOf(s)));
        }
    }
}
