#include<iostream>
#include<bits\stdc++.h>
using namespace std;

class Graphs {
    private:
    int V;
    list<int> *E;
    int **M;
    public:
    Graphs(){}
    Graphs(int v)
    {
        V = v;
        E = new list<int>[V+1];
        M = new int*[V+1];
        for(int i=1;i<=V;i++) M[i] = new int[V+1];
        for(int i=0;i<V+1;i++)
            for(int j=0;j<V+1;j++)
                M[i][j] = 0;
    }
    void AddEdge(int u,int v,bool b)
    {
        M[u][v] = 1;
        E[u].push_back(v);
        if(b) {M[v][u] = 1;E[v].push_back(u);}
    }
    void Display()
    {
        cout << "Matrix: " << endl;
        for(int i=1;i<V+1;i++)
        {
            for(int j=1;j<V+1;j++)  cout << M[i][j] << " ";
            cout << endl;
        }
        cout << "List: " << endl;
        for(int i=1;i<V+1;i++)
        {
            cout << "Head";
            for(auto j: E[i])  cout << " <- " << j;
            cout << endl;
        }
    }
    void BFS(int v)
    {
        queue<int> Q;
        int visited[V+1] = {0};
        visited[v] = 1;
        Q.push(v);
        cout << "BFS: "; 
        while(!Q.empty())
        {
            int start = Q.front();Q.pop();
            cout << start << " ";
            for(list<int>::iterator i = E[start].begin();i != E[start].end();i++) //for(auto i:E[start]) also works
            {
                if(visited[*i]) continue;
                visited[*i] = 1;
                Q.push(*i);
            }
        }
        cout << endl;
    }
    void DFS(int v)
    {
        stack<int> S;
        int visited[V+1] = {0};
        visited[v] = 1;
        S.push(v);
        cout << "DFS: "; 
        while(!S.empty())
        {
            int start = S.top();S.pop();
            cout << start << " ";
            for(list<int>::iterator i = E[start].begin();i != E[start].end();i++) //for(auto i:E[start]) also works
            {
                if(visited[*i]) continue;
                visited[*i] = 1;
                S.push(*i);
            }
        }
        cout << endl;
    }
    void DFS2(int v)
    {
        int *visited = new int[V+1];
        for(int i=0;i<V+1;i++) visited[i] = 0;
        DFS2(E,visited,v);
    }
    void DFS2(list<int> e[],int* visited,int start)
    {
        std::cout << start << " ";
        visited[start] = 1;
        for(auto i:e[start]){
            if(!visited[i]) DFS2(e,visited,i);
        }
    }
};

int main()
{
    Graphs G(6);
    G.AddEdge(1, 2, false);
    G.AddEdge(2, 3, true);
    G.AddEdge(2, 4, false);
    G.AddEdge(4, 5, true);
    G.AddEdge(4, 6, false);
    G.AddEdge(5, 6, false);
    G.Display();
    G.DFS2(2);
}