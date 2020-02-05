#include<iostream>
#include "../Lab2/LinkedList.cpp"

int setPivot(int a[],int l,int r) {
    int ele = a[l],x = r;
    for(int i = r;i > l;i--){
        if(a[i] > ele) {std::swap(a[i],a[x--]);}
    }
    std::swap(a[l],a[x]);
    return x;
}

void QuickSort(int a[],int l,int r) {
    if(l >= r) {return;}
    int pivot = setPivot(a,l,r);
    QuickSort(a,l,pivot-1);
    QuickSort(a,pivot+1,r);
}

int main() {
    int n,c,x,container;
    std::cin >> n >> c;
    container=c;
    int sack[n];
    LinkedLists<int> sacc;
    sacc.setName("Container: ");
    for(int &i:sack) std::cin >> i;
    QuickSort(sack,0,n);
    for(int i:sack) {
        if(c > i) {c-=i;sacc.Insert(i);}
    }
    std::cout << "Do you wanna see the containment(0/1): " << std::endl;
    std::cin >> x;
    if(x) {
        std::cout << "Capacity:" << container << "\nCapacity Left:" << c << "\n";
        
        sacc.Display();
    }
    else return 0;
}