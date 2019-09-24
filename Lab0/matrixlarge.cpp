#include<iostream>

int main(){
    int i=0,j=0,p=0,q=0,max=0;
    std::cin >> i >> j ;
    int m[i][j];
    for(int a=0;a<i;a++){
        for(int b=0;b<j;b++){
            std::cin >> m[a][b];
        }
    }
    std::cout << "\n";
    std::cin >> p >> q ;
    int n[p][q];
    for(int a=0;a<p;a++){
        for(int b=0;b<q;b++){
            std::cin >> n[a][b];
        }
    }
    std::cout << "\n" ;
    for(int a=0;a<i;a++)
        for(int b=0;b<j;b++)
            if(max<m[a][b]) max=m[a][b];
    for(int a=0;a<p;a++)
        for(int b=0;b<q;b++)
            if(max<n[a][b]) max=n[a][b];
    std::cout << max << " is the max" << std::endl;
}
