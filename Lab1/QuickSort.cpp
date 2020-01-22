#include<iostream>
#include<chrono>

using namespace std::chrono;

int count;

int setPivot(int a[],int l,int r) {
    count++;
    int ele = a[l],x = r;
    for(int i = r;i > l;i--){
        count++;
        if(a[i] > ele) {std::swap(a[i],a[x--]);count++;}
    }
    std::swap(a[l],a[x]);count++;
    return x;
}

void QuickSort(int a[],int l,int r) {
    if(l >= r) {count++;return;}
    int pivot = setPivot(a,l,r);
    QuickSort(a,l,pivot-1);count++;
    QuickSort(a,pivot+1,r);count++;
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
    QuickSort(a,0,n);
    auto stop = high_resolution_clock::now();
    std::cout << "After Sorting: [ ";
    for(int i:a) std::cout << i << " ";
    std::cout << " ]" << std::endl;
    std::cout << "Step Count: " << count << "\nSize of Array: " << n << std::endl;
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time taken: " << duration.count() << "us" << std::endl;

}