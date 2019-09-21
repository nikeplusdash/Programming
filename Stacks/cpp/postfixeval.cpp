#include<iostream>
#include<math.h>
#define max 100

class Stacks {
    private:
    int a[max];
    int n;
    public:
    Stacks(){n=-1;}
    void push(int x){a[++n]=x;}
    void pop(){if(n!=-1)n--;}
    int top(){return a[n];}
    bool empty(){return n==-1;}
    void display(){for(int i=n;i>-1;i--) std::cout << "\t" << a[i] << "\n" ;std::cout << "\n";}
};

int posteval(std::string s){
    Stacks k;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9')  k.push(s[i]-'0');
        if(s[i]=='*'){
            // std::cout << "*" << std::endl;
            int x = k.top();
            k.pop();
            int y = k.top();
            k.pop();
            int z = x * y;
            k.push(z);
        }
        if(s[i]=='/'){
            // std::cout << "/" << std::endl;
            int x = k.top();
            k.pop();
            int y = k.top();
            k.pop();
            int z = y / x;
            k.push(z);
        }
        if(s[i]=='+'){
            // std::cout << "+" << std::endl;
            int x = k.top();
            k.pop();
            int y = k.top();
            k.pop();
            int z = x + y;
            k.push(z);
        }
        if(s[i]=='-'){
            // std::cout << "-" << std::endl;
            int x = k.top();
            k.pop();
            int y = k.top();
            k.pop();
            int z = y - x;
            k.push(z);
        }
        if(s[i]=='^'||s[i]=='$'){
            // std::cout << "^" << std::endl;
            int x = k.top();
            k.pop();
            int y = k.top();
            k.pop();
            int z = pow(y,x);
            k.push(z);
        }
        // k.display();
    }
    return k.top();
}

int main(){
    std::string s = "12$3*4-56/78+/+";
    int y = posteval(s);
    std::cout << "Answer: " << y;
}