#include<iostream>

int main(){
    int a=0,b=1,n=0,temp=0;
    std::cin >> n ;
    for(int i=0;i<n;i++){
        std::cout << a << "\t";
        temp = b;
        b = a + b;
        a = temp;
    }
    return 0;
}
