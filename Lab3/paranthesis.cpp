#include<iostream>
#include<stdlib.h>
#define max 100

class Stacks {
private:
    char s[max];
    int n;
public:
    Stacks(){n=-1;}
    void push(char c){s[++n]=c;}
    void pop(){n--;}
    char top(){if(n!=-1) return s[n];}
    bool empty(){return n==-1;}
    void display(){std::cout<<s<<std::endl;}
};

std::string paran(std::string s){
    Stacks k;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('||s[i]=='{'||s[i]=='[') k.push(s[i]);
        if(s[i]==')')
            if(k.top()=='(')k.pop();
        if(s[i]=='}')
            if(k.top()=='{')k.pop();
        if(s[i]==']')
            if(k.top()=='[')k.pop();
    }
    if(k.empty())
        std::cout << "Paranthesis are matched" << std::endl;
    else{
        std::cout << "Paranthesis Unmatched" << std::endl;
    }
}

int main(){
    std::string s;
    std::cin >> s;
    paran(s);
}