#include<iostream>
#include<stdlib.h>
#include<bits\stdc++.h>
/*
class stacks{
  private:
  int* a;
  int top;
  public:
  stacks(){top=-1;a=(int*) malloc(top*sizeof(int));}
  void push(int n){
    a = (int*) realloc(a,++top*sizeof(int));
    a[top]=n;
  }
  int pop(){
    int x = a[top];
    a = (int*) realloc(a,--top*sizeof(int));
    return x;
  }
  void display(){
    for(int i=0;i<=top;i++)  std::cout << a[i] << "\t";
    std::cout<<std::endl;
  }
  bool empty(){
    return top==-1;
  }
};
*/
class qusingstacks {
  private:
  std::stack<int> s1,s2;
  public:
  void enqueue(int n){
    if(s1.empty())  {s1.push(n);return;}
    while(!s1.empty()) {s2.push(s1.top());s1.pop();}
    s1.push(n);
    while(!s2.empty()) {s1.push(s2.top());s2.pop();}
  }
  void dequeue(){
    if(!s1.empty()) {std::cout<<s1.top()<<std::endl;s1.pop();}
    else std::cout<<"Queue is empty"<<std::endl;
  }
};

int main(){
  qusingstacks q;
  q.enqueue(5);
  q.enqueue(7);
  q.enqueue(69);
  q.enqueue(5);
  q.dequeue();
  q.dequeue();
  q.dequeue();
  q.dequeue();
  q.dequeue();
}