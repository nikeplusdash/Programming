#include<iostream>
#include<math.h>

int main(){
    int trace=0,norm=0,i,j;
    std::cin >> i >> j ;
    int m[i][j];
    if(i==j){
    for(int a=0;a<i;a++)
        for(int b=0;b<j;b++)
            std::cin >> m[a][b];

    for(int a=0;a<i;a++){
        trace+=m[a][a];
        for(int b=0;b<j;b++)
            norm+=m[a][b]*m[a][b];
    }
    std::cout << "\nNorm is: " << sqrt(norm) << "\nTrace is: " << trace << std::endl;
    }
}
