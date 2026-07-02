#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    vector<vector<int>>adj;
    public:
    Graph(int v)
    {
        V = v;
        adj.resize(V);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }


    void printGraph()
    {
        for(int i = 0; i < V; i++)
            {
                cout<<i<<"->";

                for(int node : adj[i])
                cout<<node<<" ";

                cout<<endl;
            }


    }
};

int main()
{
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);

    g.printGraph();
    return 0;
}
