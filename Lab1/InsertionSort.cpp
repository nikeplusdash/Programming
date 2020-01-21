#include<iostream>

void InsertionSort(int a[],int n,int i) {
    if(i >= n) return;  
    int j = 0,k = a[i];
    for(j=i-1;j>-1&&a[j]>k;j--)
        a[j+1]=a[j];
    a[j+1]=k;
    InsertionSort(a,n,++i);
}

void InsertionSort(int a[],int n) {
    InsertionSort(a,n,1);
}

int main() {
    int a[] = {8,9,4,2,1,0,10,1};
    int n = sizeof(a)/sizeof(int);
    std::cout << "Before Sorting: [ ";
    for(int i:a) std::cout << i << " ";
    std::cout << "]" << std::endl;
    InsertionSort(a,n);
    std::cout << "After Sorting: [ ";
    for(int i:a) std::cout << i << " ";
    std::cout << " ]" << std::endl;
}