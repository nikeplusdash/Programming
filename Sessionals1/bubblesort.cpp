#include <iostream>

void swap(int a[],int i,int j){
    int temp = a[i];
    a[i]=a[j];
    a[j]=temp;
    return;
}

void bubblesort(int a[],int n){
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j]>a[j+1])
                swap(a,j,j+1);
}

void bubblesortrecursion(int a[],int n){
    if(n==0) return;
    else {
        for(int i=0;i<n-1;i++)  if(a[n-1]<a[i]) swap(a,i,n-1);
        bubblesortrecursion(a,n-1);
    }
}

int main(){
    int n,key,k;
    std::cin >> n;
    int a[n];
    for(int i = 0 ; i < n ; i++)    std::cin >> a[i];
    bubblesortrecursion(a,n);
    for(int i = 0 ; i < n ; i++)    std::cout << a[i] << "\t";
}