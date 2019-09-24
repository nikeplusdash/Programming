public class IsLeap {
	public static void main(String args[]){
		int x = Integer.parseInt(args[0]);
		boolean isLeap=true;
		isLeap = x%4==0?x%100==0?x%400==0?false:true:true:false;
		if(isLeap) System.out.println(x+" is a leap year");
		else System.out.println(x+" is not a leap year");
	}
}