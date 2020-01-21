#include<iostream>

int LinearSearch(int a[],int n,int key) {
    if(n < 1) return 0;
    if(a[n-1] == key) return 1;
    LinearSearch(a,n-1,key);
}

int main() {
    int a[] = {1,2,3,4,5,6,7,8,9,0};
    int n = sizeof(a)/sizeof(int);
    std::cout << (LinearSearch(a,n,10)?"Found":"Not Found") << std::endl;
}