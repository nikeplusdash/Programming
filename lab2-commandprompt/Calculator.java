import java.util.Scanner;

public class Calculator {
	public static void calculation(int n1,int n2,char op){
		switch(op){
			case '+':
				System.out.println("Answer = " + (n1+n2) );
				break;
			case '-':
				System.out.println("Answer = " + (n1-n2) );
				break;
			case '*':
				System.out.println("Answer = " + n1*n2 );
				break;
			case '/':
				System.out.println("Answer = " + (float)n1/n2 );
				break;
			default:
				System.out.println("Invalid operator");
		}
	}
	public static void main(String args[]){
		Scanner in = new Scanner(System.in);
		boolean more=true;
		while(more){
			System.out.print("Enter first number, operator, second number: ");
			String str = in.next();
			int num1= Character.getNumericValue(str.charAt(0));
			int num2= Character.getNumericValue(str.charAt(2));
			char op = str.charAt(1);
			calculation(num1,num2,op);
			System.out.println("Do another (y/n)?");
			char input = in.next().charAt(0);
			if(input=='y') continue;
			else more=false;
		}
	}
}