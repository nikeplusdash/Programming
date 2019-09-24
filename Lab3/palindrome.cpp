#include<iostream>
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
    bool emp(){return n==-1;}
};

int main(){
    Stacks s;
    std::string s1,op;
    std::cin >> s1;
    for(int i=0;i<s1.length();i++)  s.push(s1[i]);
    while(!s.emp())  {op+=s.top();s.pop();}
    if(op==s1) std::cout << op << " is a palindrome" << std::endl;
    else std::cout << s1 << " is not a palindrome" << std::endl;
}
