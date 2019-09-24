#include<iostream>
#define MAX 100

class Stacks {
private:
    char s[MAX];
    int n;
public:
    Stacks(){n=-1;}
    void push(char c){s[++n]=c;}
    void pop(){n--;}
    char top(){if(n!=-1) return s[n];else return 0;}
    bool empty(){return n==-1;}
};

int precedence(char c){
    if(c=='+'||c=='-')  return 1;
    if(c=='*'||c=='/')  return 2;
    if(c=='$'||c=='^')  return 3;
    return 0;
}

std::string i2p(std::string s){
    std::string op,f;
    Stacks k;
    for(int i=s.length()-1;i>-1;i--){
        if(s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z'||s[i]>='0'&&s[i]<='9')  {op+=s[i];}
        else if(s[i]=='(')  k.push(s[i]);
        else if(s[i]==')')  {
            while(k.top()!='('){op+=k.top();k.pop();}
            k.pop();
        }
        else {
            if(precedence(s[i])>=precedence(k.top())) k.push(s[i]);
            else {
                while(precedence(s[i])<precedence(k.top())){op+=k.top();k.pop();}
                k.push(s[i]);
            }
        }
    }
    while(!k.empty()){op+=k.top();k.pop();}
    for(int i=op.length()-1;i>-1;i--)f+=op[i];
    return f;
}

int main(){
    std::string s,op;
    std::cin >> s;
    op = i2p(s);
    // op = i2p("a+b+c*d");
    std::cout << op;
}