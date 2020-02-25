#include<iostream>
#include<cstdio>
#include<chrono>

using namespace std::chrono;

int count;

void Merge(int a[],int l,int u,int r) {
    int iL = u-l+1,iR = r-u,aL[iL],aR[iR],i,j,k;
    for(i = 0;i < iL; i++) {count++;aL[i] = a[l+i];}
    for(i = 0;i < iR; i++) {count++;aR[i] = a[u+i+1];}
    i = j = 0;k = l; count++;
    while(i < iL && j < iR) {
        if(aL[i] > aR[j]) a[k++] = aR[j++];
        else a[k++] = aL[i++];
        count++;
    }
    while(i<iL) {count++;a[k++]=aL[i++];}
    while(j<iR) {count++;a[k++]=aR[j++];}
}

void MergeSort(int a[],int l,int r) {
    if(l >= r) {count++;return;}
    int u = (l+r)/2;count++;
    // std::cout << "During Sorting(m): [ ";
    // for(int i=0;i<8;i++) std::cout << a[i] << " ";
    // std::cout << " ]" << std::endl;
    MergeSort(a,l,u);count++;
    MergeSort(a,u+1,r);count++;
    Merge(a,l,u,r);count++;
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
    MergeSort(a,0,n);
    auto stop = high_resolution_clock::now();
    std::cout << "After Sorting: [ ";
    for(int i:a) std::cout << i << " ";
    std::cout << " ]" << std::endl;
    std::cout << "Step Count: " << count << "\nSize of Array: " << n << std::endl;
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time taken: " << duration.count() << "us" << std::endl;
}