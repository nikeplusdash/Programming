#include "./Graphsneverendinginator.cpp"

int main() {
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
    std::cout << "\n1:View AdjMatrix\n2:View AdjList\n3:DFS using Matrix\n4:DFS using List\n5:BFS using Matrix\n6:BFS using List\n7:Mother Vertex\n8:Transpose\n9:Connected\n10:Path between x & y\n11:Cycles\n\n";
    while(true) {
        std::cin >> y;
        switch (y)
        {
        case 1:
            G->AdjMatrixViewer();
            break;
        case 2:
            G->GraphViewnator();
            break;
        case 3:
            std::cout << "Vertex: ";
            std::cin >> x;
            G->DFSusingMatrix(x);
            break;
        case 4:
            std::cout << "Vertex: ";
            std::cin >> x;
            G->DFS(x);
            break;
        case 5:
            std::cout << "Vertex: ";
            std::cin >> x;
            G->BFSusingMatrix(x);
            break;
        case 6:
            std::cout << "Vertex: ";
            std::cin >> x;
            G->BFS(x);
            break;
        case 7:
            G->MotherVertex();
            break;
        case 8:
            G = Transpose(G);
            std::cout << "Matrix Transpose: [S U C C E S S]" << std::endl;
            break;
        case 9:
            G->isConnected();
            break;
        case 10:
            std::cin >> x >> y;
            G->isPath(x,y);
            break;
        case 11:
            G->hasCycle();
            break;
        default:
            return 0;;
        }
    }
}