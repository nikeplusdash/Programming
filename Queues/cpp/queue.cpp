#include<iostream>
#define MAX 5
class Queue {
  private:
  int n[MAX];
  int last;
  public:
  Queue(){last=-1;}
  void enqueue (int);
  void dequeue ();
  void display ();
};


void Queue::enqueue(int a){
  if(last==MAX-1)  {std::cout << "Queue Overflow" << std::endl;return;}
  int x = last;
  while(x>=0){
    n[x+1]=n[x];
    x--;
  }
  n[0]= a;
  last++;
}

void Queue::dequeue(){
  if(last!=-1) {std::cout<<n[last]<<" was removed"<<std::endl;last--;}
  else std::cout << "Queue Underflow" << std::endl;
}

void Queue::display(){
  if(last==-1)  {std::cout << "Queue is empty" << std::endl;return;}
  for(int i=0;i<=last;i++)
    std::cout << n[i] << "\t";
  std::cout << std::endl;
}

int main(){
  Queue q;
  q.enqueue(5);
  q.enqueue(7);
  q.enqueue(69);
  q.enqueue(1);
  q.display();
  q.enqueue(4);
  q.display();
  q.enqueue(10);
  q.dequeue();
  q.dequeue();
  q.dequeue();
  q.display();
  q.dequeue();
  q.dequeue();
  q.dequeue();
  q.display();
}