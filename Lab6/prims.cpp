#include <bits/stdc++.h>

using namespace std;

#define max 999

int v,vis[100][100], a[100][100],e,s,d,w;
int x,y,b=0;
int sum[100] = {0};
int selected[100] = {0};

bool all()
{
    int sum=0;
    for(int i=0; i<v; i++)
    {
        sum+=selected[i];
    }
    
    if (sum==v)
        return true;
    else
        return false;
}

int get_min()
{
    int min = max;
    for(int i=0; i<v; i++)
    {
        
        if(selected[i]==1 || b==0)
        {
            for(int j=0; j<v; j++)
            {
                if((a[i][j] < min) && vis[i][j]==0)
                {
                    min = a[i][j];
                    x = i; y = j;
                }
            } 
        }
    }
    b++;
    vis[x][y] = 1;
    vis[y][x] = 1;
    return min;
    
    
}

void prims()
{
    int total_cost = 0;
    while(!all())
    {
        int dis = get_min();
        cout<<x<<"<--->"<<y<<" == "<<dis<<endl;
        total_cost+=dis;
        selected[x]=1;
        selected[y]=1;
    }
    
    cout<<total_cost;
}

int main()
{
    cout<<"Enter number of vertices: \n";
    cin>>v;
    cout<<"Enter number of edges\n";
	cin>>e;
	for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            a[i][j] = max;
            vis[i][j] = 0;
        }
        
    }

    
	for(int i=0;i<e;i++)
	{
		cout<<"Enter the source\n";
		cin>>s;
		cout<<"Enter the destination\n";
		cin>>d;
        cout<<"Enter weight: \n";
        cin>>w;
		a[s][d]=w;
        a[d][s]=w;
	}
    cout<<endl;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
    
    
    prims();
}