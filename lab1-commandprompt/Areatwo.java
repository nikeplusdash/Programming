import java.util.Scanner;

public class Areatwo {
	public static void main(String args[]){
		Scanner in = new Scanner(System.in);
		int l = in.nextInt(),b = in.nextInt();
		System.out.println("Area of the rectangle is "+l*b+"\nCircumference of the rectangle is "+2*(l+b));
	}
}