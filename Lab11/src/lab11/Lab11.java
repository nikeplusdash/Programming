package lab11;

import java.util.Scanner;

class RunnableThread implements Runnable {
    Thread t;
    RunnableThread(){
        t = new Thread(this);
        System.out.println("Starting Runnable thread");
        t.start();   
    }
    @Override
    public void run() {
        for(int i=0;i<5;i++)
        System.out.println("Running Runnable Thread");
        System.out.println("Exiting Runnable Thread");
    }
}

class ExtendedThread extends Thread {
    ExtendedThread(){
        System.out.println("Starting Extended Thread");
    }
    @Override
    public void start(){
       for(int i=0;i<5;i++)
        System.out.println("Running Extended Thread");
       System.out.println("Exiting Extended Thread");
    }
}

public class Lab11 {
    public static void main(String[] args) {
        int ip;
        Scanner in = new Scanner(System.in);
        System.out.println("1:Runnable 2:Extended\n");
        while(true){
            ip = in.nextInt();
            switch(ip) {
                case 1:
                    RunnableThread rt = new RunnableThread();
                    break;
                case 2:
                    ExtendedThread et = new ExtendedThread();
                    et.start();
                    break;
                default:
                    return;
            }
        }
    }
}
