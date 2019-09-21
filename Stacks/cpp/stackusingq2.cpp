#include<iostream>
#include<bits\stdc++.h>

class stacksusinq {
    private:
    std::queue <int> q;
    public:
    void push(int n){
        int len = q.size();
        q.push(n);
        for(int i=0;i<len;i++){
            int x = q.front();
            q.pop();
            q.push(x);
        }
    }
    void pop(){
        q.pop();
    }
    int peek(){
        q.front();
    }
    void display(std::queue <int> a){
        std::cout<<"\nStack: "<<std::endl;
        while(!a.empty()){
            std::cout<<a.front()<<std::endl;
            a.pop();
        }
    }
    void display(){
        display(q);
    }
};

int main(){
    stacksusinq q;
    q.push(5);
    q.push(2);
    q.push(69);
    q.display();
    q.pop();
    q.display();
}