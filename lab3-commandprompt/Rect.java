public class Rect {
	public static void main(String args[]){
		int length=Integer.parseInt(args[0]);
		int width=Integer.parseInt(args[1]);
		System.out.println("Area of the rectangle: " + (length*width) + "\nPerimeter of the rectangle: " + 2*(length+width));
	}
}