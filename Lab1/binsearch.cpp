 #include<iostream>

int main(){
    int n,key;
    std::cin >> n;
    int a[n];
    std::cout << "\nEnter values:" << std::endl;
    for(int i=0;i<n;i++)    std::cin >> a[i];
    std::cout << "\nEnter key:" << std::endl;
    std::cin >> key;

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
