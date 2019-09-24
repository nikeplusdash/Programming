#include <iostream>
#define MAX 10

class q {
    private:
    int a[MAX];
    int front;
    int rear;
    public:
    q(){front=-1;rear=-1;}
    void enqueue(int);
    void dequeue();
    int top();
    void display();
};

void q::enqueue(int x){
    if(front==-1)   front++;
    else if(rear==MAX-1&&front!=0) rear=-1;
    else if(rear==MAX-1&&front==0) {std::cout << "Queue Overflow" << std::endl;return;}
    else if(rear==front-1)   {std::cout << "Queue Overflow" << std::endl;return;}
    std::cout << x << " was pushed to Queue" << std::endl;
    a[++rear]=x;
}

void q::dequeue(){
    if(rear==-1) {std::cout << "Queue Underflow" << std::endl;return;}
    if(front==rear) {front=-1;rear=-1;return;}
    if(front==MAX-1)    front=-1;
    front++;
}

int q::top(){
    return a[front];
}

void q::display(){
    if(rear==-1){
        std::cout << "Queue Empty" << std::endl;
    }
    else if(front<rear){
        for(int i=rear;i>=front;i--)    std::cout << a[i] << "\t";
        std::cout << std::endl;
    }
    else if(front>rear) {
        for(int i=rear;i>=0;i--)    std::cout << a[i] << "\t";
        for(int i=MAX-1;i>=front;i--)    std::cout << a[i] << "\t";
        std::cout << std::endl;
    }
    else if(front!=-1)    std::cout << a[front] << std::endl;
    return;
}

int main(){
    q q;
    for(int i=0;i<2;i++)   q.enqueue(i);
    for(int i=0;i<4;i++)   q.dequeue();
    for(int i=0;i<1;i++)   q.enqueue(i);
    q.display();
}