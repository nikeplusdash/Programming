package lab5;

class Box {
    private double l,w,h;
    Box(){l=1;w=1;h=1;}
    Box(double s){
        l=s;w=s;h=s;
    }
    Box(double l,double w,double h){
        this.l=l;
        this.w=w;
        this.h=h;
    }
    double volume(){
        return l*w*h;
    }
}
