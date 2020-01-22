#include<iostream>
#include "../Lab2/LinkedList.cpp"

// void DFS(int **a,int m,int n) {

// }

int main() {
    int m,x;
    std::cin >> m;
    int VerticeList[m];
    LinkedLists<char> VerticeMap[m];
    for(int i=0;i<m;i++) {
        std::cin >> x;
        VerticeMap[i] = new LinkedLists();
        VerticeMap[i].Insert(x);
        VerticeList[i] = x;
    }
    for(int i=0;i<m;i++) {
        std::cout << "Vertices connected to " << VerticeList[i];
        while(true) {
            std::cin >> x;
            if(x == -1) break;
            VerticeMap[i].Insert(x);
        }
    }
    for(int i=0;i<m;i++) {
        VerticeMap[i].Display();
    }
}