#include<iostream>
#include<chrono>

using namespace std::chrono;

int count;

void InsertionSort(int a[],int n,int i) {
    if(i >= n) {count++;return;}
    int j = 0,k = a[i];
    for(j=i-1;j>-1&&a[j]>k;j--)
        {a[j+1]=a[j];count++;}
    a[j+1]=k;count++;
    InsertionSort(a,n,++i);count++;
}

void InsertionSort(int a[],int n) {
    InsertionSort(a,n,1);
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
    InsertionSort(a,n);
    auto stop = high_resolution_clock::now();
    std::cout << "After Sorting: [ ";
    for(int i:a) std::cout << i << " ";
    std::cout << " ]" << std::endl;
    std::cout << "Step Count: " << count << "\nSize of Array: " << n << std::endl;
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time taken: " << duration.count() << "us" << std::endl;
}