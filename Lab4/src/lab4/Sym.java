package lab4;
import java.util.Scanner;

public class Sym {
    public static void symmetric(){
        Scanner in = new Scanner(System.in);
        System.out.println("Enter dimensions of matrix A: ");
        int i=in.nextInt(),j=in.nextInt();
        int a[][] =  new int[i][j];
        System.out.println("Enter elements of matrix A: ");
        for(int x=0;x<i;x++)
            for(int y=0;y<j;y++)
                a[x][y]=in.nextInt();
        boolean isSym = true;
        if(i!=j) isSym=false;
        for(int x=0;x<i&&isSym;x++)
            for(int y=0;y<j&&isSym;y++)
                if(a[x][y]!=a[y][x]){isSym=false;}
        if(isSym) System.out.println("Matrix is symmetric");
        else System.out.println("Matrix is asymmetric");
    }
}
