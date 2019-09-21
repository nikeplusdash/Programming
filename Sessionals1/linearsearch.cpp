#include<iostream>

int linearsearch(int a[],int n,int key){
    int i=0;
    while(i<n&&a[i]!=key)   i++;
    if(i<n) return i+1;
    else return -1;
}

int linearsearchrecursion(int a[],int n,int key){
    if(n==0){
        return -1;
    }
    if(a[n-1]==key){
        return n;
    }
    else {
        linearsearchrecursion(a,--n,key);
    }
}

int main(){
    int n,key,k;
    std::cin >> n;
    int a[n];
    for(int i = 0 ; i < n ; i++)    std::cin >> a[i];
    std::cin >> key;
    // k = linearsearch(a,n,key);
    k = linearsearchrecursion(a,n,key);
    std::cout << k ;
}