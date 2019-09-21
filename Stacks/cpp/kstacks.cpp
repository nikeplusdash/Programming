#include<iostream>
#include<stdlib.h>

class kstacks{
  private:
  int* a;
  int* top;
  int* bottom;
  int size;
  int m;
  public:
  void push(int,int);
  int pop(int);
  void display(int);
  void display();
  kstacks(int,int);
};

kstacks::kstacks(int max,int k){
  a = (int*) malloc(sizeof(int)*max);
  top = (int*) malloc(sizeof(int)*k);
  bottom = (int*) malloc(sizeof(int)*k);
  size = (int) (max/k);
  m=max;
  for(int i=0; i<k ; i++){
    top[i]=size*i-1;
    bottom[i]=size*i-1;
  }
}

void kstacks::push(int k,int n){
  k--;
  if(top[k]<(bottom[k]+size))  a[++top[k]]=n;
  else std::cout << "Stack Overflow" << std::endl;
}

int kstacks::pop(int k){
  k--;
  if(top[k]!=bottom[k])   return a[top[k]--];
  else std::cout << "Stack Underflow" << std::endl;
}

void kstacks::display(int k){
  k--;
  for(int i=top[k];i>bottom[k];i--) std::cout << a[i] <<std::endl;
}

void kstacks::display(){
  for(int i=m/size-1;i>-1;i--){
    std::cout << "--Stack " << i+1 <<"--" <<std::endl;
    for(int j=top[i];j>bottom[i];j--)
      std::cout << a[j] << std::endl;
  }
}

int main(){
  kstacks s(50,5);
  int d=-1;
  for(int i=1;i<6;i++)
    for(int j=0;j<10;j++)
      s.push(i,++d);
  s.display();
  s.pop(1);
  s.pop(5);s.pop(5);s.pop(5);s.pop(5);s.pop(5);s.pop(5);
  s.display();
}