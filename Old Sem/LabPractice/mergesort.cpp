#include <iostream>

void Merge(int a[],int l,int m,int r) {
    int iL=m-l+1,iR=r-m;
    int aL[iL],aR[iR];
    for(int i=0;i<iL;i++) aL[i]=a[l+i];
    for(int i=0;i<iR;i++) aR[i]=a[m+i+1];
    int i=0,j=0,k=l;
    while(i<iL&&j<iR) {
        if(aL[i]<aR[j]) a[k++]=aL[i++];
        else a[k++]=aR[j++];
    }
    while(i<iL) a[k++]=aL[i++];
    while(j<iR) a[k++]=aR[j++];
}

void MergeSort(int a[],int l,int r) {
    if(l>=r) return;
    int m = (r+l)/2;
    std::cout << "While Sorting: ";
    for(int i=0;i<5;i++) std::cout << a[i] << " ";
    std::cout << std::endl;
    MergeSort(a,l,m);
    MergeSort(a,m+1,r);
    Merge(a,l,m,r);
}

int main() {
    int a[] = {66,802,1,10,-8};
    std::cout << "Before Sorting: ";
    for(int i=0;i<5;i++) std::cout << a[i] << " ";
    std::cout << std::endl;
    MergeSort(a,0,4);
    std::cout << "After Sorting: ";
    for(int i=0;i<5;i++) std::cout << a[i] << " ";
    std::cout << std::endl;
}
