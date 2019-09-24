#include<iostream>

int main(){
    bool found = false;
    int x,n;
    std::cin >> n;
    int a[n];
    for(int i=0; i<n ; i++)
        std::cin >> a[i];
    std::cout << "\nNumber to be searched: ";
    std::cin >> x;
    int low=0,high=n-1,mid=0;
    for(int i=0;i<n-1;i++){
        mid=(low+high)/2;
        if(x<a[mid])
            high=mid;
        if(x>a[mid])
            low=mid;
        if(x==a[mid]){
            found = true;
        }
    }
    if(found)
        std::cout << "Number found" << std::endl;
    else
        std::cout << "Number not found" << std::endl;
}
