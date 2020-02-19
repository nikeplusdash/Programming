#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
/*
class Stack {
    private:
        int *a;
        int top;
    public:
        Stack(){top=-1;a=(int*) malloc(top*sizeof(int));}
        void push(int n){a = (int*) realloc(a,++top*sizeof(int));a[top]=n;}
        int pop(){int x = a[top];a = (int*) realloc(a,--top*sizeof(int));std::cout << x << " was popped." << std::endl;return x;}
        void display(){for(int i=top;i>-1;i--)  std::cout << a[i] << std::endl;}
        bool empty(){return top==-1;}
        int top(){return a[top];}
};
*/
class Stackminmax {
    private:
    std::stack <int> s1;
    std::stack <int> mini;
    std::stack <int> maxi;
    public:
    void push(int n);
    void pop();
    void min();
    void max();
    void display(std::stack <int> a);
    void disp();
};

void Stackminmax::push(int n){
    s1.push(n);
    if(mini.empty()){mini.push(n);maxi.push(n);return;}
    if(mini.top()>n) mini.push(n);
    else mini.push(mini.top());
    if(maxi.top()<n) maxi.push(n);
    else maxi.push(maxi.top());
}

void Stackminmax::pop(){
    int x;
    if(!s1.empty())   {x=s1.top();s1.pop();}
    while(mini.top()==x&&!mini.empty())   mini.pop();
    while(maxi.top()==x&&!maxi.empty())   maxi.pop();
}

void Stackminmax::min(){    
    if(!mini.empty()){int x = mini.top();std::cout << x << " is the minimum." << std::endl;}
}

void Stackminmax::max(){
    if(!maxi.empty()){int x = maxi.top();std::cout << x << " is the maximum." << std::endl;}
}

void Stackminmax::display(std::stack <int> a){
    while(!a.empty()){std::cout << a.top() << std::endl;a.pop();}
    std::cout<<std::endl;
}

void Stackminmax::disp(){
    std::cout << "\nStack : " <<std::endl;
    Stackminmax::display(s1);
    std::cout << "\nStack min : " <<std::endl;
    Stackminmax::display(mini);
    std::cout << "\nStack max : " <<std::endl;
    Stackminmax::display(maxi);
}

int main(){
    Stackminmax s;
    s.push(5);
    s.push(10);
    s.push(1);
    s.push(99);
    s.push(0);
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.disp();
    s.pop();
    s.max();
    s.min();
    s.disp();
}