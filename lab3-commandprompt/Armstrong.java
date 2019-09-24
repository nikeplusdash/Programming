public class Armstrong {
    public static void main(String args[]){
        int num = Integer.parseInt(args[0]);
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
			System.out.println("Is an Armstrong number");
		else
			System.out.println("Is not an Armstrong Number");
    }
}