/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab1;
import java.util.Scanner;

public class Numbers {
    public static void numbers(){
        Scanner in = new Scanner(System.in);
        int pos=0,neg=0,zer=0;
        for(int i=0;i<10;i++){
            int x = in.nextInt();
            if(x>0)
                pos++;
            else if(x<0)
                neg++;
            else
                zer++;
        }
        System.out.println("Number of Zeroes: "+ zer + "\nNumber of Positive nos.:" + pos + "\nNumber of Negative nos.:" + neg );
    }    
}
