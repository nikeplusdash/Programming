#include<iostream>
#include<chrono>

using namespace std::chrono;

int count;

int BinarySearch(int a[],int low,int high,int key) {
    int mid = (low+high)/2;count++;
    if(low>high) {count++;return 0;}
    if(a[mid] > key)  {count++;return BinarySearch(a,low,mid-1,key);}
    else if(a[mid] < key) {count++;return BinarySearch(a,mid+1,high,key);}
    else {count++;return 1;}
}

int BinarySearch(int a[],int n,int key) {   
    return BinarySearch(a,0,n,key);
}

int main() {
    // int a[] = {1,2,3,4,5,6,7,8,9,0};
    // int n = sizeof(a)/sizeof(int);
    int n;
    std::cin >> n;
    int a[n];
    int k = a[3000];
    for(int i=0;i<n;i++) std::cin >> a[i];
    auto start = high_resolution_clock::now();
    std::cout << (BinarySearch(a,n,k)?"Found":"Not Found") << std::endl;
    auto stop = high_resolution_clock::now();
    std::cout << "Step Count: " << count << "\nSize of Array: " << n << std::endl;
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time taken: " << duration.count() << "us" << std::endl;
}