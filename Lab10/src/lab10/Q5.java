package lab10;

import java.util.Scanner;
import java.io.*;

class Student implements Serializable{
    public String name;
    public char grade;
    public float percent;
    public float total;
    @Override
    public String toString(){
        return "Name: "+name+"\n\tTotal:"+total+"\n\tGrade: "+grade+"\n\tPercentage: "+percent+"%\n";
    }
}
public class Q5 {
    public static Student init1(){
        Scanner in = new Scanner(System.in);
        Student s = new Student();
        float total=0;
        p("Enter name: ");
        s.name = in.nextLine();
        for(int i=0;i<5;i++) {p("Enter marks out of 10: ");total+=in.nextInt();}
        s.total = total;
        s.percent = 0;
        s.grade = 0;
        return s;
    }
    public static Student init2(Student s){
        s.percent = s.total*2;
        s.grade = s.total>40?'A':s.total>30?'B':s.total>20?'C':'F';
        return s;
    }
    public static void p(String args) {
        System.out.print(args);
    }
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        Scanner in = new Scanner(System.in);
        p("Enter file location: ");
        File f = new File(in.nextLine());
        ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(f));
        p("Number of Students: ");
        int x = in.nextInt();
        for(int i=0;i<x;i++){
            Student s = init1();
            oos.writeObject(s);
        }
        oos.close();
        oos = new ObjectOutputStream(new FileOutputStream(f));
        ObjectInputStream ois = new ObjectInputStream(new FileInputStream(f));
        while(--x != -1){
            Student s = (Student)ois.readObject();
            s = init2(s);
            p(s.toString()+"\n");
            oos.writeObject(s);
        }
    }
}
