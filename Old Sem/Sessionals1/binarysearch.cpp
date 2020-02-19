#include <iostream>

void binarysearch(int a[], int n, int key)
{
    int low = 0, high = n - 1, mid=0;
    bool found=0;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if(a[mid]<key){
            low = mid+1;
            continue;
        }
        if(a[mid]>key){
            high = mid;
            continue;
        }
        if(a[mid]==key){
            found=1;
            break;
        }
    }
    if(found)   std::cout << mid+1;
    else std::cout << "-1" ;
}

int binarysearchrecursive(int a[],int key,int low,int high){
    int mid = (low + high)/2;
    if(low>high)    return -1;
    if(a[mid]<key) binarysearchrecursive(a,key,mid+1,high);
    else if(a[mid]>key) binarysearchrecursive(a,key,low,mid-1);
    else if(a[mid]==key) return mid+1;
}

int main(){
    int n,key,k;
    std::cin >> n;
    int a[n];
    for(int i = 0 ; i < n ; i++)    std::cin >> a[i];
    std::cin >> key;
    // binarysearch(a,n,key);
    k = binarysearchrecursive(a,key,0,n);
    std::cout << k ;
}