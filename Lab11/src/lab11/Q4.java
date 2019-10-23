package lab11;

import java.util.logging.Level;
import java.util.logging.Logger;

class Threads extends Thread {
    int i;
    Threads(int x){
        super("Thread "+x);i=x;
        System.out.println("Starting: "+this);
        setPriority(i);
        System.out.println("Thread "+i+" priority: "+this.getPriority());
        start();
    }
    @Override
    public void run(){
        for(int j=0;j<5;j++){
            try {
                Thread.sleep(1000);
                System.out.println("Executing thread: "+i);
            } catch (InterruptedException ex) {
                Logger.getLogger(MultiThread.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        System.out.println("Exiting: "+this);
    }
}
public class Q4 {
    public static void main(String[] args) {
        Threads t1 = new Threads(1);
        Threads t2 = new Threads(2);
        Threads t3 = new Threads(3);

        try {
            t1.join();
            t2.join();
            t3.join();
        }
        catch(InterruptedException e){
            System.out.println("Main Thread Interrupted");
        }
        System.out.println("Main Thread Ended");
    }
}
