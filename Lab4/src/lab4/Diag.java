package lab4;
import java.util.Scanner;

public class Diag {
    public static void diag(){
        Scanner in = new Scanner(System.in);
        int i,j,sum = 0;
        System.out.println("Enter dimensions of matrix A: ");
        i=in.nextInt();
        j=in.nextInt();
        int a[][] = new int[i][j];
        System.out.println("Enter elements of matrix A: ");
        for(int row=0;row<i;row++)
            for(int col=0;col<j;col++)
                a[row][col]=in.nextInt();
        System.out.println("Diagonal elements of matrix A: ");
        for(int row=0;row<i;row++){
            for(int col=0;col<j;col++)
                if(row==col){    
                    sum+=a[row][col];
                    System.out.print(a[row][col]+"\t");
                }
                else 
                    System.out.print("\t");
            System.out.print("\n");
        }
        System.out.println("Sum of diag elements: " + sum);
    }
}
