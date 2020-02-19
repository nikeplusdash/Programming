#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    list<pair<int,int>> *E;
    public:
    Graph(){}
    Graph(int x)
    {
        V = x;
        E = new list<pair<int,int>>[V+1];
    }
    void AddEdge(int u,int v,bool isBi)
    {
        E[u].push_back(pair(v,-1));
        if(isBi) E[v].push_back(pair(u,-1));
    }
    void DeleteEdge(int u,int v,bool isBi)
    {
        E[u].remove(pair(v,-1));
        if(isBi) E[v].remove(pair(u,-1));
    }
    void AddCostEdge(int u,int v,int cost,bool isBi)
    {
        E[u].push_back(pair(v,cost));
        if(isBi) E[v].push_back(pair(u,cost));
    }
    void DeleteCostEdge(int u,int v,bool isBi)
    {
        for(pair<int,int> &i:E[u]) if(v == i.first) i.second = 0;
        E[u].remove(pair(v,0));
        if(isBi)
        {
            for(pair<int,int> &i:E[v]) if(v == i.first) i.second = 0;
            E[v].remove(pair(u,0));
        }
    }
    void Display()
    {
        cout << "Adjacency List:" << endl;
        for(int i=1;i<V+1;i++)
        {
            for(pair<int,int> j:E[i])
            {
                cout << j.first << " ";
            }
            cout << endl;
        }
    }
    void DisplayCost()
    {
        cout << "Adjacency List with cost:" << endl;
        for(int i=1;i<V+1;i++)
        {
            for(pair<int,int> j:E[i])
            {
                cout << j.first << " --<" << j.second << ">-- ";
            }
            cout << endl;
        }
    }
    void BFS(int start,int *visited) {
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
    }
};