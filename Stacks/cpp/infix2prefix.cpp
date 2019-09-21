#include<iostream>
#define MAX 100

class Stacks {
    private:
    char a[MAX];
    int n;
    public:
    Stacks(){n=-1;}
    void push(char c){a[++n]=c;}
    char top(){return a[n];}
    void pop(){if(n!=-1) n--;}
    bool empty(){return n==-1;}
};

int precedence(char c){
    if(c=='^'||c=='$') return 3;
    if(c=='*'||c=='/') return 2;
    if(c=='+'||c=='-') return 1;
    return -1;
}

std::string infix2prefix(std::string s){
    Stacks k;
    std::string op,oprev;
    for(int i=s.length()-1;i>-1;i--){
        if(s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z')  op+=s[i];
        else if(s[i]==')')   k.push(s[i]);
        else if(s[i]=='('){
            while(k.top()!=')'){op+=k.top();k.pop();}
            k.pop();
        }
        else {
            if(precedence(s[i])>=precedence(k.top()))   k.push(s[i]);
            else {
                while(precedence(s[i])<precedence(k.top())) {op+=k.top();k.pop();}
                k.push(s[i]);
            }
        }
    }
    while(!k.empty()) {op+=k.top();k.pop();}
    for(int i=op.length()-1;i>-1;i--) oprev+=op[i];
    return oprev;
}

int main(){
    std::string s = "(A-B/C)*(A/K-L)";
    std::cout << infix2prefix(s) << std::endl;
}