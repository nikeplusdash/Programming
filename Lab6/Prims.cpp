#include<iostream>
#include<unistd.h>
#include<bits/stdc++.h>
using namespace std;

class Graph {
    public:
    int V;
    list<pair<int,int>> *E;
    Graph(){}
    Graph(int x)
    {
        V = x;
        E = new list<pair<int,int>>[V+1];
    }
    void AddEdge(int u,int v,int cost,bool isBi)
    {
        E[u].push_back(pair<int,int>(v,cost));
        if(isBi) E[v].push_back(pair<int,int>(u,cost));
    }
    void DeleteEdge(int u,int v,bool isBi)
    {
        for(pair<int,int> &i:E[u]) if(v == i.first) i.second = 0;
        E[u].remove(pair<int,int>(v,0));
        if(isBi)
        {
            for(pair<int,int> &i:E[v]) if(v == i.first) i.second = 0;
            E[v].remove(pair<int,int>(u,0));
        }
    }
    void Display()
    {
        cout << "Adjacency List (cost):" << endl;
        for(int i=1;i<V+1;i++)
        {
            cout << "Vertex <" << i << ">: [ ";
            for(pair<int,int> j:E[i])
            {
                cout << j.first << "";
                if(j.second != 0) cout << "(" << j.second << ") ";
                else cout << "---";
            }
            cout << "]" << endl;
        }
    }
    int* BFS(int start,int *visited) {
        queue<int> Q;Q.push(start);
        visited[start]=1;
        std::cout << "BFS from <V" << start << ">: " << std::endl;
        while(!Q.empty()) {
            int i = Q.front();Q.pop();
            for(pair<int,int> j:E[i])
            {
                cout << j.first << " ";
                if(!visited[j.first]) {
                    Q.push(j.first);
                    visited[j.first] = 1;
                }
            }
        }
        cout << endl;
        return visited;
    }
};

class Compare
{
    public:
    int operator() (pair<int,int> i,pair<int,int> j)
    {
        return i.second > j.second;
    }
};

bool all(int visited[],int n)
{
    int i=1;
    for(;i<=n&&(visited[i]==1);i++);
    return i==(n+1);
}

void Prims(const Graph &G)
{
    list<int> L;
    int visited[G.V+1],parent[G.V+1],cost[G.V+1],vertices[G.V],k=1,start=1;
    Graph T(G.V);
    for(int &i:visited) {i = 0;}
    L.push_back(start);
    while(!all(visited,G.V))
    {
        cout << " Hi";
        int mins,minv,minc=INT16_MAX;
        for(int i:L)
        {
            for(auto &j:G.E[i])
            {

                cout<<endl;
                if(!visited[j.first]) {L.push_back(minv);visited[j.first]=1;}
                if(minc>j.second)
                {
                    minc = j.second;
                    minv = j.first;
                    mins = i;
                }
            }
            for(int k=1;k<=G.V;k++) cout << visited[k] << " ";
            sleep(2);
        }
        G.DeleteEdge(mins,minv,1);
        T.AddEdge(mins,minv,minc,0);
    }
    T.Display();
}

int main()
{
    int x,y,z;
    bool isBi;
    cout << "Vertices: ";
    cin >> x;
    Graph G(x);
    cout << "1:Add Edge 2:Delete Edge 3:Display 4:Dijkstra's" << endl;
    while(true)
    {
        cin >> y;
        switch(y)
        {
            case 1: 
            cin >> x >> y >> z >> isBi;
            G.AddEdge(x,y,z,isBi);
            break;
            case 2: 
            cin >> x >> y >> z >> isBi;
            G.DeleteEdge(x,y,isBi);
            break;
            case 3: 
            G.Display();
            break;
            case 4: 
            cin >> x;
            Prims(G);
            break;
            default:
            return 0;
        }
    }
}