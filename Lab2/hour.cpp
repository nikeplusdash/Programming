#include<iostream>

using namespace std;
class time {
    private:
    int h;
    int m;
    int s;
    public:
    void init();
    void display();
    void add(time t1,time t2);
    void diff(time t1,time t2);
};

void time::init(){
    cout << "Enter hours: ";
    cin >> h;
    cout << "Enter min: ";
    cin >> m;
    cout << "Enter sec: ";
    cin >> s;
}

void time::display(){
    cout << h << ":" << m << ":" << s << endl;
}

void time::add(time t1,time t2){
    h=t1.h+t2.h;
    m=t1.m+t2.m;
    s=t1.s+t2.s;
}

void time::diff(time t1,time t2){
    h=t1.h-t2.h;
    m=t1.m-t2.m;
    s=t1.s-t2.s;
}

int main(){
    time t1;
    t1.init();
    time t2;
    t2.init();
    time t;
    t1.display();
    t2.display();
    t.add(t1,t2);
    t.display();
    t.diff(t1,t2);
    t.display();
}
