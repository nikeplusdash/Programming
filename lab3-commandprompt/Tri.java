public class Tri {
	public static void main(String args[]){
		int size = Integer.parseInt(args[0]);
		int arr[][],d=0;
		arr = new int[size][];
		for(int i=0;i<arr.length;i++)	arr[i]=new int[i+1];
		for(int i=0;i<arr.length;i++)
			for(int j=0;j<arr[i].length;j++)
				arr[i][j]=++d;
		for(int i[]	:arr){
			for(int j:i)
				System.out.print(j+" ");
			System.out.print("\n");
		}
	}
}