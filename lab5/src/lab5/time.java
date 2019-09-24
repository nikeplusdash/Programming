package lab5;

class time {
    private int h;
    private int m;
    private int s;
    time(){
        this.h=0;this.m=0;this.s=0;
    }
    time(int h,int m,int s){
        this.h=h;
        this.m=m;
        this.s=s;
    }
    void display(){
        System.out.printf("Time: %02d:%02d:%02d\n", h,m,s);
    }
    time add(time t1,time t2){
        time t = new time(t1.h+t2.h,t1.m+t2.m,t1.s+t2.s);
        return t;
    }
}
