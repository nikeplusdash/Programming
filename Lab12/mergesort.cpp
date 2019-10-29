#include <iostream>

void mergeSort(int *a,int l,int m,int r){
    int l1=m-l+1,l2=r-m;
    int aL[l1],aR[l2];
    int j=0,k=0,l0=l;
    for(int i=0;i<l1;i++) aL[i]=a[l+i];
    for(int i=0;i<l2;i++) aR[i]=a[m+i+1];
    while(j<l1&&k<l2){
        if(aL[j] > aR[k]) a[l0]=aL[j++];
        else a[l0]=aR[k++];
        l0++;
    }
    while(j<l1) a[l0++]=aL[j++];
    while(k<l2) a[l0++]=aR[k++];
}

void mergeDivide(int *a,int l,int r){
    if(l<r) {
    int m = l+((r-l)/2);
    mergeDivide(a,l,m);
    mergeDivide(a,m+1,r);
    mergeSort(a,l,m,r);
    }
}

int main(){
    int a[]= {1,2,3,4};
    mergeDivide(a,0,3);
    for(int i=0;i<4;i++) std::cout << a[i] << " ";
}
