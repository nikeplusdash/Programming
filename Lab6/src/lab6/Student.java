package lab6;

import java.util.Scanner;

class Student {
    Scanner in = new Scanner(System.in);
    String name;
    String regNo;
    String age;
    
    Student(){
        System.out.print("Name: ");
        name = in.nextLine();
        System.out.print("Age: ");
        age = in.nextLine();
        System.out.print("RegNo: ");
        regNo = in.nextLine();
    }        
}

class UG extends Student {
    String semester;
    String fees;
    String subjects[];
    UG(){
        super();
        System.out.print("Semester: ");
        semester = in.next();
        System.out.print("Fees: ");
        fees = in.next();
        System.out.print("No. of subjects: ");
        int n = in.nextInt();
        subjects = new String[n];
        for(int i = 0; i < n; i++){
            subjects[i] = in.next();
        }
    }
    void display (){
        System.out.print("\nName: "+name+"\nRegistration Number: "+regNo+"\nAge: "+age+"\nSemester: "+semester+"\nFees: "+fees+"\nSubjects: ");
        for(String i:subjects)
            System.out.print(i+" ");
    }
}

class PG extends Student {
    String semester;
    String fees;
    String subjects[];
    PG(){
        super();
        System.out.print("No. of subjects: ");
        int n = in.nextInt();
        subjects = new String[n];
        for(int i = 0; i < n; i++){
            subjects[i] = in.nextLine();
        }
    }
    void display (){
        System.out.print("\nName: "+name+"\nRegistration Number: "+regNo+"\nAge: "+age+"\nSemester: "+semester+"\nFees: "+fees+"\nSubjects: ");
        for(String i:subjects)
            System.out.print(i+" ");
    }
}
