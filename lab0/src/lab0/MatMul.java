package lab0;

import java.util.Scanner;

public class MatMul {
    public static void mul(){
        Scanner in = new Scanner(System.in);
        int i,j,m,n;
        System.out.println("Enter dimensions of matrix A");
        i=in.nextInt();
        j=in.nextInt();
        System.out.println("Enter dimensions of matrix B");
        m=in.nextInt();
        n=in.nextInt();
        int a[][] = new int[i][j];
        int b[][] = new int[m][n];
        System.out.println("Enter elements of matrix A: ");
        for(int row=0;row<i;row++)
            for(int col=0;col<j;col++)
                a[row][col]=in.nextInt();
        System.out.println("Enter elements of matrix B: ");
        for(int row=0;row<i;row++)
            for(int col=0;col<j;col++)
                b[row][col]=in.nextInt();
        if(i==n){
            int c[][]= new int [i][n];
            System.out.println("Multiplied Matrix: \n");
            for(int row=0;row<i;row++){
                for(int col=0;col<n;col++){
                    c[row][col]=0;
                    for(int iter=0;iter<j;iter++)
                        c[row][col]+=a[row][iter]*b[iter][col];
                    System.out.print(c[row][col]+"\t");
                }
            System.out.print("\n");
            }
        } else {
            System.out.println("Multiplication not possible");
        }
    }
}
