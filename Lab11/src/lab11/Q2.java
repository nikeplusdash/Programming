package lab11;

import java.util.logging.Level;
import java.util.logging.Logger;

class MultiThread extends Thread {
    int i;
    MultiThread(int x){
        super("Thread "+x);i=x;
        System.out.println("Starting: "+this);
        start();
    }
    @Override
    public void run(){
        for(int j=0;j<5;j++){
            try {
                Thread.sleep(i*1000);
            } catch (InterruptedException ex) {
                Logger.getLogger(MultiThread.class.getName()).log(Level.SEVERE, null, ex);
            }
            System.out.println("Executing thread: "+i);
        }
        System.out.println("Exiting thread "+i);
    }
}

public class Q2 {
    public static void main(String[] args) {
        MultiThread t1 = new MultiThread(1);
        MultiThread t2 = new MultiThread(2);
        MultiThread t3 = new MultiThread(3);
    }
}
