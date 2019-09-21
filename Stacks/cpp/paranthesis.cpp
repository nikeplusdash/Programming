#include<iostream>
#include<stdlib.h>
#define max 100
class Stack {
    private:
    char *a;
    int n;
    public:
    Stacks(){n=-1;a=(char*) malloc(n*sizeof(char));}
    void push(char x){a = (char*) realloc(a,++n*sizeof(char));a[n]=x;}
    void pop(){a = (char*) realloc(a,--n*sizeof(char));}
    char top(){return a[n];}
    bool empty(){return n==-1;}
    void display(){std::cout<<"----- Stack -----" <<std::endl;for(int i=n;i>-1;i--)std::cout<<"\t"<<a[i]<<std::endl;}
};

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
    void display(){for(int i=0;i<=n;i++)std::cout<<s[i]<<std::endl;}
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
    k.display();
    if(k.empty())
        std::cout << "Paranthesis are matched" << std::endl;
    else{
        std::cout << "Paranthesis Unmatched" << std::endl;
    }
}

int main(){
    std::string s;
    s = "({a}[bc(d)][e]{f}())";
    paran(s);
}