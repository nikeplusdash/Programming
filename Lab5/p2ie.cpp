#include<iostream>
#include<math.h>
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

int calculation(char c1,char c2,char op){
    if(op=='+') return c1+c2;
    if(op=='-') return c1-c2;
    if(op=='*') return c1*c2;
    if(op=='/') return c1/c2;
    if(op=='^') return pow(c1,c2);
}

int p2ie(std::string s){
    Stacks k;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9')    {int x=s[i];x-='0';k.push(x);}
        else {
            char x = k.top();k.pop();
            char y = k.top();k.pop();
            int z = calculation(y,x,s[i]);
            k.push(z);
        }
    }
    std::cout << k.top();
    return k.top();
}

int main(){
    std::string s;
    std::cin >> s;
    p2ie(s);
}