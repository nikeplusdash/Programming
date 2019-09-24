public class Nested {
	public static void main(String args[]){
		int k = Integer.parseInt(args[0]);
		for(int i=1;i<=k;i++){
			for(int j=1;j<=i;j++){
				System.out.print(i);
			}
			System.out.print("\n");
		}
	}
}