#include<iostream>

void SelectionSort(int a[],int n) {
    if(n == 0) return;
    int max = n-1;
    for(int i = 0;i < n-1;i++)
        if(a[i] > a[max])   max = i;
    if(max != n-1) std::swap(a[max],a[n-1]);
    SelectionSort(a,n-1);
}

int main() {
    int a[] = {999,9,6,96,666,69,-69,-96};
    std::cout << "Before Sorting: [ ";
    for(int i:a) std::cout << i << " ";
    std::cout << "]" << std::endl;
    SelectionSort(a,8);
    std::cout << "After Sorting: [ ";
    for(int i:a) std::cout << i << " ";
    std::cout << " ]" << std::endl;
}