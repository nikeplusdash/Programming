#include<iostream>
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

void Dijkstra(const Graph &G,int start)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> Q;
    int dist[G.V+1],parent[G.V+1],visited[G.V+1],vertices[G.V],k=1,org = start;
    for(int &i:vertices) {i = k++;dist[i] = 0;parent[i] = 0;visited[i] = 0;}
    Q.push(pair<int,int>(start,0));
    while(!Q.empty())
    {
        start = Q.top().first;Q.pop();
        visited[start] = 1;
        for(const pair<int,int> &i:G.E[start])
        {
            if(!visited[i.first] && i.second+dist[start] < dist[i.first] || dist[i.first] == 0)
            {
                dist[i.first] = i.second+dist[start];
                parent[i.first] = start;
            }
            else continue;
            Q.push(i);
        }
    }
    cout << "Shortest Distance from " << org << ":\n";
    for(int &i: vertices)
    {
        if(i != org)
        {
            int j = i;
            cout << "Vertex <" << i << ">:: ";
            cout << "Distance: " << dist[i] << " ";
            cout << "Path: [ " << j << " <- ";
            while(parent[j]) {cout << parent[j];if(parent[j]==org) cout << ""; else cout << " <- ";j = parent[j];}
            cout << "]" << endl;
        }
    }
    cout << endl;
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
            Dijkstra(G,x);
            break;
            default:
            return 0;
        }
    }
}