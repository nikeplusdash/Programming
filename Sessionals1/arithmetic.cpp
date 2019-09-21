#include <iostream>

int add(int a,int b){
    if(b==0) return a;
    return add(a,--b)+1;
}

int sub(int a,int b){
    if(b==0) return a;
    return sub(a,--b)-1;
}

int mul(int a,int b){
    if(b==0) return 0;
    return a+mul(a,--b); 
}

int div(int a,int b){
    if(a<b)   return 0;
    return 1+div(a-b,b);
}

int pow(int x,int y){
    if(y==0)    return 1;
    return x*pow(x,--y);
}


int gcd(int x,int y){
    if(x==0)    return y;
    if(y==0)    return x;
    if(x==y) return x;
    if(x>y) gcd(x%y,y);
    else gcd(x,y%x);
}

int lcm(int x,int y){
    static int large = x>y?x:y;
    if(large%x==0&&large%y==0)  return large;
    large++;
    lcm(x,y);
}

int main(){
    std::cout << pow(2,10) ;
}