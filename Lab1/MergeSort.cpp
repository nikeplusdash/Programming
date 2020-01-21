#include<iostream>

void Merge(int a[],int l,int u,int r) {
    int iL = u-l+1,iR = r-u,aL[iL],aR[iR],i,j,k;
    for(i = 0;i < iL; i++) aL[i] = a[l+i];
    for(i = 0;i < iR; i++) aR[i] = a[u+i+1];
    i = j = 0;k = l;
    while(i < iL && j < iR) {
        if(aL[i] > aR[j]) a[k++] = aR[j++];
        else a[k++] = aL[i++];
    }
    while(i<iL) a[k++]=aL[i++];
    while(j<iR) a[k++]=aR[j++];
}

void MergeSort(int a[],int l,int r) {
    if(l >= r) return;
    int u = (l+r)/2;
    std::cout << "During Sorting(m): [ ";
    for(int i=0;i<8;i++) std::cout << a[i] << " ";
    std::cout << " ]" << std::endl;
    MergeSort(a,l,u);
    MergeSort(a,u+1,r);
    Merge(a,l,u,r);
}

int main() {
    int a[] = {999,9,6,96,666,69,-69,-96};
    int n = sizeof(a)/sizeof(int);
    std::cout << "Before Sorting: [ ";
    for(int i:a) std::cout << i << " ";
    std::cout << "]" << std::endl;
    MergeSort(a,0,n);
    std::cout << "After Sorting: [ ";
    for(int i:a) std::cout << i << " ";
    std::cout << " ]" << std::endl;
}