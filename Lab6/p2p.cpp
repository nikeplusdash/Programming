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

std::string convertify(std::string c1,std::string c2,char op){
    std::string o;
    o = c1+c2+op;
    return o;
}

std::string p2i(std::string s){
    Stacks k;
    for(int i=s.length()-1;i>-1;i--){
        if(s[i]==' ') i++;
        else if(s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z'||s[i]>='0'&&s[i]<='9')    k.push(s[i]);
        else {
            std::string x = k.top();k.pop();
            std::string y = k.top();k.pop();
            std::string z = convertify(x,y,s[i]);
            k.push(z);
        }
    }
    return k.top();
}

int main(){
    std::string s,o;
    std::cin >> s;
    o = p2i(s);
    // o=p2i("++ab*cd");
    std::cout << o;
}