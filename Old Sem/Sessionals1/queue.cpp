#include<iostream>
#include<stdlib.h>
#define MAX 4

class queue {
    private:
    int a[MAX];
    int front,rear;
    public:
    queue(){front=-1;rear=-1;}
    void enqueue(int x){
        if(front==-1) front++;
        if(rear==MAX-1) return;
        a[++rear]=x;
    }
    void dequeue(){
        if(front==rear&&rear==-1) return;
        if(front>rear) return;
        front++;
    }
    void display(){
        if(rear==-1) return;
        for(int i=front;i<=rear;i++)    std::cout << a[i] << " ";
        std::cout << std::endl;
    }   
};

class cq {
    private:
    int a[MAX];
    int front,rear;
    public:
    cq(){front=-1;rear=-1;}
    void enqueue(int x){
        if(front==0&&rear==MAX-1||rear==front-1) return;
        if(front==-1)   front++;
        if(rear==MAX-1) rear=-1;
        a[++rear]=x;
    }
    void dequeue(){
        if(front==rear){front=-1;rear=-1;return;}
        if(front==MAX-1)    front=-1;
        front++;    
    }
    void display(){
        if(front==-1)   return;
        std::cout << "Queue:\t";
        if(front<=rear)
            for(int i=front;i<=rear;i++)    std::cout << a[i] << " ";
        else {
            for(int i=front;i<MAX;i++)  std::cout << a[i] << " ";
            for(int i=0;i<=rear;i++)    std::cout << a[i] << " ";  
        }
        std::cout << std::endl;
    }
};

class kQueue {
    private:
    int *a;
    int *front,*rear;
    int *fixed;
    int size,len,k;
    public:
    kQueue(int max,int n){
        len=max;k=n;size=max/n;
        a=(int*)calloc(len,sizeof(int));
        front=(int*)calloc(k,sizeof(int));
        rear=(int*)calloc(k,sizeof(int));
        fixed=(int*)calloc(k,sizeof(int));
        for(int i=0;i<k;i++){
            front[i]=size*i-1;
            rear[i]=size*i-1;
            fixed[i]=size*i-1;
        }
    }
    void enqueue(int x,int k){
        k--;
        if(rear[k]==fixed[k]+size) {std::cout << "Queue Overflow\n";return;}
        if(front[k]==fixed[k])    front[k]++;
        a[++rear[k]]=x;
    }
    void dequeue(int k){
        k--;
        if(front[k]==fixed[k]) {std::cout << "Queue Underflow\n";return;}
        if(front[k]==rear[k]){front[k]=rear[k]=fixed[k];return;}
        ++front[k];
    }
    void display(int k){
        k--;
        std::cout << "Queue:" << k+1 << "\t";
        for(int i=front[k];i<=rear[k];i++)  std::cout << a[i] << " ";
        std::cout << std::endl;
    }
    void display(){
        for(int i=0;i<k;i++){
            std::cout << "Queue " << i+1 << ":\t";
            if(front[i]==fixed[i])  {std::cout << "Empty\n";continue;}
            for(int j=front[i];j<=rear[i];j++)  std::cout << a[j] << " ";
            std::cout << std::endl;
        }
    }
};

class deque {
    private:
    int a[MAX];
    int front,rear;
    public:
    deque(){front=-1;rear=-1;}
    void append(int x){
        if(rear==MAX-1&&front==0||front==rear+1){std::cout << "Queue Overflow\n";return;}
        if(front==-1)   front++;
        if(rear==MAX-1) rear=-1;
        a[++rear]=x;
    }
    void prepend(int x){
        if(rear==MAX-1&&front==0||front==rear+1){std::cout << "Queue Overflow\n";return;}
        if(rear==-1)    rear=MAX-1;
        if(front==0||front==-1) front=MAX;
        a[--front]=x;
    }
    void delete_last(){
        if(front==-1)    {std::cout << "Queue Underflow\n";return;}
        if(front==rear) {front=-1;rear=-1;return;}
        if(rear==0) rear=MAX;
        rear--;
    }
    void delete_front(){
        if(rear==-1)    {std::cout << "Queue Underflow\n";return;}
        if(front==rear) {front=-1;rear=-1;return;}
        if(front==MAX-1) front=-1;
        front++;
    }
    void display(){
        if(front==-1)   return;
        std::cout << "Queue:\t";
        if(front<=rear)
            for(int i=front;i<=rear;i++)    std::cout << a[i] << " ";
        else {
            for(int i=front;i<MAX;i++)  std::cout << a[i] << " ";
            for(int i=0;i<=rear;i++)    std::cout << a[i] << " ";  
        }
        std::cout << std::endl;
    }
};

class priorityq {
    private:
    int a[MAX];
    int n;
    public:
    priorityq(){n=-1;}
    void insert(int x){if(n<MAX-1)a[++n]=x;}
    int getPriority(){
        int i=0;
        for(int j=0;j<=n;j++)
            if(a[j]>a[i])  i=j;
        return i;
    }
    int getElement(){
        if(!empty())    return a[getPriority()];
    }
    void removeElement(){
        if(empty()) return;
        int i=getPriority();
        while(i<n){a[i]=a[i+1];i++;}
        n--;
    }
    bool empty(){return n==-1;}
    void display(){
        if(n==-1) return;
        for(int i=0;i<=n;i++)    std::cout << a[i] << " ";
        std::cout << std::endl;
    }   
};

int main(){
    priorityq q;
    q.insert(0);
    q.insert(69);
    q.insert(4);
    q.insert(1);
    q.insert(7);
    q.display();
    q.removeElement();
    q.removeElement();q.removeElement();q.removeElement();
    q.insert(1);
    q.removeElement();
    q.display();

}