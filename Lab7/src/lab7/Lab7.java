package lab7;

public class Lab7 {
    public static void main(String[] args) {
        // Student_Detail s = new Student_Detail();
        // s.display_details();
        Counter c1 = new Counter();
        Counter c2 = new Counter();
        Counter c3 = new Counter();
        Counter c4;
        c1.count();
        // c2.count();
        // c3.count();
        int a = 0;
        Integer x = new Integer(a); //Boxing
        Integer y =3;    //AutoUnboxing
        int b = x;  //Unboxing
        System.out.println(a + " " + b + " " + x);
    }
}
