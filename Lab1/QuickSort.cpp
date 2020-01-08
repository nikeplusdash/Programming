#include<iostream>

int setPivot(int a[],int l,int r) {
    int ele = a[l],x = r;
    for(int i = r;i > l;i--)
        if(a[i] > ele) std::swap(a[i],a[x--]);
    std::swap(a[l],a[x]);
    return x;    
}

void QuickSort(int a[],int l,int r) {
    if(l >= r) return;
    int pivot = setPivot(a,l,r);
    QuickSort(a,l,pivot-1);
    QuickSort(a,pivot+1,r);
}

int main() {
    int a[] = {999,9,6,96,666,69,-69,-96};
    std::cout << "Before Sorting: [ ";
    for(int i:a) std::cout << i << " ";
    std::cout << "]" << std::endl;
    QuickSort(a,0,7);
    std::cout << "After Sorting: [ ";
    for(int i:a) std::cout << i << " ";
    std::cout << " ]" << std::endl;
}