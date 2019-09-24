#include<iostream>

int main(){
    int n=0,k,temp=1;
    std::cin >> n ;
    k=n;
    for (int i = 0;i < n; i++) {
        temp*=k--;
    }
    std::cout << temp << std::endl;
    return 0;
}
