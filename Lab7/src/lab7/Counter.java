package lab7;

import java.util.Scanner;

public class Counter {
    static int counter;
    static {
        counter = 0;
    }
    Counter(){
        counter++;
    }
    void count(){
        System.out.println("Number of objects: " + counter);
    }
}
