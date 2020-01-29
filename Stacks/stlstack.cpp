#include<iostream>
#include<stack>

void showstack(std::stack<int> n){
  while(!n.empty()){
    std::cout << n.top() << std::endl;
    n.pop();
  }
}

int main(){
  std::stack<int> s;
  s.push(1);
  s.push(2);
  s.push(6);
  showstack(s);
  s.pop();
  showstack(s);
}