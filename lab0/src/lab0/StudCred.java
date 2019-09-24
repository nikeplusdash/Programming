package lab0;
import java.util.Scanner;

public class StudCred {

    Scanner in = new Scanner(System.in);
    String studName= "";
    String regNo = "";
    int marks1=0,marks2=0,marks3=0;
    
    public StudCred(String name,String no){
        studName = name;
        regNo = no;
    }
    
    public void marks(){
        System.out.println("Enter marks of " + studName + " out of 10");
        marks1=in.nextInt();
        marks2=in.nextInt();
        marks3=in.nextInt();
    }
    
    public void pf(){
        int sum = marks1+marks2+marks3;
        if(sum>10){
            System.out.println("Student "+studName+" has passed with "+sum+" marks");
        } else {
            System.out.println("Student"+studName+" has failed");
        }
    }
    
    public static void stud(){
        int x=1;

        StudCred def = new StudCred("Nikesh","180911202");
        def.marks();
        StudCred stud1 = new StudCred("Burhan","180911109");
        stud1.marks();
        stud1.pf();
        def.pf();      
    }
}
