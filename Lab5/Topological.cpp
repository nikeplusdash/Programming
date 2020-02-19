#include<iostream>
#include "../Lab4/Graphsneverendinginator.cpp"
#include<bits/stdc++.h>
using namespace std;

int TopoSort(Graph* G){
    int **Matrix = G->AdjMatrix;
    int n=G->n,inDegree[n+1],visited[n+1],i=0;
    for(int &i:inDegree) i=0;
    for(int &i:visited) i=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            inDegree[i] += Matrix[j][i];
    Stacks<int> S,TS;
    for(int i=1;i<=n;i++)
    {
        if(!inDegree[i]&&!visited[i]) S.Push(i);
        visited[i]=1;
        while (!S.Empty())
        {
            int k = S.Pop();
            TS.Push(k);
            for(int j=n;j>0;j--)
            {
                if(Matrix[k][j]) inDegree[j]--;
                if(!inDegree[j]&&!visited[j]) {S.Push(j);visited[j]=1;}
            }
        }
    }
    TS.Display();
}

int main(){
    Graph* G;
    int x,y,m;
    goback:
    std::cout << "1:Enter Adjacency Matrix for a Graph\n2:Enter Adjacency List for a graph\n";
    std::cin >> y;
    std::cout << "Vertices: ";
    std::cin >> m;
    if(y == 1) {
        int** matrix = GraphinatorMatrix(m);
        G = Graphinator(matrix,m);
    }
    else if(y == 2) {
        G = Graphinator(m);
    }
    else {
        goto goback;
    }
    G->GraphViewnator();
    G->AdjMatrixViewer();
    TopoSort(G);
    return 0;
}