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
    std::cout<<"\n1:Push n\t2:Pop\t3:Peek\t4:Display"<<std::endl;
	while(1){
		int ip,x;
		std::cin>>ip;
		switch(ip){
			case 1:
                std::cin >> x;
                n.push(x);
                break;
            case 2:
                n.pop();
                break;
            case 3:
                n.peek();
                break;
            case 4:
                n.display();
                break;
            default:
                return 0;
		}
	}
}
