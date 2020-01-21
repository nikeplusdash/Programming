#include<iostream>

void BubbleSort(int a[],int n) {
    if(n == 0) return;
    for(int i = 0;i < n-1;i++)
        if(a[i] > a[i+1]) std::swap(a[i],a[i+1]);
    BubbleSort(a,n-1);
}

int main() {
    int a[] = {999,9,6,96,666,69,-69,-96};
    int n = sizeof(a)/sizeof(int);
    std::cout << "Before Sorting: [ ";
    for(int i:a) std::cout << i << " ";
    std::cout << "]" << std::endl;
    BubbleSort(a,n);
    std::cout << "After Sorting: [ ";
    for(int i:a) std::cout << i << " ";
    std::cout << " ]" << std::endl;
}