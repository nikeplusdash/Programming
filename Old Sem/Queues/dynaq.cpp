#include<iostream>
#include<stdlib.h>

class dynaq {
    private:
    int *a;
    int n;
    public:
    dynaq(){n=-1;a=(int*) calloc(n,sizeof(int));}
    void enqueue(int x){a=(int*)realloc(a,++n*sizeof(int));a[n]=x;}
    void dequeue(){if(n!=-1){int x = *a;a=a+1;n--;std::cout << x << " was popped out." << std::endl;} else std::cout << "Queue Underflow" << std::endl;}
    void display(){std::cout << "Queue: \t";for(int i=0;i<=n;i++)std::cout << a[i] << "\t";std::cout<<std::endl;}
    void poprear(){if(n!=-1) {int x = a[n];n--;std::cout << x << " was popped out." << std::endl;}else std::cout << "Queue Underflow" << std::endl;}
};

int main(){
    dynaq q;
    q.enqueue(4);q.enqueue(5);q.enqueue(5);q.enqueue(9);
    q.display();
    q.dequeue();
    q.poprear();
    q.display();
    q.dequeue();
    q.poprear();
    q.display();
    q.dequeue();
    q.poprear();
}