package lab11;

import java.io.*;
import java.util.logging.Level;
import java.util.logging.Logger;

class Runnable1 implements Runnable {
    @Override
    public void run(){
        System.out.println("Starting thread: "+ this);
        String s="";
        int a=0,b=1;
        while(a<10000){
            s+=a+" \n";
            int i=b;b=a+b;a=i;
        }
        System.out.println("Fibonacci.txt is being written");
        File f = new File("C:\\Users\\STUDENT\\Desktop\\Fibonacci.txt");
        try {
            FileOutputStream fos = new FileOutputStream(f);
            fos.write(s.getBytes());
        } catch (IOException ex) {
            Logger.getLogger(Runnable1.class.getName()).log(Level.SEVERE, null, ex);
        }
        System.out.println("Fibonacci.txt was written");
    }
    
}

class Runnable2 implements Runnable {
    @Override
    public void run(){
        System.out.println("Starting thread: "+ this);
        String s="";
        int a=2;
        while(a<10000){
            boolean isPrime = true;
            int b=2;
            while(b<a/2){
                if(a%b==0) isPrime = false;
                b++;
            }
            if(isPrime) s+=a+" \n";
            a++;
        }
        System.out.println("Prime.txt is being written");
        File f = new File("C:\\Users\\STUDENT\\Desktop\\Primes.txt");
        try {
            FileOutputStream fos = new FileOutputStream(f);
            fos.write(s.getBytes());
        } catch (IOException ex) {
            Logger.getLogger(Runnable1.class.getName()).log(Level.SEVERE, null, ex);
        }
        System.out.println("Prime.txt was written");
    }
}

class Runnable3 implements Runnable {
    @Override
    public void run(){
        File f1 = new File("C:\\Users\\STUDENT\\Desktop\\Primes.txt");
        File f2 = new File("C:\\Users\\STUDENT\\Desktop\\Fibonacci.txt");
        try {
            FileInputStream fis1 = new FileInputStream(f1);
            FileInputStream fis2 = new FileInputStream(f2);
            byte[] b1 = new byte[fis1.available()];
            byte[] b2 = new byte[fis2.available()];
            fis1.read(b1);fis2.read(b2);
            String s1 = new String(b1),s2 = new String(b2);
            String[] k = s1.split(" \n");
            for(String i:k){
                if(s2.contains(i)) System.out.print(i+" ");
            }
            System.out.print("\n");
        } catch (IOException ex) {
            Logger.getLogger(Runnable3.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}

public class Wait {
    public static void main(String[] args) throws InterruptedException {
        System.out.println("Starting threads");
        Thread t1 = new Thread(new Runnable1());
        Thread t2 = new Thread(new Runnable2());
        t1.start();
        t2.start();
        t1.join();
        t2.join();
        Thread t3 = new Thread(new Runnable3());
        System.out.print("Displaying common terms: ");
        t3.start();
       
    }
}
