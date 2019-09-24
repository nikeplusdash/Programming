#include<iostream>


int main(){
    int i=0,j=0,p=0,q=0;
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
    for(int a=0;a<i;a++){
            for(int b=0;b<q;b++){
                    std::cout << m[a][b] << " ";
                }
            std::cout << "\n" ;
        }
    std::cout << "\n" ;
    for(int a=0;a<i;a++){
            for(int b=0;b<q;b++){
                    std::cout << n[a][b] << " ";
            }
            std::cout << "\n" ;
        }

    //Multiplication
    std::cout << "\n" ;
    std::cout << "\n" ;
    if(j==p){
        int o[i][q];
        std::cout << "Multiplication :" <<std::endl;
        for(int a=0;a<i;a++){
            for(int b=0;b<q;b++){
                o[a][b]=0;
                for(int c=0;c<j;c++){
                    o[a][b] = o[a][b] + m[a][c]*n[c][b];
                }
            }
        }
        for(int a=0;a<i;a++){
            for(int b=0;b<q;b++){
                    std::cout << o[a][b] << " ";
            }
            std::cout << "\n" ;
        }

    } else {
        std::cout << "Multiplication not possible" << std::endl;
    }

    //Addition
    std::cout << "\n" ;
    if(i==p&&j==q){
            std::cout << "Addition :" <<std::endl;
        for(int a=0;a<i;a++){
            for(int b=0;b<j;b++){
                std::cout << m[a][b]+n[a][b]<< " ";
            }
            std::cout << "\n" ;
        }

    } else {
        std::cout << "Addition not possible" << std::endl;
    }

    //Subtraction
    std::cout << "\n" ;
    if(i==p&&j==q){
            std::cout << "Subtraction :" <<std::endl;
        for(int a=0;a<i;a++){
            for(int b=0;b<j;b++){
                std::cout << m[a][b]-n[a][b]<< " ";
            }
            std::cout << "\n" ;
        }

    } else {
        std::cout << "Subtraction not possible" << std::endl;
    }
}
