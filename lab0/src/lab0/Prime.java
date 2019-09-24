package lab0;

public class Prime {
    public static void prime(int n){
        int prime=1,count=0;
        for(int i=2;count<n;i++){
            prime=1;
            for(int j=2;j<i;j++){
                if(i%j==0){
                    prime = 0;
                    break;
                }              
            }
            if(prime==1){
                System.out.print(i+"\t");
                count++;
            }
        }
    }
    

}
