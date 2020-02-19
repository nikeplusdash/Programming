#include<iostream>
#include "../Lab4/Graphsneverendinginator.cpp"
#include<bits/stdc++.h>
using namespace std;

int TopoSort(Graph* G){
    int **Matrix = G->AdjMatrix;
    int n=G->n,inDegree[n+1],reached[n+1],i=0;
    for(int &i:inDegree) i=0;
    for(int &i:reached) i=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            inDegree[i] += Matrix[j][i];
    Queue<int> S;
    int order[n+1],l=0;
    for(int i=1;i<=n;i++)
    {
        if(!inDegree[i]) S.Enqueue(i);
        while (!S.Empty())
        {
            int k = S.Dequeue();order[++l] = k;
            reached[k] = 1;
            for(int j=1;j<=n;j++)
            {   
                if(reached[j]) continue;
                if(Matrix[k][j] != 0) inDegree[j]--;
                if(!inDegree[j]) {S.Enqueue(j);reached[j]=1;}
            }
        }
    }
    for(int i=1;i<n+1;i++) cout << order[i] << " ";
    cout << endl;
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
    G->AdjMatrixViewer();
    TopoSort(G);
}