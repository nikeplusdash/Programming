package lab4;
import java.util.Scanner;

public class NonDiag {
    public static void sopln(String args) {
        System.out.println(args);
    }
    public static void sop(String args) {
        System.out.print(args);
    }
    public static void nondiag(){
        Scanner in = new Scanner(System.in);
        int i,j,sum = 0;
        sopln("Enter dimensions of matrix A: ");
        i=in.nextInt();
        j=in.nextInt();
        int a[][] = new int[i][j];
        sopln("Enter elements of matrix A: ");
        for(int row=0;row<i;row++)
            for(int col=0;col<j;col++)
                a[row][col]=in.nextInt();
        sopln("Non-Diagonal elements of matrix A: ");
        for(int row=0;row<i;row++){
            for(int col=0;col<j;col++)
                if(row!=col&&row!=(i-col-1)){    
                    sum+=a[row][col];
                    sop(a[row][col]+"\t");
                }
                else 
                    sop("\t");
            sop("\n");
        }
        sopln("Sum of non-diag elements: " + sum);
    }
}
