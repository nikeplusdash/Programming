package lab11;

import java.util.logging.Level;
import java.util.logging.Logger;

class SyncMessage {
    public void message(int msg){
        System.out.println("Table of "+msg+": ");
        try {
            for(int i=1;i<=10;i++) {
                System.out.println(msg*i);
                Thread.sleep(200);
            }
        } catch (InterruptedException ex) {
            Logger.getLogger(SyncMessage.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
class Thread5 extends Thread {
    int i;
    String msg;
    SyncMessage sm;
    Thread5(int x,String s,SyncMessage a){
        super(s);
        this.setPriority(x);
        i=x;
        sm=a;
        msg=s;
        System.out.println("Starting: "+this);
    }
    @Override
    public void run(){
        synchronized(sm){sm.message(i);}
    }
}
public class Q5 {
    public static void main(String[] args) {
        SyncMessage sm = new SyncMessage();
        Thread5 t1 = new Thread5(1,"Thread 1",sm);
        Thread5 t2 = new Thread5(2,"Thread 2",sm);
        Thread5 t3 = new Thread5(3,"Thread 3",sm);
        Thread5 t4 = new Thread5(4,"Thread 4",sm);
        Thread5 t5 = new Thread5(5,"Thread 5",sm);
        t1.start();
        t2.start();
        t3.start();
        t4.start();
        t5.start();
        try {
            t1.join();
            t2.join();
            t3.join();
            t4.join();
            t5.join();
        }
        catch(InterruptedException e){
            System.out.println("Main Thread Interrupted");
        }
//        System.out.println("Main Thread Ended");
    }
}
