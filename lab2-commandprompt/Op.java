public class Op {
	public static void a(){
		int x =10;
		double y = x;
		System.out.println(y);
	}
	/*
	public static void b(){
		double x = 10.5;
		int y = x;
		System.out.println(y);
	}
	*/
	//gives error
	public static void c(){
		double x=10.5;
		int y = (int) x;
		System.out.println(y);
	}
	public static void main(String args[]){
		a();
		//b();
		c();
	}
}
