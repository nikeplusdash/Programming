#include<iostream>
#include<stdlib.h>

class stacklist {
  private:
  int data;
  stacklist* below;
  public:
  void IsEmpty();
  void push(int);
  void pop();
  void display();
  void peek();
}*pointer =NULL;

void stacklist::display(){
  stacklist* start = new stacklist();
  start = pointer;
  while(start!=NULL){
    std::cout << start->data << "\t";
    start=start->below;
  }
  std::cout << std::endl;
}

void stacklist::IsEmpty(){
  std::cout << (pointer==NULL) << std::endl;
}

void stacklist::push(int n){
  stacklist* insert = new stacklist();
  insert->data=n;
  insert->below=pointer;
  pointer=insert;
}

void stacklist::pop(){
  stacklist* top = new stacklist();
  top=pointer;
  pointer=top->below;
  std::cout << top->data << " was removed." << std::endl;
  free(top);
}

void stacklist::peek(){
  std::cout << pointer->data << " is at the top." << std::endl;
}

int main(){
  stacklist n;
  n.IsEmpty();
  n.push(5);
  n.push(8);
  n.push(1);
  n.display();
  n.peek();
  n.pop();
  n.pop();
}