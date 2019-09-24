#include<iostream>
#define max 100

class Stacks {
private:
    std::string s[max];
    int n;
public:
    Stacks(){n=-1;}
    void push(std::string c){s[++n]=c;}
    void push(char c){s[++n]=c;}
    void pop(){n--;}
    std::string top(){if(n!=-1) return s[n];}
    bool emp(){return n==-1;}
};

std::string bracketify(std::string c1,std::string c2,char op){
    std::string o;
    o = '('+c2+op+c1+')';
    return o;
}

std::string p2i(std::string s){
    Stacks k;
    for(int i=0;i<s.length();i++){
        if(s[i]==' ') i++;
        else if(s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z'||s[i]>='0'&&s[i]<='9')    k.push(s[i]);
        else {
            std::string x = k.top();k.pop();
            std::string y = k.top();k.pop();
            std::string z = bracketify(x,y,s[i]);
            k.push(z);
        }
    }
    return k.top();
}

int main(){
    std::string s,o;
    std::cin >> s;
    o=p2i(s);
    std::cout << o;
}