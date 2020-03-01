#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
//m resources n processes
class PCB
{
    int m,n;
    int* available; //m
    int** max; // n*m
    int** alloc; // n*m
    int** need; // n*m
    int* finish; // n
    queue<int> safestate;
    public:
    PCB(){}
    PCB(int x,int y)
    {
        n=x;m=y;
        available = new int[m];
        finish = new int[n];
        max = new int*[n];
        alloc = new int*[n];
        need = new int*[n];
        for(int i=0;i<n;i++)
        {
            max[i] = new int[m];
            alloc[i] = new int[m];
            need[i] = new int[m];
        }
    }
    void init()
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>alloc[i][j];
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>max[i][j];
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                need[i][j] = max[i][j]-alloc[i][j];
        for(int j=0;j<m;j++)
            cin>>available[j];
        for(int i=0;i<n;i++)
            finish[i]=0;
    }
    void printer(string s,int padding)
    {
        // if(padding<4+6*m) for(int i=0;i<padding;i++) {cout << " ";}
        // else padding=0;
        cout << s;
        for(int i=0;i<2*m-s.length()+1;i++) cout << " ";
        cout << "|";
    }
    void spaceprinter(string s){
        cout << s << "___|_";
        for(int j=0;j<m;j++)
        {
            cout << "__";
        }
        cout << "|_";
        for(int j=0;j<m;j++)
        {
            cout << "__";
        }
        cout << "|_";
        for(int j=0;j<m;j++)
        {
            cout << "__";
        }
        cout << "|\n";
    }
    void printState()
    {
        int spaces = 9+6*m;
        cout << " ";
        for(int i=0;i<spaces;i++) cout << "_";
        cout << "\n";
        cout << "|id |";
        string printarray[] = {"alloc","max","need"};
        for(auto i:printarray) printer(i,0);
        cout <<"\n";
        spaceprinter("|");
        for(int i=0;i<n;i++)
        {
            cout << "|p" << i+1 << " | ";
            for(int j=0;j<m;j++)
            {
                cout <<  alloc[i][j] << " ";
            }
            cout << "| ";
            for(int j=0;j<m;j++)
            {
                cout <<  max[i][j] << " ";
            }
            cout << "| ";
            for(int j=0;j<m;j++)
            {
                cout <<  need[i][j] << " ";
            }
            cout << "|\n";
        }
        // cout << "|";
        // for(int i=0;i<spaces;i++) cout << "_";
        // cout << "|\n\n";
        spaceprinter("|");
        cout << endl;
        cout << "Available: [";
        for(int j=0;j<m;j++) cout <<  available[j] << " ";
        cout << "]\n\n";
    }
    void bankers()
    {
        printState();
        while(safestate.size() != n)
        {
            int i,j;
            for(i=0;i<n;i++){
                for(j=0;!finish[i]&&need[i][j]<=available[j]&&j<m;j++);
                if(j==m) break;
            }
            if(i==n&&j!=m) {cout << "No one is fucking safe" << endl;return;}
            for(int j=0;j<m;j++)
            {
                available[j]+=alloc[i][j];
                alloc[i][j]=0;
            }
            finish[i]=1;
            safestate.push(i);
        }
        cout << "SafeState: [";
        for(int i=0;i<n;i++){
            int j=safestate.front();safestate.pop();
            cout << "P" << j << " ";
        }
        cout << "]\n";
    }
};

int main()
{
    int i,j;
    FILE* fp;
    fp=freopen("output.txt","a+",stdout);
    cin >> i >> j;
    PCB block(i,j);
    block.init();
    block.bankers();
    fclose(fp);
}