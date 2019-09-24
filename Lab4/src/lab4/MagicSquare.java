package lab4;
import java.util.Scanner;
public class MagicSquare {
    public static void magics(){
    boolean isMagic = true;
    Scanner in = new Scanner(System.in);
    int i,j;
    System.out.println("Enter dimensions of matrix A");
    i=in.nextInt();
    j=in.nextInt();
    int a[][] = new int[i+1][j+1];
    System.out.println("Enter elements of matrix A: ");
    for(int row=0;row<i;row++)
         for(int col=0;col<j;col++)
                a[row][col]=in.nextInt();
    
    if(i!=j)    {System.out.println("Not a magic square");return;}
    int sum=0,n=0;
    boolean cont = true;
    for(int col=0;col<j;col++){ 
        sum+=a[col][col];
    }
    n=sum;
    for(int row=0;row<i;row++){ 
        sum=0;
        for(int col=0;col<j;col++)
            sum+=a[row][col];
        if(sum==n)  a[row][j]=sum;
        else cont = false;
        //System.out.println(a[row][j]);
    }
    if(!cont)    {System.out.println("Not a magic square");return;}
    for(int col=0;col<j;col++){ 
        sum=0;
        for(int row=0;row<i;row++)
            sum+=a[row][col];
        if(sum==n)  a[i][col]=sum;
        else cont = false;
        //System.out.println(a[i][col]);
    }
    if(!cont)    {System.out.println("Not a magic square");return;}
    int x=0;
    sum=0;
    for(int row=0;row<i;row++){ 
        sum+=a[row][i-row-1];
    }
    if(sum==n)  x=sum;
    else cont = false;
    //System.out.println(sum);
    if(cont)    {System.out.println("Is a magic square");}
    else    {System.out.println("Not a magic square");}
    }
}
