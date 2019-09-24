package lab8;

import java.util.Scanner;

interface ar {
    abstract void area();
}

class Rectangle implements ar {
    Integer l;
    Integer w;
    Rectangle(Integer l,Integer w){
        this.l = l;
        this.w = w;
    }
    @Override
    public void area(){
        System.out.println("Area: "+l*w);
    }
}

class Circle implements ar {
    Integer r;
    Circle(Integer r){
        this.r = r;
    }
    @Override
    public void area(){
        System.out.println("Area: "+3.14*r*r);
    }
}

public class AreaI {
    public static void main(String [] args){
        Scanner in;
        in = new Scanner(System.in);
        Rectangle r;
        r = new Rectangle(in.nextInt(),in.nextInt());
        r.area();
        Circle c;
        c = new Circle(in.nextInt());
        c.area();
        in.close();
    }
}
