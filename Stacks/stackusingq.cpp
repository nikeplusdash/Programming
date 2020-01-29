#include<bits/stdc++.h>
#include<iostream>

class stackusingq {
    private:
    std::queue <int>q1;
    std::queue <int>q2;
    public:
    void push(int);
    void pop();
    int top();
};

void stackusingq::push(int n){
    if(q1.empty()){q1.push(n);return;}
    while(!q1.empty())  {q2.push(q1.front());q1.pop();}
    q1.push(n);
    while(!q2.empty())  {q1.push(q2.front());q2.pop();}
}

void stackusingq::pop(){
    std::cout << q1.front() << " was popped out" << std::endl;
    q1.pop();
}

int stackusingq::top(){
    std::cout << q1.front() << " is at the top." << std::endl;
}

int main(){
    stackusingq s;
    s.push(5);
    s.push(9);
    s.push(10);
    s.pop();
    s.top();
    s.pop();
    s.pop();
}