#include <iostream>
#include <stdlib.h>

class dynastack {
  private:
  int *a;
  int n;
  public:
  void push(int x);
  int pop();
  void display();
  dynastack(){n=-1;a = (int*) malloc(n * sizeof(int));}
};

void dynastack::push(int x){
  a = (int*) realloc(a,++n * sizeof(int));
  a[n] = x;
}

void dynastack::display(){
  for(int i=0;i<=n;i++)  std::cout << a[i] << "\t";
  std::cout<<std::endl;
}

int dynastack::pop(){
  int num = a[n];
  a = (int*) realloc(a,--n * sizeof(int));
  return num;
}

int main(){
  dynastack s;
  s.push(2);
  s.push(29);
  s.push(6);
  std::cout << s.pop() << std::endl;
  s.display();
}