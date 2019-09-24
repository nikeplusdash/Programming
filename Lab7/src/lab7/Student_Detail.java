      package lab7;

import java.util.Scanner;
import java.util.concurrent.TimeUnit;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Student_Detail {
    static String college_name;
    String name;
    String id;
    Student_Detail(){
        Scanner in = new Scanner (System.in);
        name = in.nextLine();
        id = in.nextLine();
    }
    static {
        college_name= "MIT";
    }
    public void display_details(){
        try {
            System.out.print("Name: "+name);
            TimeUnit.SECONDS.sleep(3);
            System.out.print("\rCollege: "+college_name);
            TimeUnit.SECONDS.sleep(3);
            System.out.print("\rId: "+id);
            TimeUnit.SECONDS.sleep(3);
            System.out.print("\rClosing Display in 3s");
            TimeUnit.SECONDS.sleep(3);
        } catch (InterruptedException ex) {
            Logger.getLogger(Student_Detail.class.getName()).log(Level.SEVERE, null, ex);
        }
        
    }
}
