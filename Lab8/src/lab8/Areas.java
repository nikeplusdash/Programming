/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab8;

import java.util.Scanner;

abstract class Area {
    protected int l;
    protected int w;
    protected int r;
    abstract void area();
}

class Rect extends Area {
    Rect(int l,int w){
        this.l = l;
        this.w = w;
    }
    @Override
    void area(){
        System.out.println("Area: "+l*w);
    }
}

class Circ extends Area {
    Circ(int r){
        this.r = r;
    }
    @Override
    void area(){
        System.out.println("Area: "+3.14*r*r);
    }
}

public class Areas {
    public static void main(String [] args){
        Scanner in;
        in = new Scanner(System.in);
        Rect r;
        r = new Rect(in.nextInt(),in.nextInt());
        r.area();
        Circ c;
        c = new Circ(in.nextInt());
        c.area();
    }
}
