#include<iostream>

int BinarySearch(int a[],int low,int high,int key) {
    int mid = (low+high)/2;
    if(low>high) return 0;
    if(a[mid] > key)  return BinarySearch(a,low,mid-1,key);
    else if(a[mid] < key) return BinarySearch(a,mid+1,high,key);
    else return 1;
}

int BinarySearch(int a[],int n,int key) {
    return BinarySearch(a,0,n,key);
}

int main() {
    int a[] = {1,2,3,4,5,6,7,8,9,0};
    std::cout << (BinarySearch(a,10,15)?"Found":"Not Found") << std::endl;
}