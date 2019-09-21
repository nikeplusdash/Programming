#include<iostream>

int fibonaccin(int n){
    if(n==1) return 0;
    if(n==2) return 1;
    return fibonaccin(n-1)+fibonaccin(n-2);
}

int fibonacci(int n){
    static int a = 0;
    static int b = 1;
    int x = 0;
    if(n==0) exit(0);
    std::cout << a << " ";
    x = a;a = b;b += x;
    fibonacci(--n);
}

int main(){
    std:: cout << fibonacci(10) << std::endl;
}