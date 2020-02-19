#include<iostream>
using namespace std;
class Heap {
public:
    int a[50];
    int n;
    Heap(){n=0;};
    void Insert(int x){
        int i=++n;
        while(i!=1&&x>a[i/2]) {a[i]=a[i/2];i/=2;}
        a[i]=x;
    }
    void Display(){for(int i=1;i<=n;i++) cout<<a[i]<<" "; cout<<endl;}
    void Delete(){
        swap(a[1],a[n]);
        n--;
        int i=1,j;
        while(1){
            if(2*i>n) break;
            else if(2*i<=n&2*i+1>n) j=2*i;
            else j = a[2*i]>a[2*i+1]?2*i:2*i+1;
            if(a[j]>a[i]) swap(a[j],a[i]);
            i=j;
        }
    }
    void sort(){
        int i=n;
        while(n!=1) Delete();
        n=i;
    }
};

int main(){
    Heap h;
    h.Insert(33);h.Insert(35);h.Insert(10);h.Insert(15);h.Insert(11);
    h.Insert(1010);
    h.Display();
    //h.Delete();
    h.sort();
    h.Display();
}
