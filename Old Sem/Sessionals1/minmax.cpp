#include<iostream>

int findmax(int a[],int n){
    static int max = a[n-1];
    int r = a[n-1];
    if(r>max)   max=r;
    if(n==0) return max;
    findmax(a,n-1);
}

int findmin(int a[],int n){
    static int min = a[n-1];
    int r = a[n-1];
    if(r<min)   min=r;
    if(n==0) return min;
    findmin(a,n-1);
}

int main(){
    int a[]={1,49,0,5,6,-2};
    std::cout << findmin(a,6);
}