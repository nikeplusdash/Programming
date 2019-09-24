#include<iostream>
#include<time.h>
class SM {
    private:
    int r;
    int c;
    int v;
    public:
    SM* init(int,int,SM*);
    SM* transpose(SM*);
    SM* ftranspose(SM*);
    void display(SM*);
};

SM* SM::init(int m,int n,SM* a){
    int k=0;
    a[k].r=m;
    a[k].c=n;
    std::cout << "Enter values:" << std::endl;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++) {
            int x;
            std::cin >> x;
            if(x!=0){
                k++;
                a[k].r=i;
                a[k].c=j;
                a[k].v=x;
            }
        }
    a[0].v=k;
    return a;
}

SM* SM::transpose(SM* a){
    int k=0;
    SM* b = new SM[a[0].v+1];
    b[k].r=a[k].c;
    b[k].c=a[k].r;
    b[k].v=a[k].v;
    for(int i=0;i<a[0].c;i++){
        for(int j=1;j<=a[0].v;j++){
            if(i==a[j].c){
                k++;
                b[k].r=a[j].c;
                b[k].c=a[j].r;
                b[k].v=a[j].v;
            }
        }
    }
    //b->display(b);
    return b;
}

SM* SM::ftranspose(SM* a){
    int k=0;
    SM* b = new SM[a[0].v+1];
    int* col_posn = new int[a[k].c];
    int* start_posn = new int[a[k].c];
    b[k].r=a[k].c;
    b[k].c=a[k].r;
    b[k].v=a[k].v;
    for(int i=0;i<a[0].c;i++){
        col_posn[i]=0;
        start_posn[i]=0;
    }
    for(int i=1;i<=a[0].v;i++){
        col_posn[a[i].c]++;
    }
    start_posn[0]=1;
    for(int i=1;i<a[0].c;i++){
        start_posn[i]=start_posn[i-1]+col_posn[i-1];
    }
    for(int i=1;i<=a[0].v;i++){
        int start = start_posn[a[i].c]++;
        b[start].c = a[i].r;
        b[start].r = a[i].c;
        b[start].v = a[i].v;
    }
    //b->display(b);
    return b;
}

void SM::display(SM* x){
    std::cout << "\n  --Rows-- --Columns-- --Value--"<< std::endl;
    std::cout <<"\t"<< x[0].r << "\t" << x[0].c << "\t" << x[0].v << std::endl;
    std::cout << "  -------- ----------- ---------"<< std::endl;
    for(int i=1;i<=x[0].v;i++)
        std::cout <<"\t"<< x[i].r << "\t" << x[i].c << "\t" << x[i].v << std::endl;
}

int main(){
    clock_t t;
    int m,n;
    std::cout << "Enter rows and columns: " << std::endl;
    std::cin >> m >> n ;
    SM* a = new SM[m*n];
    SM* b;
    a->init(m,n,a);
    a->display(a);
    b = a->ftranspose(a);
    b->display(b);
}
