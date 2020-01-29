#include <iostream>

class X {
    public:
    int x;
    char c;
    X(){}
    X(char a,int b){x=b;c=a;}
};

int main(){
    X* a[4];
    a[0] = new X('a',1);
    a[1] = new X('b',2);
    a[2] = new X('c',3);
    a[3] = new X('d',4);
    for(auto *z:a){
        std::cout << z->x << " " << z->c << "\n";
    }
    int *i;
    i = new int[100];
    i[0]=0;
    //W o w
}