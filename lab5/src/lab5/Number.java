package lab5;

class Number {
    private double n;
    Number(double x){n=x;}
    boolean isZero(){return n==0.0;}
    boolean isPositive(){return n>0.0;}
    boolean isNegative(){return n<0.0;}
    boolean isEven(){return n%2.0==0.0;}
    boolean isOdd(){return n%2!=0.0;}
    boolean isPrime(){
        boolean prime = true;
        for(double i=2;i<n&&prime;i++){
            if(n%i==0)  prime=false;
        }
        if(n!=1) return prime;
        else return !prime;
    }
    boolean isArmstrong(){
        int num = (int)n;
        int length = 0,n=num,sum=0;
        while(n!=0){
            length++;
            n = n/10;
        }
        n=num;
        while(n!=0){
            int r = n % 10;
            n = n / 10;
            sum += Math.pow(r,length);
        }
	if(sum==num)
           return true;
	else
           return false;
    }
}
