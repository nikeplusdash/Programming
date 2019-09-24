#include<iostream>

int main(){
    int n,key;
    std::cin >> n;
    int a[n];
    std::cout << "\nEnter values:" << std::endl;
    for(int i=0;i<n;i++)    std::cin >> a[i];
    std::cout << "\nEnter key:" << std::endl;
    std::cin >> key;

    for(int i=0;i<n;i++)
        if(a[i]==key){
            std::cout << key << " found at " << i+1 << " position using linear search" << std::endl;
            return 0;
        }
    std::cout << "Not found" << std::endl;

}
