package lab6;

import java.util.Scanner;

class Account {
    Scanner in = new Scanner(System.in);
    String name;
    String accno;
    String acctype;
    Double balance;

    Account(){
        System.out.print("Name: ");
        name=in.nextLine();
        System.out.print("AccNo: ");
        accno=in.nextLine();
        System.out.print("AccType: ");
        acctype=in.nextLine();
        System.out.print("Balance: ");
        balance=in.nextDouble();
    }
    Account(String s){
        System.out.print("Name: ");
        name=in.nextLine();
        System.out.print("AccNo: ");
        accno=in.nextLine();
        acctype=s;
        System.out.print("Balance: ");
        balance=in.nextDouble();
    }
    void display(){System.out.println("Account Balance: "+balance);}
    void deposit(){
        System.out.print("Deposit Amount: ");
        Double money = in.nextDouble();
        this.balance+=money;
    }
    
    public static void main(String args[]){
        Scanner in = new Scanner(System.in);
        Integer x;
        System.out.println("- - - - - - - - - - - - - - W E L C O M E   T O   H A C K B A N K - - - - - - - - - - - - - \n\n");
        System.out.println("**    **        **        **********  **    **   ******          **        ***     **  **    **");
        System.out.println("**    **       ****       **********  **   **    **   **        ****       ****    **  **   **");
        System.out.println("**    **      **  **      **          **  **     **   **       **  **      ** **   **  **  **");
        System.out.println("********     ********     **          ****       ******       ********     **  **  **  ****");
        System.out.println("**    **    **********    **          **  **     **    **    **********    **   ** **  **  **");
        System.out.println("**    **   **        **   **********  **   **    **    **   **        **   **    ****  **   **");
        System.out.println("**    **  **          **  **********  **    **   *******   **          **  **     ***  **    **");
        System.out.println("\n\n- - - - - - - - - - - - - - W E L C O M E   T O   H A C K B A N K - - - - - - - - - - - - - \n\n");
        System.out.println("\n\n\nPress one of the following:\n\t1:Savings\n\t2:Current\n");
        x = in.nextInt();
        if(x==1){
            boolean more = true;
            Savings s = new Savings();
            while(more){
                System.out.println("\nPress one of the following:\n\t1:Deposit\n\t2:Withdraw\n\t3:Display\n\t4:Calculate Interest\n\t6:Exit\n");
                x = in.nextInt();
                if(x==1){
                    s.deposit();
                }
                else if(x==2){
                    s.withdraw();
                }
                else if(x==3){
                    s.display();
                }
                else if(x==4){
                    s.interest();
                }
                else {
                    more = false;
                }
            }
        } else if (x==2){
            boolean more = true;
            Current s = new Current();
            while(more){
                System.out.println("\nPress one of the following:\n\t1:Deposit\n\t2:Withdraw\n\t3:Display\n\t5:Exit");
                x = in.nextInt();
                if(x==1){
                    s.deposit();
                }
                else if(x==2){
                    s.withdraw();
                }
                else if(x==3){
                    s.display();
                }
                else {
                    more = false;
                }
            }
        } else {
            System.out.print("Thank you for visiting");
            return;
        }
    }
}

class Savings extends Account {
    Integer rate;
    Integer time;
    Savings(){
        super("Savings");
        System.out.print("Rate: ");
        rate = in.nextInt();
        System.out.print("Time: ");
        time = in.nextInt();
    }
    void interest(){
        System.out.print("Interest: "+(super.balance*rate*time*0.01)+"\n");
    }
    void withdraw(){
        System.out.print("Amount to be withdrawn: ");
        Double wd = in.nextDouble();
        if(balance-wd>0)
            super.balance-=wd;
        else
            System.out.println("- - - - - - - - Balance Insufficient - - - - - - - -");
    }
}

class Current extends Account {
    Double tax;
    Double min;
    Current(){
        super("Current");
        System.out.print("Tax: ");
        this.tax=in.nextDouble();
        System.out.print("Limit: ");
        this.min=in.nextDouble();
        if(super.balance<this.min){
            super.balance-=this.tax;
        }
    }
    void withdraw(){
        System.out.print("Amount to be withdrawn: ");
        Double wd = in.nextDouble();
        if(super.balance>this.min)  super.balance-=wd;
        if(super.balance<this.min){
            System.out.println("Limit reached and amount will be charged");
            super.balance-=this.tax;
            this.display();
        }
    }
}
