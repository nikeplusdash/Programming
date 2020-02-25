#include<iostream>
#include<chrono>

using namespace std::chrono;

int count;

void BubbleSort(int a[],int n,int j) {
    if(j == n) {count++;return;}
    for(int i = 0;i < n-1-j;i++){
        count++;
        if(a[i] > a[i+1]) {std::swap(a[i],a[i+1]);count++;}
    }
    BubbleSort(a,n,++j);count++;
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
    BubbleSort(a,n,0);
    auto stop = high_resolution_clock::now();
    std::cout << "After Sorting: [ ";
    for(int i:a) std::cout << i << " ";
    std::cout << " ]" << std::endl;
    std::cout << "Step Count: " << count << "\nSize of Array: " << n << std::endl;
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time taken: " << duration.count() << "us" << std::endl;
}