package lab4;
import java.util.Scanner;

public class Mul {
    public static void sop(String args) {
        System.out.println(args);
    }
    public static void sopp(String args) {
        System.out.print(args);
    }
    public static void mul(){
        Scanner in = new Scanner(System.in);
        int i,j,m,n;
        sop("Enter dimensions of matrix A");
        i=in.nextInt();
        j=in.nextInt();
        sop("Enter dimensions of matrix B");
        m=in.nextInt();
        n=in.nextInt();
        int a[][] = new int[i][j];
        int b[][] = new int[m][n];
        sop("Enter elements of matrix A: ");
        for(int row=0;row<i;row++)
            for(int col=0;col<j;col++)
                a[row][col]=in.nextInt();
        sop("Enter elements of matrix B: ");
        for(int row=0;row<m;row++)
            for(int col=0;col<n;col++)
                b[row][col]=in.nextInt();
        if(j==m){
            int c[][]= new int [i][n];
            sop("Multiplied Matrix: \n");
            for(int row=0;row<i;row++){
                for(int col=0;col<n;col++){
                    c[row][col]=0;
                    for(int iter=0;iter<j;iter++)
                        c[row][col]+=a[row][iter]*b[iter][col];
                    sopp(c[row][col]+"\t");
                }
            sopp("\n");
            }
        } else {
            sop("Multiplication not possible");
        }
        if(i==m&&j==n){
            sop("Added Matrix: \n");
            for(int row=0;row<i;row++){
                for(int col=0;col<n;col++){
                    sopp(a[row][col]+b[row][col]+"\t");
                }
            sopp("\n");
            }
        } else {
            sop("Addition not possible");
        }
    }
}
