imort java.util.Scanner;

int main(){
    bool isMagic = true;
    int i=0,j=0,n,diag=0;
    std::cin >> i >> j ;
    int m[i+1][j+1]={0};
    for(int a=0;a<i;a++){
        for(int b=0;b<j;b++){
            std::cin >> m[a][b];
        }
    }

    if(i!=j){
        std::cout<< "Not a magic Square" <<std::endl;
        return 0;
    }

    std::cout << "\n" ;
    for(int a=0;a<i+1;a++){
                    m[i][a]=0;
                    m[a][j]=0;
        }

    std::cout << "\n";
    for(int a=0;a<i;a++){
        for(int b=0;b<j;b++){
            m[a][j]+=m[a][b];
            m[i][b]+=m[b][a];
            if(a==b){
                m[i][j]+=m[a][a];
            }
        }
        diag+=m[a][i-a];
    }
    n=m[i][j];
    for(int a=0;a<i;a++){
        if(m[i][a]!=n||m[i][a]!=diag){
            std::cout << "Not a magic square" << std::endl;
            isMagic=false;
            break;
        }
        if(m[a][j]!=n||m[a][j]!=diag){
            std::cout << "Not a magic square" << std::endl;
            isMagic=false;
            break;
        }
    }
    if(isMagic){
            std::cout << "Is a magic square" << std::endl;
    }
}
