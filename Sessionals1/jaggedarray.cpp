#include <iostream>
#include<stdlib.h>
class JaggedArray {
    private:
        int** a;
        int* len;
        int n;
    public:
        void init(int x,int size[]){
            n = x;
            a = (int**) calloc(n,sizeof(int*));
            len = (int*) calloc(n,sizeof(int));
            std::cout << "Insert Values: " << std::endl;
            for(int i=0;i<n;i++)    len[i]=size[i];
            for(int i=0;i<n;i++){
                a[i] = (int*) calloc(len[i],sizeof(int));
                for(int j=0;j<len[i];j++)   std::cin >> a[i][j];
            }
        }
        void display(){
            std::cout << "\n-----Ragged Array-----\n";
            for(int i=0;i<n;i++){
                std::cout << i+1 << "] ";
                for(int j=0;j<len[i];j++)
                    std::cout << a[i][j] << "  ";
                std::cout << "\n";
            }
        }
        void exchange(){
            int d=0,*x;
            for(int i=0;i<n;i++) d+=len[i];
            x=(int*) calloc(d,sizeof(int));
            d=-1;
            for(int i=0;i<n;i++)
                for(int j=0;j<len[i];j++)
                    x[++d]=a[i][j];
            a = (int**) realloc(a,1*sizeof(int*));
            a[0] = x;len[0]=d+1;n=1;
        }
};

int main(){
    int n,*a;
    JaggedArray Arr;
    std::cout << "Insert Size" << std::endl;
    std::cin >> n;
    a = new int[n];
    std::cout << "Insert Jagged Size" << std::endl;
    for(int i=0;i<n;i++)    std::cin >> a[i];
    Arr.init(n,a);
    Arr.display();
    Arr.exchange();
    Arr.display();
}