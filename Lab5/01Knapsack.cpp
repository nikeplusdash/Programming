#include<iostream>

template<class T>
int setPivot(T a[],int l,int r,bool isA,int track[]) {
    T ele = a[l];int x = r;
    if(isA)
        for(int i = r;i > l;i--)
            if(a[i] > ele) {std::swap(a[i],a[x]);std::swap(track[i],track[x--]);}
    if(!isA)
        for(int i = r;i > l;i--)
            if(a[i] < ele) {std::swap(a[i],a[x]);std::swap(track[i],track[x--]);}
    std::swap(a[l],a[x]);
    std::swap(track[l],track[x]);
    return x;
}

template<class T>
void QuickSort(T a[],int l,int r,bool isA,int track[]) {
    if(l >= r) {return;}
    int pivot = setPivot(a,l,r,isA,track);
    QuickSort(a,l,pivot-1,isA,track);
    QuickSort(a,pivot+1,r,isA,track);
}

// Greedy on Profit
void GoP(int p[],int w[],int n,int c)
{
    int x[n],track[n];
    int profit=0,k=0;
    for(int &i:x) i = 0;
    for(int &i:track) i=k++;
    QuickSort(p,0,n-1,0,track);
    for(int i=0;i<n;i++) {
        if(c >= w[track[i]]) {c-=w[track[i]];x[track[i]]=1;profit+=p[i];}
    }
    std::cout << "Sack(Profit = " << profit << "): \n";
    for(int i=0;i<n;i++)
        if(x[i]) std::cout << "[ " << w[track[i]] << " - " << p[i] << " ] x " << x[i] << std::endl;
    return;
}

// Greedy on Weight
void GoW(int p[],int w[],int n,int c)
{
    int x[n],track[n];
    int profit=0,k=0;
    for(int &i:x) i = 0;
    for(int &i:track) i=k++;
    QuickSort(w,0,n-1,0,track);
    for(int i=0;i<n;i++) {
        if(c >= w[i]) {c-=w[i];x[track[i]]=1;profit+=p[track[i]];}
    }
    std::cout << "Sack(Profit = " << profit << "): \n";
    for(int i=0;i<n;i++)
        if(x[i]) std::cout << "[ " << w[i] << " - " << p[track[i]] << " ] x " << x[i] << std::endl;
    return;
}

// Greedy on Profit Density
void GoPD(int p[],int w[],int n,int c)
{
    int x[n],track[n];
    float pd[n];
    int profit=0;
    int k=0,j=0;
    for(int &i:x) i = 0;
    for(int &i:track) i=k++;
    for(auto &i:pd) i=(float)p[j]/w[j++];
    QuickSort(pd,0,n-1,0,track);
    for(int i=0;i<n;i++) {
        if(c >= w[track[i]]) {c-=w[track[i]];x[track[i]]=1;profit+=p[track[i]];}
    }
    std::cout << "Sack(Profit = " << profit << "): \n";
    for(int i=0;i<n;i++)
        if(x[i]) std::cout << "[ " << w[track[i]] << " - " << p[track[i]] << " ] x " << x[i] << std::endl;
    return;
}

//Fractional Knapsack
void FracKS(int p[],int w[],int n,int c)
{
    int track[n];
    float pd[n],x[n],profit=0;
    int k=0,j=0;
    for(float &i:x) i = 0;
    for(int &i:track) i=k++;
    for(auto &i:pd) i=(float)p[j]/w[j++];
    QuickSort(pd,0,n-1,0,track);
    while(c)
    {
        for(int i=0;i<n;i++)
            if(c >= w[track[i]]) {c-=w[track[i]];x[track[i]]=1;profit+=p[track[i]];}
            else {
                float store = (float)c/w[track[i]];
                profit += store*p[track[i]];
                c = 0;
                x[track[i]] = store;
            }
    }
    std::cout << "Sack(Profit = " << profit << "): \n";
    for(int i=0;i<n;i++)
        if(x[i]>0) std::cout << "[ " << w[track[i]] << " - " << p[track[i]] << " ] x " << x[i] << std::endl;
    return;
}

int main()
{
    int n,c;
    std::cin >> n >> c;
    int w[n];
    int p[n];
    int track[n];
    int k=0;
    for(int &i:track) i=k++;
    for(int &i:w) std::cin >> i;
    for(int &i:p) std::cin >> i;
    GoPD(p,w,n,c);
    return 0;
}