#include<iostream>

#define SIZE 5
class Stack {
  private:
  int top;
  int a[SIZE];
  public:
  void push(int n);
  int pop();
  void display();
  bool isfull();
  bool isempty();
  Stack(){top=-1;}
};

void Stack::push(int n){
  if(top!=SIZE-1)  a[++top]=n;
  else std::cout << "Stack Overflow" << std::endl;
}

int Stack::pop(){
  if(top!=-1) return a[top--];
  else std::cout << "Stack Underflow" << std::endl;
}

void Stack::display(){
  for(int i=top;i>-1;i--) std::cout << "\t" << a[i] << "\n" ;
}

bool Stack::isempty(){
  return top==-1;
}

bool Stack::isfull(){
  return top==SIZE-1;
}


int main(){
  Stack s;
  s.push(5);
  s.push(10);
  s.push(11);
  s.push(79);
  s.push(0);
  s.push(4);
  s.display();
  std::cout << s.pop() << std::endl;
  std::cout << s.pop() << std::endl;
  s.display();
  std::cout << s.pop() << std::endl;
  std::cout << s.pop() << std::endl;
}