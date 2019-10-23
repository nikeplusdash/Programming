import java.util.logging.Level;
import java.util.logging.Logger;

class SyncMessage {
    public void message(String msg){
        System.out.println(msg);
        try {
            Thread.sleep(1000);
        } catch (InterruptedException ex) {
            Logger.getLogger(SyncMessage.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
class Thread5 extends Thread {
    int i;
    String msg;
    SyncMessage sm;
    Thread5(int x,String s,SyncMessage sm){
        super("Thread "+x);i=x;
        this.sm = sm;
        msg=s;
        System.out.println("Starting: "+this);
    }
    @Override
    public void run(){
        synchronized(sm){
            sm.message(msg);
        }
    }
}
public class Q5B {
    public static void main(String[] args) {
        SyncMessage sm = new SyncMessage();
        Thread5 t1 = new Thread5(1,"Hi",sm);
        Thread5 t2 = new Thread5(2,"How",sm);
        Thread5 t3 = new Thread5(3,"are",sm);
        Thread5 t4 = new Thread5(4,"you",sm);
        Thread5 t5 = new Thread5(5,"?",sm);
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
