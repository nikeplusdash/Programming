#include<iostream>
#include<chrono>

using namespace std::chrono;

int count;

int LinearSearch(int a[],int n,int key) {
    if(n < 1) {count++;return 0;}
    if(a[n-1] == key) {count++;return 1;}
    LinearSearch(a,n-1,key);count++;
}

int main() {
    int n;
    std::cin >> n;
    int a[n];
    for(int i=0;i<n;i++) std::cin >> a[i];
    int k = a[4250];
    auto start = high_resolution_clock::now();
    std::cout << (LinearSearch(a,n,k)?"Found":"Not Found") << std::endl;
    auto stop = high_resolution_clock::now();
    std::cout << "Step Count: " << count << "\nSize of Array: " << n << std::endl;
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time taken: " << duration.count() << "us" << std::endl;
}