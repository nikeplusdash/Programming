#include <iostream>

int main(){
    char s[]="12abc",x;
    int* ptr;
    ptr = (int *)s +2;
    x=*ptr-(int)*s;
    std::cout << *ptr;
}