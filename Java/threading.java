import java.lang.*;

class threading {
    public static void main(String[] args) {
        Thread t = Thread.currentThread();
        System.out.println("Current thread: " + t);
        t.setName("Main Thread");
        try {
            for(int i=5;i>0;i--)
            {
                Thread t2 = Thread.currentThread();
                System.out.println("Current thread: " + t + t2);
                System.out.println(i);
                Thread.sleep(2000);

            }
        }
        catch (Exception e)
        {
            System.out.println("Interrupted");
        }
    }
}