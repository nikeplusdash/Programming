#include <iostream>
#include <stdlib.h>

class dynaqueue
{
private:
  int *n;
  int last;

public:
  dynaqueue()
  {
    last = -1;
    n = (int *)malloc(sizeof(int) * last);
  }
  void enqueue(int);
  void dequeue();
  void display();
  bool newq();
};

void dynaqueue::enqueue(int a)
{
  n = (int *)realloc(n,++last*sizeof(int));
  for (int i = last; i > 0; i--)
    n[i] = n[i - 1];
  n[0] = a;
}

void dynaqueue::dequeue()
{
  if(last==-1) {std::cout << "Queue Underflow" << std::endl;return;}
  int x = n[last];
  n = (int *)realloc(n,--last*sizeof(int));
  std::cout << x << " has been removed" << std::endl;
}

void dynaqueue::display()
{
  for (int i = 0; i <= last; i++)
    std::cout << n[i] << "\t";
  std::cout << std::endl;
}

int main()
{
  dynaqueue dq;
  dq.display();
  dq.dequeue();
  dq.enqueue(5);
  dq.enqueue(6);
  dq.enqueue(7);
  dq.enqueue(5);
  dq.enqueue(6);
  dq.enqueue(7);
  dq.enqueue(5);
  dq.enqueue(6);
  dq.enqueue(7);
  dq.dequeue();
  dq.display();
}