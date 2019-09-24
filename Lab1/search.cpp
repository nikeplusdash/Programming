#include<iostream>

int linearSearch(int a[],int n,int key){
    for(int i=0;i<n;i++)
        if(a[i]==key){
            std::cout << key << " found at " << i+1 << " position using linear search" << std::endl;
            return 0;
        }
    std::cout << "Not found" << std::endl;
}

int binarySearch(int a[],int n,int key){
    int low=0,high=n-1,mid=0;
    while(low<=high){
        mid=(low+high)/2;
        if(a[mid]==key){
            std::cout << key << " found at " << mid+1 << " position using binary search" << std::endl;
            return 0;
        }
        if(a[mid]<key)
            low=mid+1;
        if(a[mid]>key)
            high=mid-1;
    }
    std::cout << "Not found" << std::endl;
}

int binarySearchRecursion(int a[],int n,int low,int high,int key){
    int mid=(low+high)/2;
    if(a[mid]==key){
        std::cout << key << " found at " << mid+1 << " position using binary search recursion" << std::endl;
        return 0;
    }
    if(a[mid]<key)
        binarySearchRecursion(a,n,mid+1,high,key);
    if(a[mid]>key)
        binarySearchRecursion(a,n,low,mid-1,key);
    std::cout << "Not found" << std::endl;
}

int swap(int a[],int j,int k){
    int temp=a[k];
    a[k]=a[j];
    a[j]=temp;
}

int bubbleSortAscending(int a[],int n){
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j]>a[j+1]) swap(a,j,j+1);
    for(int i=0;i<n;i++)    std::cout << a[i] << "\t" ;
    std::cout << "\n";
}

int bubbleSortDescending(int a[],int n){
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j]<a[j+1]) swap(a,j,j+1);
    for(int i=0;i<n;i++)    std::cout << a[i] << "\t" ;
    std::cout << "\n";
}

int selectionSortAscending(int a[],int n){
    int min=0;
    for(int i=0;i<n-1;i++){
        min=i;
        for(int j=i+1;j<n;j++)
            if(a[min]>a[j]) min=j;
        if(min!=i) swap(a,min,i);
    }
    for(int i=0;i<n;i++)    std::cout << a[i] << "\t" ;
    std::cout << "\n";
}

int selectionSortDescending(int a[],int n){
    int max=0;
    for(int i=0;i<n-1;i++){
        max=i;
        for(int j=i+1;j<n;j++)
            if(a[max]<a[j]) max=j;
        if(max!=i) swap(a,max,i);
    }
    for(int i=0;i<n;i++)    std::cout << a[i] << "\t" ;
    std::cout << "\n";
}

int selectionRecursion(int a[],int n){

}

int insertionSortAscending(int a[],int n){
    int num=0,i=0,j=0;
    for(int i=0;i<n-1;i++){
        j=i+1;
        num=a[j];
        while(num<a[j-1]&&j>0){
            a[j]=a[j-1];
            j--;
        }
        a[j]=num;
    }
    for(int k=0;k<n;k++)    std::cout << a[k] << "\t";
    std::cout << "\n";
}

int insertionSortDescending(int a[],int n){
    int num=0,i=0,j=0;
    for(int i=0;i<n-1;i++){
        j=i+1;
        num=a[j];
        while(num>a[j-1]&&j>0){
            a[j]=a[j-1];
            j--;
        }
        a[j]=num;
    }
    for(int k=0;k<n;k++)    std::cout << a[k] << "\t";
    std::cout << "\n";
}

int main(){
    int n,key;
    std::cin >> n;
    int a[n];
    std::cout << "Enter values:" << std::endl;
    for(int i=0;i<n;i++)    std::cin >> a[i];
    insertionSortAscending(a,n);


    std::cout << "Enter key:" << std::endl;
    std::cin >> key;
    binarySearchRecursion(a,n,0,n-1,key);
    //linearSearch(a,n,key);
    //binarySearch(a,n,key);
}
