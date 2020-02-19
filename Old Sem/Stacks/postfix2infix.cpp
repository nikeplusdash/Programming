#include <iostream>
#define MAX 100

class Stacks {
    private:
    std::string a[MAX];
    int n;
    public:
    Stacks(){n=-1;}
    void push(std::string s){a[++n]=s;}
    void push(char s){a[++n]=s;}
    std::string top(){if(n!=-1) return a[n];}
    void pop(){if(n!=-1)n--;}
    void display(){for(int i=n;i>-1;i--) std::cout << "\t" << a[i] << "\n" ;}
};

std::string brancketify(std::string s1,std::string s2, char op){
    return "("+s1+op+s2+")";
}

std::string postfix2infix(std::string s){
    Stacks k;
    for(int i=0;i<s.length();i++){
        if(s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z')  k.push(s[i]);
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='^'||s[i]=='$') {
            std::string x,y,z;
            y = k.top();k.pop();
            x = k.top();k.pop();
            z = brancketify(x,y,s[i]);
            k.push(z);
        }
    }
    return k.top();
}

int main(){
    std::string a = "abcd-e^*+";
    std::cout << postfix2infix(a) << std::endl;
}