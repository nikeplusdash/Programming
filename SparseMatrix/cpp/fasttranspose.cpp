#include<stdlib.h>
#include<iostream>
#define MAX 100

class SM {
    private:
    int r;
    int c;
    int v;
    public:
    void init(int m,int n,SM a[]);
    SM* transpose(SM a[]);
    SM* fasttranspose(SM a[]);
    SM* addition(SM a[],SM b[]);
    void display(SM a[]);
};

void SM::init(int m,int n,SM a[]){
    int k = 0;
    a[k].c=n;
    a[k].r=m;
    std::cout << "Enter value: " << std::endl;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++){
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
}

SM* SM::transpose(SM a[]){
    SM *b = new SM[MAX];
    int k =0;
    b[k].c=a[k].r;
    b[k].r=a[k].c;
    b[k].v=a[k].v;
    for(int i=0;i<a[0].c;i++){
        for(int j=1;j<=a[0].v;j++){
            if(i==a[j].c){
                k++;
                b[k].r = a[j].c;
                b[k].c = a[j].r;
                b[k].v = a[j].v;
            }
        }
    }
    b->display(b);
    return b;
}

SM* SM::fasttranspose(SM a[]){
    SM* b = new SM[MAX];
    int k=0;
    int col_start[a[0].c];
    int start_pos[a[0].c];
    b[k].c=a[k].r;
    b[k].r=a[k].c;
    b[k].v=a[k].v;
    for(int i=0;i<a[0].c;i++){
        col_start[i]=0;
        start_pos[i]=0;
    }
    for(int i=1;i<=a[0].v;i++){
        col_start[a[i].c]++;
    }
    start_pos[0]=1;
    for(int i=1;i<a[0].c;i++){
        start_pos[i]=start_pos[i-1]+col_start[i-1];
    }
    for(int i=1;i<=a[0].v;i++){
        int start = start_pos[a[i].c]++;
        b[start].c=a[i].r;
        b[start].r=a[i].c;
        b[start].v=a[i].v;
    }
    b->display(b);
    return b;
}

SM* SM::addition(SM a[],SM b[]){
    SM* c = new SM[MAX];
    int k=0,i=1,j=1;
    c[k].r=a[k].r;c[k].c=a[k].c;c[0].v=0;
    while(i<=a[0].v&&j<=b[0].v){
        if(a[i].r>b[j].r){
            k++;
            c[k].r=b[j].r;
            c[k].c=b[j].c;
            c[k].v=b[j].v;
            c[0].v++;
            j++;
        }
        else if(a[i].r<b[j].r){
            k++;
            c[k].r=a[i].r;
            c[k].c=a[i].c;
            c[k].v=a[i].v;
            c[0].v++;
            i++;
        }
        else if(a[i].c<b[j].c){
            k++;
            c[k].r=a[i].r;
            c[k].c=a[i].c;
            c[k].v=a[i].v;
            c[0].v++;
            i++;
        }
        else if(a[i].c>b[j].c){
            k++;
            c[k].r=b[j].r;
            c[k].c=b[j].c;
            c[k].v=b[j].v;
            c[0].v++;
            j++;
        }
        else {
            k++;
            c[k].r=a[i].r;
            c[k].c=a[i].c;
            c[k].v=b[j].v+a[i].v;
            c[0].v++;
            i++;
            j++;
        }
    }
    while(i<=a[0].v){
        k++;
        c[k].r=a[i].r;
        c[k].c=a[i].c;
        c[k].v=a[i].v;
        c[0].v++;
        i++;
    }
    while (j<=b[0].v)
    {
        k++;
        c[k].r=b[j].r;
        c[k].c=b[j].c;
        c[k].v=b[j].v;
        c[0].v++;
        j++;
    }
    c->display(c);
    return c;
}

void SM::display(SM a[]){
    std::cout << "\nr\tc\tv" << std::endl;
    std::cout << "---\t---\t---" << std::endl;
    std::cout << a[0].r <<"\t"<<a[0].c<<"\t"<<a[0].v<<std::endl;
    std::cout << "---\t---\t---" << std::endl;
    for(int i=1;i<=a[0].v;i++){
        std::cout << a[i].r <<"\t"<<a[i].c<<"\t"<<a[i].v<<std::endl;
    }
    
}

int main(){
    SM *a = new SM[MAX];
    SM *b = new SM[MAX];
    SM *c = new SM[MAX];
    int m,n;
    std::cout << "Enter elem for sparse mat & size: "<< std::endl;
    std::cin >> m >> n;
    a->init(m,n,a);
    a->display(a);
    std::cout << "Enter elem for sparse mat & size: "<< std::endl;
    std::cin >> m >> n;
    b->init(m,n,b);
    b->display(b);
    c = c->addition(a,b);
    // b = a->fasttranspose(a);
    //b->display(b);
}

    // while(i<=a[0].v&&j<=b[0].v){
    //     if(a[i].r<b[j].r){
    //         k++;
    //         c[k].r=a[i].r;
    //         c[k].c=a[i].c;
    //         c[k].v=a[i].v;
    //         i++;
    //     }
    //     else if(a[i].r>b[j].r){
    //         k++;
    //         c[k].r=a[i].r;
    //         c[k].c=a[i].c;
    //         c[k].v=a[i].v;
    //         i++;
    //     }
    // }
