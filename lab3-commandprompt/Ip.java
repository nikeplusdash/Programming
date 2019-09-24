public class Ip {
	public static void main(String args[]){
		int a[]={1,2,3,1,2,1,5,6,7};
		int search = Integer.parseInt(args[0]);
		int x=-1;
		for(int i:a){
			x++;
			if(i==search)	System.out.println("a["+ x + "]");
		}
	}
}