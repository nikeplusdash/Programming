#include<iostream>

void frequency(int a[],int n){
    int x[2][n];
    for(int i=0;i<n;i++)    {x[0][i]=a[i];x[1][i]=1;}
    for(int i=0;i<n;i++){
        if(x[1][i]==-1) continue;
        for(int j=i+1;j<n;j++){
            if(x[0][i]==x[0][j]){
                x[1][i]++;
                x[1][j]=-1;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(x[1][i]!=-1){
            std::cout << "[" << x[0][i] << "] x " << x[1][i] << std::endl;
        }
    }
}

int main(){
    int n;
    std::cin >> n;
    int a[n];
    for(int i=0;i<n;i++)    std::cin >> a[i];
    frequency(a,n);
}