#include <iostream>
#define MAX 100
class Stacks {
private:
    int s[MAX];
    int n;
public:
    Stacks(){n=-1;}
    void push(int c){s[++n]=c;}
    void pop(){n--;}
    int top(){if(n!=-1) return s[n];}
    bool empty(){return n==-1;}
    void display(){std::cout <<"Queue: \t";for(int i=0;i<=n;i++)std::cout<<s[i]<<"\t";std::cout << std::endl;}
};

class Queue {
    private:
        Stacks main;
        Stacks temp;
        int n;
    public:
    Queue(){n=-1;}
    void enqueue(int x){
        main.push(x);n++;
    }
    void dequeue(){
        if(n==1){main.pop();return;}
        while(!main.empty()){temp.push(main.top());main.pop();}
        temp.pop();
        while(!temp.empty()){main.push(temp.top());temp.pop();}
    }
    void display(){
        if(!main.empty())
            main.display();
    }
};

int main(){
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.dequeue();q.dequeue();q.dequeue();q.dequeue();q.enqueue(5);
    q.display();
}