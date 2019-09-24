package lab5;

import java.util.Scanner;

class Employee {
    private String name;
    private String city;
    private double salary;
    private double total;
    private double da;
    private double hr;
    
    void Display(){
        System.out.println("Employee Details:\n\nName:\t"+name+"\nCity:\t"+city+"\nSalary:\t"+salary+"\nDA:\t"+da+"\nHR:\t"+hr+"\nTotal:\t"+total);
    }
    void GetData(){
        Scanner in = new Scanner(System.in);
        System.out.println("Name: ");
        this.name = in.nextLine();
        System.out.println("City: ");
        this.city = in.nextLine();
        System.out.println("Salary: ");
        this.salary = in.nextLong();
        System.out.println("DA: ");
        this.da = in.nextDouble();
        System.out.println("HR: ");
        this.hr = in.nextDouble();
        calculate();
    }
    void calculate(){
        total = salary+salary*da/100+salary*hr/100;
    }
}
