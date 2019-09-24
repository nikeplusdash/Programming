public class Prime {
	public static void main(String args[]){
		int low = Integer.parseInt(args[0]);
		int high = Integer.parseInt(args[1]);
		int c=0;
		for(int i = low;i<=high;i++){
			boolean isPrime=true;
			for(int j=2;j<i;j++)
				if(i%j==0)	{isPrime=false;break;}
			if(isPrime&&i!=1) System.out.println(++c+") "+i);
		}
	}
}