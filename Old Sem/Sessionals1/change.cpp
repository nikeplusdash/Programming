#include<iostream>
#include<stdlib.h>

void minimize(int money[]){
    // Money format [2000,500,200,100,50,20,10,5,2,1
    int changes[] = {10,5,2,1};
    if(money[9]>1){money[8]+=money[9]%2;money[9]%=2;}
}

void change(int cash){
    int changes[] = {2000,500,200,100,50,20,10,5,2,1};
    int* money = (int*) calloc(10,sizeof(int));
    for(int i=0;i<10;i++){
        if(cash>=changes[i]&&changes[i]!=-1){
            int x = cash / changes[i];
            money[i]=x;
            cash-=x*changes[i];
        }
        else continue;
    }
    for(int i=9;i>-1;i--){
        if(money[i]!=0) std::cout << "[ " << changes[i] << " ] x " <<  money[i] << "\n";
    }
}

int main(){
    int cash;
    while(1){
        std::cin>>cash;
        if(cash==0) exit(0);
        change(cash);
    }
}