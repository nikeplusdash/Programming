package lab6;

class Account {
    String customersName;
    long accNo;
    String type;
    long balance;

    public void deposit(long dep){
        this.balance+=dep;
    }
}

class CurrentAccount extends Account {
    long min;
    int taxRate;

    public void minimum(){
        if(this.balance<min){
            int serviceTax = balance*taxRate/100;
            this.balance-=serviceTax;
        }
    }
}

class SavingsAccount extends Account {
    int rate;
    public long display(){
        System.out.println(this.balance);
    }
    public void interest(int time){
        long interest = this.balance*this.rate*time/100;
        this.balance+=interest;
    }
    public void withdraw(long amount){
        this.balance-=amount;
    }
}