#include <iostream>
#include <math.h>
#include <bits\stdc++.h>
#define MAX 100
class Stacks {
    public:
    int a[MAX];
    int n;
    public:
    Stacks(){n=-1;}
    void push(int x){if(!full())a[++n]=x;}
    void pop(){if(!empty())--n;}
    int top(){if(!empty())return a[n];else return 100;}
    bool empty(){return n==-1;}
    bool full(){return n==MAX-1;}
    void display(){for(int i=0;i<=n;i++)std::cout << a[i] << " ";std::cout << std::endl;}
};
class Hanoi
{
    int n;
    int moves;
    Stacks src;
    Stacks aux;
    Stacks final;
    public: 
    Hanoi(int x)
    {
        moves = 1;
        n = 3;
        while (x > 0)
        {
            src.push(x);
            x--;
        }
    }
    void Display() {
        std::cout << "A: "; src.display();
        std::cout << "B: "; aux.display();
        std::cout << "C: "; final.display();
        std::cout << std::endl;
        }
    void Iterate()
    {
        if (moves % n == 1)
        {
            if (!src.empty() && src.top() < final.top())
            {
                Display();
                final.push(src.top());
                src.pop();
            }
            else
            {
                Display();
                src.push(final.top());
                final.pop();
            }
        }
        else if (moves % n == 2)
        {
            if (!src.empty() && src.top() < aux.top())
            {
                Display();
                aux.push(src.top());
                src.pop();
            }
            else
            {
                Display();
                src.push(aux.top());
                aux.pop();
            }
        }
        else if (moves % n == 0)
        {
            if (!aux.empty() && aux.top() < final.top())
            {
                Display();
                final.push(aux.top());
                aux.pop();
            }
            else
            {
                Display();
                aux.push(final.top());
                final.pop();
            }
        }
        moves++;
    }
};
int main()
{
    int x = 3;
    int move = pow(2,x)-1;
    Hanoi *h = new Hanoi(x);
    while(move >= 0) {h->Iterate();;move--;}
}