import java.util.Scanner;

public class Convert {
	public static void main(String args[]){
		Scanner in = new Scanner(System.in);
		int i = in.nextInt();
		int x1 = 0,x2 = 0;
		byte b1 = 0,b2=0;
		double d = in.nextDouble();
		char c = in.next().charAt(0);
		b1 = (byte)i;
		x1 = c;
		b2 = (byte)d;
		x2 = (int)d;
		System.out.println(b1 + "\t" + x1 + "\t" +b2 + "\t" +x2 + "\t" );
	}
}