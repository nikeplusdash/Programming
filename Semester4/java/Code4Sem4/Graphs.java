import java.util.LinkedList;
import java.util.Iterator;

public class Graphs {
    private int V;
    private LinkedList<Integer> E[];
    private int M[][];
    Graphs(){}
    /**
     * Constructor to initialize the objecgt of Graph
     * 
     * @param V Vertices for the given graph
     */
    Graphs(int V)
    {
        this.V = V;
        this.E = new LinkedList[V+1];
        this.M = new int[V+1][];
        for(int i = 1;i <= V;i++) {E[i] = new LinkedList<>();M[i] = new int[V+1];}
    }
    /**
     * Adding and edge to the graph
     * 
     * @param src from edge
     * @param dest to edge
     * @param isBi is bidirectional or not
     */
    public void AddEdge(int src,int dest,boolean isBi)
    {
        E[src].add(dest);
        M[src][dest] = 1;
        if(isBi) {E[dest].add(src);M[dest][src]=1;}
    }
    /**
     * Displays the adjacency matrix and the adjacency list
     */
    public void Display()
    {
        System.out.println("\nMatrix:");
        for(int i=1;i<=V;i++) {for(int j=1;j<=V;j++) System.out.print(M[i][j]+" ");System.out.print("\n");}
        System.out.println("\nList:");
        for(int i=1;i<=V;i++) {for(int j:E[i]) System.out.print(j+" ");System.out.print("\n");}
        System.out.print("\n");
    }

    public void BFS(int v)
    {
        System.out.print("BFS from "+v+": ");
        int[] visited = new int[V+1];
        LinkedList<Integer> Q = new LinkedList<>();
        visited[v] = 1;
        Q.add(v);
        while(Q.size() != 0)
        {
            int start = Q.pollFirst();
            System.out.print(start+" ");
            Iterator<Integer> i = E[start].iterator();
            while(i.hasNext())
            {   
                int j = i.next();
                if(visited[j] != 1)
                {
                    visited[j] = 1;
                    Q.add(j);
                }
            }
        }
        System.out.print("\n");
    }

    public void DFS(int v)
    {
        System.out.print("DFS from "+v+": ");
        int[] visited = new int[V+1];
        LinkedList<Integer> S = new LinkedList<>();
        visited[v] = 1;
        S.add(v);
        while(S.size() != 0)
        {
            int start = S.pollLast();
            System.out.print(start+" ");
            Iterator<Integer> i = E[start].iterator();
            while(i.hasNext())
            {   
                int j = i.next();
                if(visited[j] != 1)
                {
                    visited[j] = 1;
                    S.add(j);
                }
            }
        }
        System.out.print("\n");
    }

    public static void main(){
        Graphs G = new Graphs(6);
        G.AddEdge(1, 2, false);
        G.AddEdge(2, 3, true);
        G.AddEdge(2, 4, false);
        G.AddEdge(4, 5, true);
        G.AddEdge(4, 6, false);
        G.AddEdge(5, 6, false);
        G.Display();
        G.DFS(1);
    }
}