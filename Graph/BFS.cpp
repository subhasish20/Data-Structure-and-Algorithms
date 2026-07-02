#include<bits/stdc++.h>
using namespace std;

class Graph
{
  public :
  int V;
  vector<vector<int>>adj;
  Graph(int v)
  {
      V = v;
      adj.resize(V);
  }

  void addEdge(int u, int v)
  {
      adj[u].push_back(v);
      adj[v].push_back(u); //for undirected Graph
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
  void BFS(int start)
  {
      vector<bool> visited(V, false);
      queue<int> q;

      visited[start] = true;
      q.push(start);

      while (!q.empty())
      {
          int current = q.front();
          q.pop();

          cout << current << " ";

          for (int neighbor : adj[current])
          {
              if (!visited[neighbor])
              {
                  visited[neighbor] = true;
                  q.push(neighbor);
              }
          }
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
    cout<<"The BFS of this graph is ";
    g.BFS(0);
    cout<<endl;
}
