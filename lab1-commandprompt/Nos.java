public class Nos {
	public static void main(String args[]){
		int zer=0,pos=0,neg=0;
		for(int i=0;i<10;i++){
			int x = Integer.parseInt(args[i]);
			if(x>0)	pos++;
			else if(x<0) neg++;
			else zer++;
		}
		System.out.println("Number of Zeros: "+zer+"\nNumber of Positive Nos: "+pos+"\nNumber of Negative Nos: "+neg);
	}
}