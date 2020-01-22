#include<iostream>
#include<chrono>

using namespace std::chrono;

int count;

void SelectionSort(int a[],int n) {
    if(n == 0) {count++;return;}
    int max = n-1;
    for(int i = 0;i < n-1;i++) {
        count++;
        if(a[i] > a[max]) max = i;
    }
    if(max != n-1) {std::swap(a[max],a[n-1]);count++;}
    SelectionSort(a,n-1);count++;
}

int main() {
    int n;
    std::cin >> n;
    int a[n];
    for(int i=0;i<n;i++) std::cin >> a[i];
    std::cout << "Before Sorting: [ ";
    for(int i:a) std::cout << i << " ";
    std::cout << "]" << std::endl;
    auto start = high_resolution_clock::now();
    SelectionSort(a,n);
    auto stop = high_resolution_clock::now();
    std::cout << "After Sorting: [ ";
    for(int i:a) std::cout << i << " ";
    std::cout << " ]" << std::endl;
    std::cout << "Step Count: " << count << "\nSize of Array: " << n << std::endl;
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time taken: " << duration.count() << "us" << std::endl;
}