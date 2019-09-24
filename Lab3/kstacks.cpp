#include <iostream>
#define max 100
class kStacks {
private:
    int s[max];
    int t[max];
    int b[max];
    int n;
    int siz;
public:
    kStacks(int k,int n1){
        n=n1;
        siz = n1/k;
        for(int i=0;i<k;i++){
            t[i]=siz*i;
            b[i]=siz*i;
        }
    }
    void push(int n,int k){
        k--;

        if(t[k]<(b[k]+siz)){
            s[t[k]++]=n;
            //std::cout << t[k]-1<<"--"<<s[t[k]-1]<<"--" << b[k] <<std::endl;
        }
    }
    int pop(int k){
        if(t[k-1]>b[k-1])
            return s[t[k-1]--];
    }
    void display(){
        for(int i=n/siz-1;i>-1;i--){
            std::cout << "---- Stack " << i+1 << " ----" << std::endl;
            for(int j=t[i]-1;b[i]<=j;j--){
                std::cout <<s[j] << "\n";
            }
        std::cout << "\n";
        }
    }
};

int main(){
    kStacks s(5,50);
    int k=-1;
    for(int i=1;i<=5;i++)
        for(int j=0;j<10;j++){
            s.push(++k,i);
        }
    s.pop(1);
    s.pop(1);
    s.pop(3);
    s.display();
}
