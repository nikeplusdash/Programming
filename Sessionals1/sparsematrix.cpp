#include<iostream>
#define MAX 100

class SparseMatrix {
    private:
    int r;
    int c;
    int v;
    public:
    static SparseMatrix* init(int m,int n){
        SparseMatrix* a = new SparseMatrix[m*n];
        int k = 0;
        a[k].r=m;
        a[k].c=n;
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
        return a;
    }
    SparseMatrix* transpose (SparseMatrix a[]){
        SparseMatrix* b = new SparseMatrix[a[0].v+1];
        int k=0;
        b[k].r=a[k].c;
        b[k].c=a[k].r;
        b[k].v=a[k].v;
        for(int i=0;i<a[0].c;i++)
            for(int j=1;j<=a[0].v;j++)
                if(i==a[j].c){
                    k++;
                    b[k].r=a[j].c;
                    b[k].c=a[j].r;
                    b[k].v=a[j].v;
                }
        return b;
    }
    SparseMatrix* ftranspose (SparseMatrix a[]){
        SparseMatrix* b = new SparseMatrix[a[0].v+1];
        int* colp = new int[a[0].c];
        int* startp = new int [a[0].c];
        for(int i=1;i<=a[0].v;i++)  colp[a[i].c]++;
        startp[0]=1;
        for(int i=1;i<a[0].c;i++)   startp[i]=startp[i-1]+colp[i-1];
        for(int i=1;i<=a[0].v;i++){
            int start = startp[a[i].c]++;
            b[start].r=a[i].c;
            b[start].c=a[i].r;
            b[start].v=a[i].v;
        }
        return b;
    }
    SparseMatrix* addition(SparseMatrix a[],SparseMatrix b[]){
        SparseMatrix* c = new SparseMatrix[a[0].v+b[0].v];
        int i=1,j=1,k=0;
        if(a[0].r!=b[0].r||a[0].c!=b[0].c) return NULL;
        c[k].r=a[k].r;
        c[k].c=b[k].c;
        c[k].v=0;
        while(i<=a[0].v&&j<=b[0].v){
            if(a[i].r>b[j].r){
                k++;
                c[k].r=b[j].r;
                c[k].c=b[j].c;
                c[k].v=b[j].v;
                j++;
                c[0].v++;
            }
            else if(a[i].r<b[j].r){
                k++;
                c[k].r=a[i].r;
                c[k].c=a[i].c;
                c[k].v=a[i].v;
                i++;
                c[0].v++;
            }
            else if(a[i].c>b[j].c){
                k++;
                c[k].r=b[j].r;
                c[k].c=b[j].c;
                c[k].v=b[j].v;
                j++;
                c[0].v++;
            }
            else if(a[i].c<b[j].c){
                k++;
                c[k].r=a[i].r;
                c[k].c=a[i].c;
                c[k].v=a[i].v;
                i++;
                c[0].v++;
            }
            else {
                k++;
                c[k].r=a[i].r;
                c[k].c=a[i].c;
                c[k].v=a[i].v+b[j].v;
                i++;j++;
                c[0].v++;
            }
        }
        while(i<=a[0].v){
            k++;
            c[k].r=a[i].r;
            c[k].c=a[i].c;
            c[k].v=a[i].v;
            i++;
            c[0].v++;
        }
        while(j<=b[0].v){
            k++;
            c[k].r=b[j].r;
            c[k].c=b[j].c;
            c[k].v=b[j].v;
            j++;
            c[0].v++;
        }
        return c;
    }
    SparseMatrix* multiplication(SparseMatrix a[],SparseMatrix b[]){
        if(a[0].r!=b[0].r)  return NULL;
    }
    void display(SparseMatrix a[]){
        std::cout << "\n-Rows-- --Columns-- --Values--" << std::endl;
        std::cout << "---\t---\t---" << std::endl;
        std::cout << a[0].r <<"\t"<<a[0].c<<"\t"<<a[0].v<<std::endl;
        std::cout << "---\t---\t---" << std::endl;
        for(int i=1;i<=a[0].v;i++){
            std::cout << a[i].r <<"\t"<<a[i].c<<"\t"<<a[i].v<<std::endl;
        }
    }
};

int main(){
    SparseMatrix* a = new SparseMatrix[MAX];
    SparseMatrix* b = new SparseMatrix[MAX];
    SparseMatrix* c = new SparseMatrix[MAX];
    int m,n;
    std::cout << "Enter elem for sparse mat & size: "<< std::endl;
    std::cin >> m >> n;
    a = SparseMatrix::init(m,n);
    a->display(a);
    std::cout << "Enter elem for sparse mat & size: "<< std::endl;
    std::cin >> m >> n;
    b = SparseMatrix::init(m,n);
    b->display(b);
    c = c->addition(a,b);
    // b = a->fasttranspose(a);
    c->display(c);
}