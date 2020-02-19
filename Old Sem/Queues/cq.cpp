#include<iostream>
#define MAX 5
class circularq {
    private:
    int a[MAX];
    int front;
    int rear;
    public:
    circularq(){front=-1;rear=-1;}
    void enqueue(int);
    void dequeue();
    void display();
};

void circularq::enqueue(int k){
    if(rear==MAX-1&&front==0||rear==front-1) {std::cout << "Queue Overflow" << std::endl;return;}
    std::cout << k << " was added to queue" << std::endl;
    if(rear==MAX-1) rear=-1;
    if(front==-1)   front=0;
    a[++rear]=k;
}

void circularq::dequeue(){
    if(front==-1) {std::cout << "Queue Underflow" << std::endl;return;}
    std::cout << a[front] << " was removed" << std::endl;
    if(front==rear) {front=-1;rear=-1;return;}
    if(front==MAX-1) front=-1;
    front++;
}

void circularq::display(){
    //std::cout << front << " " << rear << std::endl;
    std::cout << "Queue:\t";
    if(front==-1)   return;
    else if(front<=rear)
        for(int i=front;i<=rear;i++)
            std::cout << a[i] << "\t" ;
    else {
        for(int i=front;i<MAX;i++)
            std::cout << a[i] << "\t"  ;
        for(int i=0;i<=rear;i++)
            std::cout << a[i] << "\t"  ;
    }
    std::cout << std::endl;
}

int main(){
    circularq q;
    q.enqueue(5);
    q.enqueue(7);
    q.enqueue(69);
    q.dequeue();
    q.dequeue();
    q.enqueue(1);
    q.display();
    q.enqueue(4);
    q.display();
    q.enqueue(10);
    q.display();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.display();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.enqueue(0);
    q.display();
}