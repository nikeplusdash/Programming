#include<iostream>
#define max 100
class Stacks {
private:
    int s[max];
    int n;
public:
    Stacks(){n=-1;}
    void push(int c){s[++n]=c;}
    void pop(){n--;}
    int top(){if(n!=-1) return s[n];}
    bool emp(){return n==-1;}
};

void Convert(int n,int k){
    Stacks s;
    std::string x;
    while(k!=0&&n!=1){
        s.push(k%n);
        k=k/n;
    }
    if(n=1){while(k!=0){s.push(1);k--;}}
    while(!s.emp()){
        x+=s.top();
        std::cout<< s.top();
        s.pop();
    }
}

int main(){
    int x = 64;
    Convert(3,9);
}
