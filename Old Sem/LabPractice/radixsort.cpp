#include <iostream>
#include <bits\stdc++.h>

void RadixSort(int a[],int n) {
    std::queue<int> s[10];
    int max=a[0],digits=0,mul=1;
    for(int i=1;i<n;i++) if(a[i]>max) max=a[i];
    for(int i=0;max!=0;i++) {max/=10;digits++;}
    for(int i=0;i<digits;i++) {
        for(int i=0;i<n;i++) {
            int dig = (a[i]%(10*mul))/(1*mul);
            // std::cout << "Digit: " << dig << std::endl;
            s[dig].push(a[i]);
        }
        int d=-1;
        for(int i=0;i<10;i++) while(!s[i].empty()) {a[++d]=s[i].front();s[i].pop();}
        mul*=10;
        std::cout << "While Sorting: ";
        for(int i=0;i<5;i++) std::cout << a[i] << " ";
        std::cout << std::endl;
    }
}

int main() {
    int a[] = {66,802,1,10,2};
    std::cout << "Before Sorting: ";
    for(int i=0;i<5;i++) std::cout << a[i] << " ";
    std::cout << std::endl;
    RadixSort(a,5);
    std::cout << "After Sorting: ";
    for(int i=0;i<5;i++) std::cout << a[i] << " ";
    std::cout << std::endl;
}
