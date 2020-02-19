#include<iostream>
#include<stdlib.h>
#define MAX 100

class Stacks {
    private:
    int a[MAX];
    int n;
    public:
    Stacks(){n=-1;}
    void push(int x){if(!full())a[++n]=x;}
    void pop(){if(!empty())--n;}
    int top(){if(!empty())return a[n];}
    bool empty(){return n==-1;}
    bool full(){return n==MAX-1;}
    void display(){for(int i=n;i>-1;i--)std::cout << a[i] << " ";std::cout << std::endl;}
};

class kStacks {
    private:
    int *a,*top,*bottom;
    int len,k,size;
    public:
    kStacks(int max,int n){
        a=(int*) calloc(max,sizeof(int));
        top=(int*) calloc(n,sizeof(int));
        bottom=(int*) calloc(n,sizeof(int));
        len = max;
        k = n;
        size = len/k;
        for(int i=0;i<k;i++){bottom[i]=size*i-1;top[i]=size*i-1;}
    }
    void push(int n,int k){
        k--;
        if(top[k]<bottom[k]+size)   a[++top[k]]=n;
    }
    void pop(int k){
        k--;
        if(top[k]>bottom[k])    top[k]--;
    }
    void display(int k){
        k--;
        std::cout << "Stack " << k+1 << "\n";
        for(int i=top[k];i>bottom[k];i--)   std::cout << a[i] << " ";
        std::cout<<std::endl;
    }
    void display(){
        for(int i=k-1;i>-1;i--){
            std::cout << "Stack " << i+1 << ":\t";
            for(int j=top[i];j>bottom[i];j--)
                std::cout << a[j] << " ";
        std::cout << std::endl;
        }
    }
};

class twostacks {
    private:
    int a[MAX];
    int n1,n2;
    public:
    twostacks(){n1=-1;n2=MAX;}
    void push(int n,int k){
        if(n2!=n1+1)    a[k==2?--n2:++n1]=n;
    }
    void pop(int k){
        if(k==2?n1!=-1:n2!=MAX)    k==2?n2++:n1--;
    }
    int top(int k){
        return k==2?a[n2]:a[n1];
    }
    void display(int k){
        for(int i=k==2?n2:n1;k==2?i<MAX:i>-1;k==2?i++:i--)    std::cout << a[i] << " ";
        std::cout << std::endl;
    }
    void display(){
        for(int i=n1;i>-1;i--)  std::cout << a[i] << " ";
        for(int i=n2;i<MAX;i++) std::cout << a[i] << " ";
        std::cout << std::endl;
    }
};

int main(){
    twostacks k;
    k.pop(1);
    k.display();
    k.push(5,1);
    k.push(6,2);
    k.push(7,2);
    k.display(1);
    k.display(2);
    k.pop(1);
    k.pop(1);
    k.display();
}