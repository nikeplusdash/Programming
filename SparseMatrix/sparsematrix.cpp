#include<iostream>
#define MAX 100

class SparseMat {
    private:
    int r;
    int c;
    int v;
    public:
    void init(int,int,SparseMat a[]);
    void transpose(SparseMat a[]);
    void display(SparseMat a[]);
};

void SparseMat::init(int m,int n,SparseMat a[MAX]){
    int num,k=0;
    a[k].r = m;
    a[k].c = n;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++){
            std::cin >> num;
            if(num!=0){
                k++;
                a[k].r=i;
                a[k].c=j;
                a[k].v=num;
            }
        }
    a[0].v=k;
}

void SparseMat::transpose(SparseMat a[MAX]){
    SparseMat *b = new SparseMat[MAX];
    int k = 0;
    b[k].r = a[k].c;
    b[k].c = a[k].r;
    b[k].v = a[k].v;
    k++;
    for(int i=0;i<b[0].r;i++)
        for(int j=1;j<=b[0].v;j++)
            if(i==a[j].c){
                b[k].r=a[j].c;
                b[k].c=a[j].r;
                b[k].v=a[j].v;
                k++;
            }
    b->display(b);
}

void SparseMat::display(SparseMat a[MAX]){
    std::cout<<std::endl;
    for(int i=1;i<=a[0].v;i++)
        std::cout << "(" << a[i].r << "," << a[i].c <<"):" << a[i].v << std::endl;
    std::cout<<std::endl;
}

int main(){
    SparseMat *s = new SparseMat[MAX];
    s->init(3,6,s);
    s->display(s);
    s->transpose(s);
}