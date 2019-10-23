package lab11;

import java.util.logging.Level;
import java.util.logging.Logger;

class Threading extends Thread {
    int i;
    Threading(int x){
        super("Thread "+x);i=x;
        System.out.println("Starting: "+this);
        start();
    }
    @Override
    public void run(){
        for(int j=0;j<5;j++){
            try {
                Thread.sleep(i*1000);
                System.out.println("Executing thread: "+i);
            } catch (InterruptedException ex) {
                Logger.getLogger(MultiThread.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        System.out.println("Exiting: "+this);
    }
}

public class Q3 {
    public static void main(String[] args) {
        Threading t1 = new Threading(1);
        Threading t2 = new Threading(2);
        Threading t3 = new Threading(3);
        
        System.out.println("Thread 1 status: "+t1.isAlive());
        System.out.println("Thread 2 status: "+t2.isAlive());
        System.out.println("Thread 3 status: "+t3.isAlive());
        
        try {
            t1.join();
            t2.join();
            t3.join();
        }
        catch(InterruptedException e){
            System.out.println("Main Thread Interrupted");
        }
        
        System.out.println("Thread 1 status: "+t1.isAlive());
        System.out.println("Thread 2 status: "+t2.isAlive());
        System.out.println("Thread 3 status: "+t3.isAlive());  
        
        System.out.println("Main Thread Ended");
    }
}
