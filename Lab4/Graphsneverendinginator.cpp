#include<iostream>
#include "../Lab2/LinkedList.cpp"
#include "../Lab2/Stack.cpp"
#include "../Lab2/Queue.cpp"

class Graph {
    public:
    int n;
    int *VerticeList;
    LinkedLists<int> **VerticeMap;
    int **AdjMatrix;
    Graph(){}
    Graph(int m){
        n = m;
        VerticeList = new int[m];
        VerticeMap = new LinkedLists<int>*[m+1];
        AdjMatrix = new int*[m+1];
        for(int i=1;i<=m;i++) {
            AdjMatrix[i] = new int[m+1];
            VerticeMap[i] = new LinkedLists<int>;
        }
    }
    void GraphViewnator(){  
        for(int i=1;i<=n;i++)
            VerticeMap[i]->Display(i);
        std::cout << std::endl;
    }
    void AdjMatrixViewer() {
        std::cout << "Adjacency Matrix:\n\n   ";
        for(int i=1;i<=n;i++)
            std::cout << i << " ";
        std::cout << std::endl;
        std::cout <<  "   " ;
        for(int i=1;i<=n;i++)
            std::cout << "- ";
        std::cout << std::endl;
        for(int i=1;i<=n;i++) {
            std::cout << i << "| ";
            for(int j=1;j<=n;j++)
                std::cout << AdjMatrix[i][j] << " ";
            std::cout << std::endl;
        }
        std::cout<<std::endl;
    }
    // BFS Recursive
    void BFS(Queue<LinkedLists<int>*> Q,int* visited) {
        LinkedLists<int>* start;
        if(Q.Empty()) return;
        start = Q.Dequeue();
        std::cout << " > " << start->data << "\n";
        while(start) {
            if(!visited[start->data]) {LinkedLists<int>* curr = VerticeMap[start->data]->getHead();Q.Enqueue(curr);visited[curr->data]=1;}
            start = start->next;
        }
        BFS(Q,visited);
    }
    void BFS(int begin) {
        Queue<LinkedLists<int>*> Q;
        std::cout << "BFS from <V" << begin << ">: " << std::endl;
        int* visited = new int[(n)+1];
        for(int i=0;i<=n;i++) visited[i] = 0;
        Q.Enqueue(VerticeMap[begin]->getHead());
        visited[begin] = 1;
        BFS(Q,visited);
        std::cout<<std::endl;
    }
    // Recursive DFS
    void DFS(LinkedLists<int>* start,int* visited) {
        if(!start) return;
        // visited[start->data] = 1;
        while(start) {
            if(!visited[start->data]) {visited[start->data]=1;std::cout << " > " << start->data << "\n";DFS(VerticeMap[start->data]->getHead(),visited);}
            start = start->next;
        }
    }
    void DFS(int begin) {
        LinkedLists<int>* start = VerticeMap[begin]->getHead();
        std::cout << "DFS from <V" << begin << ">: " << std::endl;
        int* visited = new int[n+1];
        for(int i=0;i<=n;i++) visited[i] = 0;
        visited[begin] = 1;
        DFS(start,visited);
        std::cout<<std::endl;
    }
    // DFS Iterative
    void DFSusingMatrix(int start) {
        int* visited = new int[n+1];
        for(int i=0;i<=n;i++) visited[i] = 0;
        Stacks<int> S;S.Push(start);visited[start]=1;
        std::cout << "DFS from <V" << start << ">: " << std::endl;
        while(!S.Empty()) {
            int i = S.Pop();
            if(visited[i]) std::cout << " > " << i << "\n";
            for(int j=1;j<=n;j++) {
                if(AdjMatrix[i][j] && !visited[j]) {
                    S.Push(j);
                    visited[j] = 1;
                }
            }
        }
        std::cout<<std::endl;
    }
    // BFS Iterative
    void BFSusingMatrix(int start) {
        int* visited = new int[n+1];
        for(int i=0;i<=n;i++) visited[i] = 0;
        Queue<int> Q;Q.Enqueue(start);
        visited[start]=1;
        std::cout << "BFS from <V" << start << ">: " << std::endl;
        while(!Q.Empty()) {
            int i = Q.Dequeue();
            if(visited[i]) std::cout << " > " << i << "\n";
            for(int j=1;j<=n;j++) {
                if(AdjMatrix[i][j] && !visited[j]) {
                    Q.Enqueue(j);
                    visited[j] = 1;
                }
            }
        }
        std::cout<<std::endl;
    }
    // MotherVertex
    void MotherVertex(){
        Queue<int> vertice;
        for(int begin=1;begin<=n;begin++) {
            LinkedLists<int>* start = VerticeMap[begin]->getHead();
            int* visited = new int[n+1];
            for(int i=0;i<=n;i++) visited[i] = 0;
            visited[begin] = 1;
            DFSForMother(start,visited);
            int i;
            for(i=0;visited[i+1]==1&&i<n;i++);
            if(i == n)  vertice.Enqueue(begin);
        }
        while(!vertice.Empty()) {int i = vertice.Dequeue(); std::cout << i << " is a mother vertex" << std::endl;}
        std::cout << std::endl;
    }
    void DFSForMother(LinkedLists<int>* start,int* visited) {
        if(start) visited[start->data] = 1;
        while(start) {
            if(!visited[start->data]) DFSForMother(VerticeMap[start->data]->getHead(),visited);
            start = start->next;
        }
    }
    bool isConnected(){
        int count = 0,isConnected = 0;
        for(int begin=1;begin<=n;begin++) {
            LinkedLists<int>* start = VerticeMap[begin]->getHead();
            int* visited = new int[n+1];
            for(int i=0;i<=n;i++) visited[i] = 0;
            visited[begin] = 1;
            DFSForMother(start,visited);
            int i;
            for(i=0;visited[i+1]==1&&i<n;i++);
            if(i == n)  {count++;isConnected=1;}
        }
        if(count == n) {std::cout << "Graph is strongly connected\n" << std::endl;}
        if(isConnected) {std::cout << "Graph is connected\n" << std::endl;return 1;}
        else {std::cout << "Graph is not connected\n" << std::endl;return 0;}
    }
    bool isPath(int start,int end){
        int* visited = new int[n+1];
        for(int i=0;i<=n;i++) visited[i] = 0;
        Stacks<int> S;S.Push(start);visited[start]=1;
        while(!S.Empty()) {
            int i = S.Pop();
            for(int j=1;j<=n;j++) {
                if(AdjMatrix[i][j] && !visited[j]) {
                    S.Push(j);
                    visited[j] = 1;
                    if(j == end) {std::cout << "Path exists\n" << std::endl;return 1;}
                }
            }
        }
        std::cout << "Path doesn't exists\n" << std::endl;return 0;
    }
    void hasCycle() {
        int* visited = new int[n+1];
        for(int i=0;i<=n;i++) visited[i] = 0;
        for(int begin=1;begin<=n;begin++){
            DFSForMother(VerticeMap[begin]->getHead(),visited);
            std::cout << (visited[begin] ? "There is a cycle at " : "There's no cycle at ") << begin << std::endl;
        }
        std::cout << std::endl;   
    }
};
//Creates Adjacency Matrix
int** GraphinatorMatrix(int m) {
    int x;
    int** AdjMatrix;
    AdjMatrix = new int*[m+1];
    for(int i=1;i<=m;i++) {
        AdjMatrix[i] = new int[m+1];
        std::cout << "Vertices connected to " << i;
        for(int j=1;j<=m;j++) {
            std::cin >> x;
            AdjMatrix[i][j] = x;
        }
        std::cout << std::endl;
    }
    return AdjMatrix;
}
// Creates Adjacency List & Matrix
Graph* Graphinator(int m) {
    int x;
    Graph* G = new Graph(m);
    for(int i=1;i<=m;i++) {
        std::cin >> x;
        G->VerticeList[i] = x;
    }
    for(int i=1;i<=m;i++) {
        std::cout << "Vertices connected to " << G->VerticeList[i];
        while(true) {
            std::cin >> x;
            if(x == -1) break;
            G->VerticeMap[i]->Insert(x);
            G->AdjMatrix[G->VerticeList[i]][x] = 1;
        }
        std::cout << std::endl;
    }
    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++) 
            if(G->AdjMatrix[i][j] != 1) G->AdjMatrix[i][j] = 0;
    std::cout << std::endl;
    return G;
}
// Converts Adjacency Matrix to List
Graph* Graphinator(int** AdjMatrix,int m) {
    Graph* G = new Graph(m);
    for(int i=1;i<=m;i++) {
        G->VerticeList[i] = i;
    }
    for(int i=1;i<=m;i++) {
        for(int j=1;j<=m;j++) {
            G->AdjMatrix[i][j] = AdjMatrix[i][j];
            if(AdjMatrix[i][j] == 1)
                G->VerticeMap[i]->Insert(j);
        }
    }
    return G;
}
Graph* Transpose(Graph* G){
    Graph* newG;
    for(int i=1;i<=G->n;i++)
        for(int j=i+1;j<=G->n;j++)
            std::swap(G->AdjMatrix[j][i],G->AdjMatrix[i][j]);
    newG = Graphinator(G->AdjMatrix,G->n);
    // delete G->VerticeList;
    // for(int i=0;i<=G->n;i++){
    //     G->VerticeMap[i]->Clear();
    // }
    // delete[] G->VerticeMap;
    return newG;
}