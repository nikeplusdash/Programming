#include<iostream>
#include<vector>
#include<unistd.h>
#define size 2
#define d << " - " <<
using namespace std;

class answer
{
    public:
    int min,max;
    answer(int i){min = INT16_MAX;max = INT16_MIN;}
};

void compare(vector<int> &a,answer &b,int l,int r)
{
    int n = r-l+1;
    if(n == 1) {
        if(b.max < a[l]) b.max = a[l];
        if(b.min > a[l]) b.min = a[l];
    }
    else if(n == 2) {
        int max = a[l]>a[r]?a[l]:a[r];
        int min = a[l]<a[r]?a[l]:a[r];
        if(b.max < max) b.max = max;
        if(b.min > min) b.min = min;
        return;
    }
}
void minmax(vector<int> &a,answer &b,int l,int r)
{
    int n = r-l+1;
    if(n <= size) compare(a,b,l,r);
    else {
        int N = (r+l-1)/2;
        // cout << "Entry: " << N d l d r << endl; 
        minmax(a,b,l,N);
        minmax(a,b,N+1,r);
        // cout << "Exit: " << N d l d r << endl; 
        
    }
    // sleep(1);
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n+1,0);
    answer b(0);
    for(int i=1;i<=n;i++) cin >> a[i];
    minmax(a,b,1,n);
    cout << "Min: " << b.min << "\nMax: " << b.max << endl;
}