#include <iostream>

void swap(int a[],int i,int j) {
    int k=a[i];
    a[i]=a[j];
    a[j]=k;
}

int pivotSet(int a[],int l,int r) {
    int x = r;
    int pivot_ele = a[l];
    for(int j=r;j>l;j--) if(a[j]>pivot_ele) swap(a,j,x--);
    swap(a,l,x);
    return x;
}

void QuickSort(int a[],int l,int r) {
    if(l>=r) return;
    int pivot = pivotSet(a,l,r);
    std::cout << "While Sorting: ";
    for(int i=0;i<5;i++) std::cout << a[i] << " ";
    std::cout << std::endl;
    QuickSort(a,l,pivot-1);
    QuickSort(a,pivot+1,r);
}

int main() {
    int a[] = {66,802,1,10,-8};
    std::cout << "Before Sorting: ";
    for(int i=0;i<5;i++) std::cout << a[i] << " ";
    std::cout << std::endl;
    QuickSort(a,0,4);
    std::cout << "After Sorting: ";
    for(int i=0;i<5;i++) std::cout << a[i] << " ";
    std::cout << std::endl;
}
