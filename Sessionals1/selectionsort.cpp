#include <iostream>

void swap(int a[],int i,int j){
    int temp = a[i];
    a[i]=a[j];
    a[j]=temp;
    return;
}

void selectionsort(int a[],int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for (int j=i+1;j<n;j++)
            if(a[j]<a[min])    min=j;
        if(i!=min)  swap(a,i,min);
    }
}

void selectionsortrecursion(int a[],int n){
    if(n==0)    return;
    else {
        int max=n-1;
        for(int i=n-2;i>-1;i--) if(a[i]>a[max]) max=i;
        swap(a,max,n-1);
        selectionsortrecursion(a,--n);
    }
}

int main(){
    int n,key,k;
    std::cin >> n;
    int a[n];
    for(int i = 0 ; i < n ; i++)    std::cin >> a[i];
    selectionsortrecursion(a,n);
    for(int i = 0 ; i < n ; i++)    std::cout << a[i] << "\t";
}