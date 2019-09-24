/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab0;

/**
 *
 * @author STUDENT
 */
public class Fibo {
    public static void fibo(int n){
        int a=0,b=1,i=0;
        while(i<n){
            int temp=b;
            System.out.print(a+"\t");
            b+=a;
            a=temp;
            i++;
        }
    }    
}
