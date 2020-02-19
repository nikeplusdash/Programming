#include <iostream>

void insertionsort(int a[],int n){
    int j;
    for(int i=1;i<n;i++){
        int k=a[i];
        for(j=i-1;j>-1&&a[j]>k;j--)
            a[j+1]=a[j];
        a[j+1]=k;
    }
}

void insertionsortrecursion(int a[],int n,int i){
    if(i==n) return;
    else {
        int j,k=a[i];
        for(j=i-1;j>-1&&a[j]>k;j--)
            a[j+1]=a[j];
        a[j+1]=k;
        insertionsortrecursion(a,n,++i);
    }
}

int main(){
    int n,key,k;
    std::cin >> n;
    int a[n];
    for(int i = 0 ; i < n ; i++)    std::cin >> a[i];
    // insertionsort(a,n);
    insertionsortrecursion(a,n,1);
    for(int i = 0 ; i < n ; i++)    std::cout << a[i] << "\t";
}