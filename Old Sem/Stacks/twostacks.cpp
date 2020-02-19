#include<iostream>
#define MAX 5

class twostacks {
  private:
  int a[MAX];
  int top;
  int bottom;
  public:
  twostacks(){top=-1;bottom=MAX;}
  void push1(int n);
  void push2(int n);
  int pop1();
  int pop2();
  void display(int k);
};

void twostacks::push1(int n){
  if(top<bottom-1)  a[++top]=n;
  else std::cout << "\nStack Overflow" << std::endl;
}

void twostacks::push2(int n){
  if(top+1<bottom)  a[--bottom]=n;
  else std::cout << "\nStack Overflow" << std::endl;
}

int twostacks::pop1(){
  if(top!=-1) return a[top--];
  else std::cout << "\nStack Underflow" << std::endl;
}

int twostacks::pop2(){
  if(bottom!=MAX) return a[bottom++];
  else std::cout << "\nStack Underflow" << std::endl;
}

void twostacks::display(int k){
  for(int i=k==2?bottom:top;k==2?i<MAX:i>-1;k==2?i++:i--)    std::cout << a[i] << "\t";
  std::cout<<std::endl;
}

int main(){
  twostacks s;
  s.push1(5);
  s.push1(10);
  s.push2(11);
  s.display(1);
  s.push2(79);
  s.push2(0);
  s.push2(4);
  s.display(2);
  std::cout << s.pop2() << std::endl;
  std::cout << s.pop2() << std::endl;
  s.display(2);
  std::cout << s.pop1() << std::endl;
  s.push2(79);
  s.push1(0);
  s.push1(4);
  s.display(1);
  std::cout << s.pop2() << std::endl;
  s.display(2);
}