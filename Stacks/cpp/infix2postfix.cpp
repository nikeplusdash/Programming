#include<iostream>
#define max 100

class stack {
    private:
    char x[max];
    int n;
    public:
    stack(){n=-1;}
    bool empty(){return n==-1;}
    bool full(){return n==max-1;}
    void push(char c){if(n!=max-1) x[++n]=c;}
    void pop(){if(n!=-1) n--;}
    char top(){return x[n];}
    void display(){for(int i=n;i>-1;i--) std::cout << "\t" << x[i] << "\n" ;}
};

int prec(char c){
    if(c=='^')  return 3;
    if(c=='*'||c=='/')  return 2;
    if(c=='+'||c=='-')  return 1;
    return 0;
}

std::string infix2postfix(std::string str){
    stack s1;
    std::string op;
    for(int i=0;i<str.length();i++){
        if(str[i]>='a'&&str[i]<='z'||str[i]>='A'&&str[i]<='Z') op+=str[i];
        else if(str[i]=='('||str[i]=='{'||str[i]=='[') s1.push(str[i]);
        else if(str[i]==')'){
            while(s1.top()!='(') {op+=s1.top();s1.pop();}
            s1.pop();
        }
        else if(str[i]=='}'){
            while(s1.top()!='{') {op+=s1.top();s1.pop();}
            s1.pop();
        }
        else if(str[i]==']'){
            while(s1.top()!='[') {op+=s1.top();s1.pop();}
            s1.pop();
        }
        else {
            if(prec(str[i])>prec(s1.top())) s1.push(str[i]);
            else {while(prec(str[i])<=prec(s1.top())){op+=s1.top();s1.pop();}s1.push(str[i]);}
        }
        //std::cout << "Working: " << i <<": " << op << std::endl;
        //s1.display();
    }
    while(!s1.empty()) {op+=s1.top();s1.pop();}
    return op;
}

int main(){
    std::string str1,str2;
    str1 = "x+y*z+(p*q+r)*s";
    str2 = infix2postfix(str1);
    std::cout << str2 << std::endl;
}