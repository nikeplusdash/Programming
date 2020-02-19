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

void Dijkstra(const Graph &G,int start)
{
    queue<int> Q;
    int dist[G.V+1],parent[G.V+1],visited[G.V+1],vertices[G.V],k=1,org = start;
    for(int &i:vertices) {i = k++;dist[i] = 0;parent[i] = 0;visited[i] = 0;}
    Q.push(start);
    // for(pair<int,int> i:G.E[start]) {dist[i.first] = 0;}
    while(!Q.empty())
    {
        start = Q.front();Q.pop();
        visited[start] = 1;
        for(const pair<int,int> &i:G.E[start])
        {
            if(!visited[i.first] && dist[i.first] == 0)
            {
                dist[i.first] = i.second;
                parent[i.first] = start;
                Q.push(i.first);
            }
            else if(!visited[i.first] && i.second+dist[start] > dist[i.first])
            {
                dist[i.first] = i.second;
                parent[i.first] = start;
                Q.push(i.first);
            }
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
            cout << "Path: [ ";
            while(parent[j]) {cout << parent[j] << " ";j = parent[j];}
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